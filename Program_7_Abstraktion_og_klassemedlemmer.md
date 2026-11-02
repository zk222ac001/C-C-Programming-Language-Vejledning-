# Program 7 · Abstraktion og klassemedlemmer i C++

[Oversigt](OOP_Laeringsforloeb.md) · [Næste: Arv](Program_8_Arv_og_livscyklus.md) · [Interaktivt lab](interactive/oop-videre.html)

**Forudsætning:** Du har arbejdet med klasser, objekter og constructors i Program 6. Alle kørbare programmer i dette forløb bruger C++17. HTML-labbet skal downloades og åbnes i en browser; GitHubs filvisning kører ikke knapperne.

## Abstraktion: vælg det, din model skal kunne

En fysisk sensor har elektronik, strømforbrug, temperaturgrænser og mange andre egenskaber. Vores undervisningsprogram har kun brug for sensorens navn og måling. Vi laver derfor en mindre model: `Sensor`.

**Abstraktion** betyder, at vi udtrykker de relevante egenskaber og handlinger og skjuler de detaljer, brugeren af modellen ikke behøver. Den offentlige funktion `hent()` siger, hvad man kan få fra objektet. Den behøver ikke afsløre, om målingen kommer fra et felt, en fil eller et netværk.

**Indkapsling** handler om at samle data med de funktioner, der arbejder med dem, og styre adgangen. `private` kan understøtte abstraktionen ved at gøre intern repræsentation utilgængelig for almindelig kode udenfor klassen. Begreberne hænger sammen, men betyder ikke helt det samme. En klasse kan være en abstraktion uden at være en *abstrakt klasse* med rene virtuelle funktioner. Det sidste kommer i Program 9.

## Member data og member functions

Medlemsdata beskriver et objekts tilstand. Medlemsfunktioner beskriver de handlinger, objektet tilbyder. I `Sensor` er `maaling` data, mens `hent()` og `saet()` er funktioner.

```cpp
class Sensor {
private:
    double maaling = 0;
public:
    double hent() const { return maaling; }
    void saet(double v) { maaling = v; }
};
```

`hent()` læser, så den kan være `const`. `saet()` ændrer tilstanden. Hvis en virkelig sensor kun må acceptere bestemte værdier, er `saet()` et naturligt sted at kontrollere dem. At gøre data private validerer dog ikke automatisk noget; den kontrol skal vi selv skrive.

| Adgang | Hvem må bruge medlemmet direkte? | Hvad betyder det for `main()`? |
| --- | --- | --- |
| `public` | Almindelig kode, der har et passende objekt | Kan kalde `s.hent()` |
| `private` | Klassens egne medlemmer og erklærede friends | Kan ikke skrive `s.maaling = 99` |
| `protected` | Klassens medlemmer/friends og afledte klassers medlemmer efter adgangsreglerne | Stadig ikke offentlig adgang fra `main()` |

I en `class` er standardadgangen `private`. I en `struct` er den `public`. Begge kan have metoder, constructors og arv. Vi bruger ofte `struct` i små sporingsprogrammer, hvor alle felter bevidst er offentlige.

## Destructor: hvad sker der, når objektets liv slutter?

Constructoren gør objektet klar. Destructoren afslutter dets levetid og kan frigive de ressourcer, objektet ejer. For klassen `Sensor` hedder den `~Sensor()`.

```cpp
~Sensor() noexcept {
    // Frigiv eventuelle ejede ressourcer her.
}
```

En destructor har ingen returtype og ingen parametre. Et lokalt objekt destrueres normalt automatisk, når dets scope forlades. Objekter i samme scope destrueres i omvendt rækkefølge af deres færdige konstruktion. En rå pointer, der forlader scope, destruerer derimod ikke automatisk det heap-objekt, den peger på.

Undgå selv at kalde `s.~Sensor()` på et normalt lokalt objekt. Det kan efterlade et objekt, som programmet senere forsøger at bruge eller destruere igen. Lad automatisk levetid og ressourceejere som `std::unique_ptr` gøre arbejdet.

