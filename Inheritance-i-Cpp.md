# Inheritance i C++

![Inheritance i C++ – visuel guide til nedarvning](assets/inheritance/cover.png)

> **Læringsmål:** Forstå basisklasser og afledte klasser, læs `public` nedarvning, og brug en arvet funktion i et C++-program.

**Niveau:** Begynder · **Eksempel:** Dyr og Hund · **Sprog:** C++

---

## 1. Hvad er nedarvning?

**Inheritance betyder nedarvning** i objektorienteret programmering. Det betyder, at du kan lave en ny klasse, som bygger videre på en eksisterende klasse.

Den nye klasse kan genbruge funktionalitet og tilføje sine egne egenskaber og funktioner.

## 2. Et enkelt eksempel: Dyr og Hund

Tænk på en generel klasse, der hedder `Dyr`. Et dyr kan fx spise. En `Hund` er et dyr, så den kan også spise, men den kan desuden gø.

![Klassediagram: Hund arver fra Dyr. Dyr har spis(), og Hund tilføjer goe().](assets/inheritance/inheritance.png)

*Den hule trekant peger mod basisklassen `Dyr`. Blå viser det fælles; grøn viser det, `Hund` tilføjer. Plusset angiver en public funktion.*

| Begreb | Betydning | Eksempel |
| --- | --- | --- |
| **Basisklasse** (*Base class*) | Klassen, som andre klasser arver fra | `Dyr` |
| **Afledt klasse** (*Derived class*) | Klassen, som arver og bygger videre | `Hund` |

> **Huskeregel:** Basisklassen indeholder det fælles. Den afledte klasse bygger videre med det særlige.

## 3. Se programmet som en animation

![Animation i fire trin: opret minHund, kald spis(), kald goe(), og se det samlede resultat.](assets/inheritance/inheritance-animation.gif)

Animationen gentages automatisk. Her er de samme trin som tekst:

| Trin | Kode | Hvad sker der? |
| --- | --- | --- |
| 1 | `Hund minHund;` | Opretter et objekt af klassen `Hund`. |
| 2 | `minHund.spis();` | Bruger funktionen fra `Dyr` og udskriver `Dyret spiser.` |
| 3 | `minHund.goe();` | Bruger funktionen fra `Hund` og udskriver `Hunden siger vov!` |
| 4 | Begge kald er udført | Samme objekt har brugt både den arvede og sin egen funktion. |

## 4. Sådan skriver vi det i C++

```cpp
#include <iostream>
using namespace std;

// Basisklasse
class Dyr {
public:
    void spis() {
        cout << "Dyret spiser." << endl;
    }
};

// Hund arver fra Dyr
class Hund : public Dyr {
public:
    void goe() {
        cout << "Hunden siger vov!" << endl;
    }
};

int main() {
    Hund minHund;

    minHund.spis(); // Funktion fra Dyr
    minHund.goe();  // Funktion fra Hund

    return 0;
}
```

### Den vigtigste linje

```cpp
class Hund : public Dyr
```

| Del | Betydning |
| --- | --- |
| `class Hund` | Vi definerer klassen `Hund`. |
| `:` | Klassen arver fra den efterfølgende basisklasse. |
| `public Dyr` | `Hund` arver offentligt fra `Dyr`. De offentlige medlemmer i `Dyr` forbliver offentlige i `Hund`. |

### Programmet udskriver

```text
Dyret spiser.
Hunden siger vov!
```

## 5. Hvad betyder “IS-A”?

“IS-A” betyder **“er en”** og beskriver forholdet mellem klasserne:

| Relation | Eksempel | Passende opbygning |
| --- | --- | --- |
| **Er en / IS-A** | En hund **er et** dyr. | Nedarvning passer. |
| **Er en / IS-A** | En bil **er et** køretøj. | Nedarvning passer. |
| **Har en / HAS-A** | En bil **har en** motor. | Motoren bør normalt være et objekt inde i bilen. Dette kaldes komposition. |

## 6. Vigtigt om adgang

En vigtig detalje i C++: Den afledte klasse kan ikke tilgå basisklassens `private` medlemmer direkte. Den kan bruge de tilgængelige funktioner, som basisklassen stiller til rådighed.

> **Eksempel:** Hvis `Dyr` har en privat variabel, kan `Hund` ikke læse den direkte. En tilgængelig funktion i `Dyr` kan give kontrolleret adgang til værdien.

