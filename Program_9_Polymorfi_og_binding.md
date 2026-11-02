# Program 9 · Polymorfi, binding og object slicing

[Oversigt](OOP_Laeringsforloeb.md) · [Forrige](Program_8_Arv_og_livscyklus.md) · [Næste: Operatorer](Program_10_Operatoroverloading.md)

## Hvad er binding?

Når koden kalder en funktion, skal sprogets regler afgøre, hvilken funktion kaldet betyder. Denne forbindelse kaldes binding.

Ved **statisk binding** afgøres valget ud fra information ved kompilering, blandt andet de statiske typer og de synlige funktioner. Ved **dynamisk binding** kan et virtuelt kald vælge implementation efter objektets dynamiske type ved kørsel. Dynamisk binding kaldes også late binding.

```cpp
Hund hund;
Dyr* p = &hund;
```

`p` har den statiske type `Dyr*`. Det objekt, den peger på, har den dynamiske type `Hund`. Begge oplysninger er vigtige. En optimerende compiler kan nogle gange udregne et virtuelt kald på forhånd, men det ændrer ikke programmets semantiske regler.

## Statisk polymorfi: function overloading

Overloading giver flere funktioner samme navn med forskellige parameterlister. Compileren vælger blandt de synlige kandidater ved at sammenligne argumenterne med parametrene.

```cpp
void vis(int tal);
void vis(double tal);
```

`vis(3)` passer direkte til `int`. `vis(3.5)` passer direkte til `double`. Funktionerne kan også være medlemsfunktioner. Returtypen alene er ikke tilstrækkelig til at overload en funktion:

```cpp
// Forkert som to overloads med samme parameterliste:
// int hent();
// double hent();
```

Templates er en anden vigtig form for statisk polymorfi, men her fokuserer vi på function overloading.

### Tvetydighed i overload resolution

Overload resolution handler om den bedste gyldige kandidat, ikke om hvilken funktion der står først. Se disse to funktioner:

```cpp
void bland(int, double);
void bland(double, int);
```

`bland(1, 1)` er tvetydigt. Den første kandidat passer bedst på første argument, den anden på andet argument. Ingen vinder samlet. Compileren giver en fejl; den vælger ikke tilfældigt.

Skriv eksempelvis `bland(1, 1.0)`, hvis den første overload er den ønskede. Et cast kan også gøre hensigten tydelig, men brug ikke casts til at skjule et uklart API. Overloads med standardargumenter eller mange implicitte konverteringer kan også blive tvetydige.

[05_overloading.cpp](examples/oop-advanced/05_overloading.cpp):

```cpp
#include <iostream>
void vis(int) { std::cout << "vis(int)\n"; }
void vis(double) { std::cout << "vis(double)\n"; }
void bland(int, double) { std::cout << "bland(int, double)\n"; }
void bland(double, int) { std::cout << "bland(double, int)\n"; }
int main() {
    vis(3);
    vis(3.5);
    // bland(1, 1); // Bevidst udeladt: tvetydigt, kan ikke kompilere.
    bland(1, 1.0);
    bland(1.0, 1);
}
```

De fire linjer i output viser henholdsvis `vis(int)`, `vis(double)`, `bland(int, double)` og `bland(double, int)`. Den tvetydige linje er kommenteret ud, så filen kan køres. Testpakken kontrollerer særskilt, at et tilsvarende tvetydigt kald faktisk bliver afvist.

## Dynamisk polymorfi og overriding

Basisklassen skal erklære funktionen `virtual`, når kald skal kunne afhænge af den afledte objekttype:

```cpp
virtual const char* lyd() const;
```

En derived-klasse kan override den med en passende signatur. Skriv `override`, så compileren kontrollerer hensigten:

```cpp
const char* lyd() const override;
```

Navn, parameterliste og relevante kvalifikationer som `const` skal passe. `lyd()` uden `const` overrider ikke `lyd() const`. `override` gør sådan en fejl synlig. Returtypen skal også opfylde reglerne; der findes særlige undtagelser for kovariante pointer- og referencereturtyper.

En ikke-virtuel funktion med samme navn i derived-klassen bliver normalt skjult eller en anden overload; det er ikke dynamisk overriding. Overload-valget og det virtuelle valg er to forskellige trin. Standardargumenter vælges også ud fra den statiske kontekst, så brug ikke forskellige standardargumenter til at skabe forskellige forventninger ved virtuelle kald.

## Base class pointer og reference

En basepointer eller basereference kan give fælles adgang til forskellige derived-objekter. Et virtuelt kald gennem denne adgang bruger det rigtige objekts override. En pointer kan være null, så den skal pege på et levende objekt, før du bruger den. I eksemplet ejer pointeren ikke hunden og skal ikke slettes.

[06_binding_slicing.cpp](examples/oop-advanced/06_binding_slicing.cpp):

```cpp
#include <iostream>
struct Dyr {
    virtual ~Dyr() = default;
    const char* kategori() const { return "Dyr"; } // Ikke virtual.
    virtual const char* lyd() const { return "Generisk lyd"; }
};
struct Hund : Dyr {
    const char* kategori() const { return "Hund"; } // Skjuler, overrider ikke.
    const char* lyd() const override { return "Vov"; }
};
void somVaerdi(Dyr d) { std::cout << "Vaerdi: " << d.lyd() << '\n'; }
void somReference(const Dyr& d) { std::cout << "Reference: " << d.lyd() << '\n'; }
int main() {
    Hund hund;
    Dyr* p = &hund; // Ikke-ejende pointer; hund lever længere end p bruges.
    std::cout << "Statisk: " << p->kategori() << '\n';
    std::cout << "Dynamisk: " << p->lyd() << '\n';
    somVaerdi(hund);       // Et nyt Dyr-objekt: Hund-delen skæres væk.
    somReference(hund);   // Samme Hund-objekt: polymorfien bevares.
}
```