Ofte behøver du slet ikke skrive en destructor. Medlemmer som `std::string`, `std::vector` og `std::unique_ptr` rydder selv op. Det er en del af ideen bag **Rule of Zero**: lad velafprøvede typer eje ressourcerne. RAII bliver gennemgået i Program 11.

## Inline-funktioner

En funktion defineret inde i klassens krop er implicit `inline` i C++17. En funktion udenfor kan markeres sådan:

```cpp
inline int dobbelt(int x) { return x * 2; }
```

`inline` garanterer ikke, at kaldet bliver erstattet med funktionskoden, og det garanterer ikke et hurtigere program. Compileren træffer optimeringsbeslutningen. Den praktiske sproglige betydning er også, at en inline-definition kan stå i flere oversættelsesenheder, typisk fordi en header inkluderes i flere `.cpp`-filer. Definitionerne skal opfylde ODR-reglerne, blandt andet være ens på de krævede måder. En include guard løser ikke i sig selv konflikter mellem forskellige `.cpp`-filer.

Brug `inline` til definitioner, der hører hjemme i en header. Vælg ikke nøgleordet ud fra en antagelse om hastighed.

## Friend-funktioner

En friend-funktion er en funktion, som klassen giver adgang til sine private og beskyttede medlemmer. En fri friend-funktion bliver ikke en medlemsfunktion og får ikke en `this`-pointer.

```cpp
friend void rapport(const Sensor& s);
```

Vi kalder den `rapport(s)`, ikke `s.rapport()`. Den kan være relevant, når en operation arbejder naturligt med flere objekter, eller når vi implementerer en I/O-operator. Venskab er ikke automatisk gensidigt, arvet eller transitivt: hvis A giver B adgang, får alle B's venner ikke dermed adgang til A.

En normal offentlig læsefunktion er ofte tilstrækkelig. Giv kun friend-adgang til funktioner, der faktisk skal samarbejde tæt med klassens repræsentation.

## Static members: data for klassen

Et almindeligt medlem findes særskilt i hvert objekt. Et statisk datamedlem er fælles for klassen og er ikke et ekstra felt i hvert objekt.

```cpp
inline static int levende = 0;  // Definition i klassen, C++17.
static int antal() { return levende; }
```

`Sensor::antal()` kan kaldes uden et bestemt sensorobjekt. En statisk medlemsfunktion har ingen `this`-pointer og kan derfor ikke bare læse et bestemt objekts `maaling`. Den skal have et objekt som argument, hvis den har brug for objektdata.

`inline static` er C++17-formen. En ældre form er `static int levende;` i klassen og én definition, `int Sensor::levende = 0;`, i en `.cpp`-fil. Static betyder ikke automatisk trådsikker; flere samtidige skrivninger kræver synkronisering.

## References: et andet navn for samme objekt

En lvalue-reference erklæres med `&`:

```cpp
int tal = 10;
int& alias = tal;
alias = 20; // tal er nu 20.
```

Referencen skal bindes ved oprettelsen. Den kan ikke senere ombindes til et andet objekt. `alias = andetTal` tildeler værdien til det oprindelige objekt. En reference skal referere til et gyldigt objekt; den kan blive hængende, hvis objektet dør. Returnér derfor ikke en reference til en almindelig lokal variabel, som forlader scope ved returneringen.

| Parameter | Adfærd | Typisk formål |
| --- | --- | --- |
| `T x` | Modtager en værdi, ofte en kopi | En selvstændig lokal værdi |
| `T& x` | Henviser til originalen og kan ændre den | Bevidst ændring af et eksisterende objekt |
| `const T& x` | Henviser til et objekt og læser gennem en const-adgang | Læsning uden unødig kopiering |

`const T&` gør ikke nødvendigvis hele objektet uforanderligt gennem alle andre navne. I denne artikel bruger vi lvalue-referencer. Rvalue-referencer (`T&&`) og move-semantik er et senere emne.

## Samlet eksempel: målinger og antal levende objekter

[Hent 01_medlemmer.cpp](examples/oop-advanced/01_medlemmer.cpp).