## 7. Prøv selv

1. Opret en klasse `Kat`, som arver fra `Dyr` med `public` nedarvning.
2. Tilføj funktionen `miav()`, som udskriver `Katten siger miav!`.
3. Opret objektet `minKat`, og kald både `spis()` og `miav()`.
4. Forklar, hvorfor du ikke behøver skrive `spis()` igen i `Kat`.

## 8. Udvidelsesopgaver: Byg videre på dyrene

Arbejd videre fra koden i afsnit 4. Gem en ny version efter hver opgave. Opgave 1–4 bygger oven på hinanden; opgave 5 er et selvstændigt designforsøg.

| Opgave | Fokus | Niveau | Vejledende tid |
| --- | --- | --- | --- |
| 1. Flere dyr | Genbrug af funktioner | 🟢 Begynder | 10–15 min. |
| 2. Navne og constructors | Initialisering af baseklassen | 🟡 Øvet | 20–25 min. |
| 3. Alder med kontrol | Private data og validering | 🟡 Øvet | 20–25 min. |
| 4. Se objekternes livscyklus | Constructors og destructors | 🟡 Øvet | 15–20 min. |
| 5. En hund har et halsbånd | Nedarvning og komposition | 🔵 Udfordring | 25–35 min. |

### Opgave 1 – Udvid med Kat og Fugl

**Mål:** Genbrug én fælles funktion i flere afledte klasser.

1. Færdiggør `Kat` fra afsnit 7.
2. Tilføj `Fugl : public Dyr` med funktionen `syng()`.
3. Opret én hund, én kat og én fugl.
4. Kald `spis()` og derefter dyrets egen funktion på hvert objekt.

**Krav:** Skriv kun `spis()` én gang, i `Dyr`.

**Forventet output:**

```text
Dyret spiser.
Hunden siger vov!
Dyret spiser.
Katten siger miav!
Dyret spiser.
Fuglen synger!
```

<details>
<summary>Hint – hvor skal funktionerne placeres?</summary>

Den fælles adfærd hører til i `Dyr`. `goe()`, `miav()` og `syng()` hører til i hver sin afledte klasse. Brug `public` nedarvning.

</details>

**Forklar:** Hvorfor kan `minFugl.spis()` bruges, selvom `Fugl` ikke selv definerer funktionen?

### Opgave 2 – Giv hvert dyr et navn

**Mål:** Lad en constructor i en afledt klasse sende data til baseklassens constructor.

Tilføj `#include <string>`. Tilføj det private felt `string navn;` i `Dyr` og constructoren `Dyr(string navn)`. Lav en offentlig læsefunktion `string hentNavn() const`.

Opdater `spis()`, så den udskriver dyrets navn. Tilføj constructors til `Hund`, `Kat` og `Fugl`, som sender navnet videre til `Dyr`.

**Afprøv:**

```cpp
Hund hund("Buster");
Kat kat("Luna");
hund.spis();
kat.spis();
```

**Forventet output:**

```text
Buster spiser.
Luna spiser.
```

<details>
<summary>Hint – initialiseringslisten</summary>

Baseklassens constructor kan skrives som `Dyr(string nytNavn) : navn(nytNavn) {}`. I den afledte klasse bruges fx `Hund(string navn) : Dyr(navn) {}`.

Når `Dyr` kun har en constructor med et navneargument, skal de afledte constructors angive dette argument. Opdater også de tidligere objektoprettelser, så de får et navn.

</details>

**Forklar:** Hvorfor må `Hund` ikke læse det private felt `navn` direkte? Hvordan hjælper `hentNavn()`?

### Opgave 3 – Alder, der ikke kan være negativ

**Mål:** Beskyt data med en offentlig funktion, der kontrollerer input.

Tilføj `private: int alder = 0;` i `Dyr`, en offentlig `bool saetAlder(int nyAlder)` og en offentlig `int hentAlder() const`.

**Regler:**

- En alder på `0` eller mere accepteres, gemmes og giver returværdien `true`.
- En negativ alder afvises med `false`.
- Ved afvisning skal den tidligere alder bevares.
- Alderen må ikke ændres direkte fra `main()` eller fra `Hund`.

**Kontrollér disse tilfælde på samme objekt, i rækkefølge:**