Output:

```text
Statisk: Dyr
Dynamisk: Vov
Vaerdi: Generisk lyd
Reference: Vov
```

Læs første par som ét forsøg: `p->kategori()` er ikke virtuelt, så basens funktion vælges. `p->lyd()` er virtuelt, så Hund-implementationen vælges.

## Object slicing

Ved `somVaerdi(hund)` oprettes en selvstændig parameter af typen `Dyr`. Kun base-delen kopieres over. Den nye parameter er faktisk et Dyr-objekt. Hund-delen er skåret væk: **object slicing**.

Det betyder ikke, at den oprindelige hund ændrer type eller mister sine data. Slicing sker i den nye værdi. Derfor returnerer referencevarianten stadig `Vov`, når den senere henviser til den oprindelige hund.

Brug ofte `const Base&` til polymorf læsning, og `Base&` til ændringer. En `std::vector<Base>` gemmer Base-værdier og kan slice derived-værdier. Til en samling, der skal eje forskellige derived-objekter, er `std::vector<std::unique_ptr<Base>>` ofte en passende model.

## Pure virtual functions og abstrakte klasser

En ren virtuel funktion markeres med `= 0`:

```cpp
virtual double areal() const = 0;
```

En klasse med en ren virtuel final overrider er abstrakt og kan ikke oprettes direkte. En derived-klasse skal implementere de manglende rene virtuelle funktioner for selv at blive konkret.

En abstrakt klasse kan godt have data, constructors og almindelige funktionsimplementationer. Den er ikke nødvendigvis en “tom interface”. Hvis du erklærer en ren virtuel destructor, skal den stadig have en definition, fordi destruktionen af base-delen skal kunne udføres.

[07_abstrakte_klasser.cpp](examples/oop-advanced/07_abstrakte_klasser.cpp):

```cpp
#include <iostream>
#include <memory>
#include <vector>
class Figur {
public:
    virtual ~Figur() = default;
    virtual double areal() const = 0;
};
class Rektangel : public Figur {
    double bredde, hoejde;
public:
    Rektangel(double b, double h) : bredde(b), hoejde(h) {}
    double areal() const override { return bredde * hoejde; }
};
class Kvadrat : public Figur {
    double side;
public:
    explicit Kvadrat(double s) : side(s) {}
    double areal() const override { return side * side; }
};
int main() {
    std::vector<std::unique_ptr<Figur>> figurer;
    figurer.push_back(std::make_unique<Rektangel>(3, 4));
    figurer.push_back(std::make_unique<Kvadrat>(5));
    for (const auto& f : figurer) std::cout << f->areal() << '\n';
} // unique_ptr rydder op gennem en virtual destructor.
```

Output er `12` og `25`. Samme udtryk, `f->areal()`, får forskellige implementationer. De positive mål er faste undervisningsdata; eksemplet validerer ikke vilkårlige dimensioner.

Basens destructor er `virtual`, så sletning af derived-objekterne gennem en `Figur`-pointer kan udføre den fulde destruktion korrekt. `std::unique_ptr` overtager ejerskabet og sørger for at kalde sletningen. En smart pointer erstatter ikke behovet for en korrekt base-destructor i denne situation.

### En vigtig grænse under oprettelse og oprydning

Virtuelle kald under en base-constructor eller base-destructor bruger ikke et override fra en mere afledt del, som endnu ikke er oprettet eller allerede er afviklet. Undgå især at kalde en ren virtuel funktion indirekte fra sådan kode. Lad ikke en base-constructor være afhængig af, at hele derived-objektet allerede findes.

## Opgaver

1. Fjern `virtual` fra basens `lyd()` og `override` fra Hund. Hvad vælger `p->lyd()` nu?
2. Hvorfor er `const Dyr&` anderledes end `Dyr` som parameter?
3. Tilføj en klasse `Trekant` med arealet `grundlinje * hoejde / 2` til Figur-eksemplet.
4. Forklar, hvorfor `Figur f;` ikke kan kompileres.

<details><summary>Løsningsforslag</summary>

1. Basens `Generisk lyd`, fordi kaldet er ikke-virtuelt gennem en Dyr-pointer.
2. Referencen henviser til det eksisterende Hund-objekt. Værdiparameteren opretter en ny Base-værdi og slicer.
3. Arv offentligt fra Figur, gem to mål, og implementér `double areal() const override`. Brug fx `std::make_unique<Trekant>(4, 3)` og forvent 6.
4. Figur har en ren virtuel `areal()` og er derfor abstrakt.

</details>

## Videre læsning

Microsoft: [function overloading](https://learn.microsoft.com/en-us/cpp/cpp/function-overloading), [virtual functions](https://learn.microsoft.com/en-us/cpp/cpp/virtual-functions) og [abstract classes](https://learn.microsoft.com/en-us/cpp/cpp/abstract-classes-cpp).