```cpp
#include <iostream>
#include <string>
class Sensor {
    std::string navn;                // Hvert objekt har sit eget navn.
    double maaling;
    inline static int levende = 0;   // Fælles for klassen (C++17).
public:
    Sensor(std::string n, double m) : navn(n), maaling(m) { ++levende; }
    Sensor(const Sensor&) = delete;  // Hold tælleren enkel i denne demo.
    Sensor& operator=(const Sensor&) = delete;
    ~Sensor() noexcept { --levende; }
    double hent() const { return maaling; } // Implicit inline i C++17.
    void saet(double v) { maaling = v; }
    static int antal() { return levende; }
    friend void rapport(const Sensor& s);
};
void rapport(const Sensor& s) { // Fri funktion med eksplicit adgang.
    std::cout << s.navn << ": " << s.maaling << '\n';
}
int main() {
    std::cout << "Antal: " << Sensor::antal() << '\n';
    {
        Sensor a("A", 20), b("B", 25);
        Sensor& alias = a;
        alias.saet(21);
        rapport(a);
        rapport(b);
        std::cout << "Antal: " << Sensor::antal() << '\n';
    } // b og derefter a destrueres.
    std::cout << "Antal: " << Sensor::antal() << '\n';
}
```

Forventet output:

```text
Antal: 0
A: 21
B: 25
Antal: 2
Antal: 0
```

Aliaset ændrer kun A. Den fælles tæller er 2, mens begge objekter lever. Når scopet slutter, reducerer deres destructors tælleren til 0. Vi har deaktiveret kopiering i denne lille demo, så en implicit kopi ikke omgår tællerlogikken. Det er en afgrænsning af demonstrationen, ikke en generel regel om at alle klasser skal forbyde kopiering.

### Et selvstændigt referenceforsøg

[Hent 02_referencer.cpp](examples/oop-advanced/02_referencer.cpp).

```cpp
#include <iostream>
void kopi(int x) { x = 99; std::cout << "Lokal kopi: " << x << '\n'; }
void original(int& x) { x = 30; }
void laes(const int& x) { std::cout << "Laest: " << x << '\n'; }
inline int dobbelt(int x) { return x * 2; }
int main() {
    int a = 10, b = 20;
    int& r = a;
    r = b; // Skriver 20 i a; r bliver ved med at referere til a.
    b = 50;
    kopi(a);
    std::cout << "a: " << a << ", b: " << b << '\n';
    original(a);
    laes(a);
    std::cout << "Dobbelt: " << dobbelt(a) << '\n';
}
```

Output er `Lokal kopi: 99`, `a: 20, b: 50`, `Laest: 30` og `Dobbelt: 60`. En ændring af `b` ændrer ikke senere `a`, selvom vi tidligere skrev `r = b`.

## Opgaver

1. Forudsig tælleren, når to sensorer lever i et ydre scope og én i et indre scope.
2. Flyt `hent()` ud af klassens krop. Skriv dens kvalificerede navn, `Sensor::hent`, og behold `const`.
3. Forklar forskellen på `rapport(s)` og `s.hent()`.
4. Afprøv `r = b`, og ændr derefter `b`. Hvilket objekt er `r` stadig bundet til?

<details><summary>Løsningsforslag</summary>

1. Før den indre sensor: 2. Inde i scopet: 3. Efter scopet: 2. Efter det ydre scope: 0.
2. Deklarationen er `double hent() const;`. Definitionen er `double Sensor::hent() const { return maaling; }`. Sæt `inline` på definitionen, hvis den placeres i en header, der inkluderes flere steder, og de øvrige ODR-krav er opfyldt.
3. `rapport` er en fri friend-funktion med et eksplicit argument. `hent` er en medlemsfunktion på det aktuelle objekt.
4. `r` er stadig bundet til `a`. Tildelingen kopierede blot værdien fra `b` til `a`.

</details>

## Videre læsning

Microsofts primære dokumentation: [inline og ODR](https://learn.microsoft.com/en-us/cpp/cpp/inline-functions-cpp), [friend](https://learn.microsoft.com/en-us/cpp/cpp/friend-cpp), [static members](https://learn.microsoft.com/en-us/cpp/cpp/static-members-cpp), [references](https://learn.microsoft.com/en-us/cpp/cpp/references-cpp) og [destructors](https://learn.microsoft.com/en-us/cpp/cpp/destructors-cpp).