| Handling | Returværdi | Alder bagefter |
| --- | --- | --- |
| Opret dyret | — | 0 |
| `saetAlder(3)` | `true` | 3 |
| `saetAlder(-2)` | `false` | 3 |
| `saetAlder(0)` | `true` | 0 |

<details>
<summary>Hint – kontrollér før du gemmer</summary>

Returnér `false` med det samme, hvis input er negativt. Tildel først feltet en ny værdi, når input er godkendt. `Hund` og `Kat` kan bruge funktionerne, fordi de arver dem fra `Dyr`.

</details>

**Forklar:** Hvorfor er `private` plus en kontrolleret funktion bedre her end et offentligt felt?

### Opgave 4 – Hvem oprettes og afsluttes først?

**Mål:** Observer rækkefølgen for constructors og destructors.

Tilføj udskrifter i constructoren og destructoren i både `Dyr` og `Hund`. Afprøv ét lokalt objekt i en blok:

```cpp
{
    Hund hund("Buster");
}
cout << "Blokken er afsluttet." << endl;
```

**Forventet rækkefølge:**

```text
Dyr oprettes.
Hund oprettes.
Hund afsluttes.
Dyr afsluttes.
Blokken er afsluttet.
```

<details>
<summary>Hint – destructorens navn</summary>

En destructor har samme navn som klassen med `~` foran, fx `~Hund()`. Baseklassens constructor kører før den afledte klasses constructor. Ved destruktion er rækkefølgen omvendt.

Brug kun det lokale objekt her. Opgaven kræver hverken `new`, `delete` eller baseklassepointere.

</details>

**Forklar:** Hvorfor skal `Dyr`-delen være klar, før `Hund`-constructorens krop kører?

### Opgave 5 – En hund har et halsbånd

**Mål:** Skeln mellem **er en** og **har en** i et konkret design.

1. Opret klassen `Halsbaand` med en privat farve, en constructor og `string hentFarve() const`.
2. Lad `Hund` indeholde et privat `Halsbaand halsbaand;` som medlemsobjekt.
3. Udvid Hundens constructor til `Hund(string navn, string farve)`.
4. Tilføj `visInfo()`, der viser hundens navn og halsbåndets farve.

**Afprøv:**

```cpp
Hund hund("Buster", "roedt");
hund.visInfo();
hund.spis();
```

**Forventet output:**

```text
Buster har et roedt halsbaand.
Buster spiser.
```

<details>
<summary>Hint – to forskellige relationer</summary>

`Hund` arver stadig fra `Dyr`, men indeholder et `Halsbaand`. Initialiser begge dele:

```cpp
Hund(string navn, string farve)
    : Dyr(navn), halsbaand(farve) {}
```

Læs navnet gennem `hentNavn()` og farven gennem `halsbaand.hentFarve()`.

</details>

**Forklar:** Hvorfor er `Hund : public Halsbaand` et dårligt valg til denne opgave?

## 9. Mini-projekt og aflevering: Et lille dyreinternat

Saml opgave 1–3 i ét program med mindst to hunde, én kat og én fugl. Giv dem forskellige navne og aldre. Vis oplysningerne, lad hvert dyr spise, og kald deres egne funktioner. Afprøv også en negativ alder og vis, at den bliver afvist.

**Ekstra udfordring:** Brug halsbånd fra opgave 5 til hundene. Brug direkte objekter; en fælles polymorf samling kan tilføjes, når du har arbejdet med polymorfi.

**Aflever:**

- En `.cpp`-fil, som kan kompileres.
- Et lille klassediagram med relationerne.
- En testtabel med input, forventet resultat, faktisk resultat og bestået/ikke bestået.
- 5–8 linjer om, hvad du genbrugte gennem nedarvning, og hvordan du beskyttede private data.

**Selvkontrol:** Er `spis()` kun defineret i `Dyr`? Har objekterne hver deres data? Afviser programmet negativ alder uden at ændre den gamle værdi? Kan du forklare forskellen på nedarvning og komposition?


---

**Brug af dokumentet:** Bevar mappen `assets/inheritance` ved siden af denne Markdown-fil. Billeder og GIF-animation vises i Markdown-læsere, der understøtter disse formater, fx GitHub. Farverne ligger i illustrationerne; kodefarver afhænger af læserens tema. Ved PDF-udskrift bliver animationen normalt til et stillbillede.
