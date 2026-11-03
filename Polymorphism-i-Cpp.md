# Polymorphism i C++: Use Case

![Polymorphism – samme kald, forskellige handlinger](assets/polymorphism/cover.png)

> **Læringsmål:** Forstå baseklassepointere, `virtual`, `override` og dynamisk binding gennem et enkelt spileksempel.

**Niveau:** Begynder · **Forudsætning:** Klasser, objekter og nedarvning · **Eksempel:** Enemy, Ninja og Monster

---

## Polymorfi betyder “mange former”

I C++ betyder det blandt andet, at vi kan kalde den samme funktion på forskellige typer objekter, og at objekterne reagerer forskelligt.

I dette spil bruges følgende eksempel:

- En **Ninja** er en fjende.
- Et **Monster** er også en fjende.
- Begge kan angribe med `attack()`, men de har **hver deres måde at angribe på**.

Guiden fokuserer på **dynamisk polymorfi**. Lad os gennemgå koden trin for trin.

![Enemy er basisklasse. Ninja og Monster arver og overrider attack().](assets/polymorphism/classes.png)

*De hule trekanter peger mod basisklassen. Blå er det fælles interface; lilla og grøn er de to afledte klassers implementeringer.*

## 1. Enemy er baseklassen

Baseklassen indeholder det, som alle fjender har til fælles. Vi begynder med den enkle version fra PDF’en, som endnu ikke har `attack()`:

```cpp
class Enemy {
protected:
    int attackPower;

public:
    void setAttackPower(int a) {
        attackPower = a;
    }
};
```

| Del af koden | Betydning |
| --- | --- |
| `class Enemy` | Definerer en klasse for fjender. |
| `attackPower` | Gemmer fjendens angrebsstyrke. |
| `protected` | Klassen selv og dens afledte klasser kan bruge variablen direkte på deres egne objekter. |
| `public` | Funktionerne kan kaldes fra kode uden for klassen. |
| `setAttackPower(int a)` | Sætter fjendens angrebsstyrke til værdien `a`. |

For eksempel giver `n.setAttackPower(20);` variablen `attackPower` værdien `20` i objektet `n`.

> **Bemærk:** I denne første version skal styrken sættes, før den læses. Det komplette eksempel nedenfor initialiserer den til `0` i constructoren.

## 2. Ninja og Monster arver fra Enemy

```cpp
class Ninja : public Enemy {
public:
    void attack() {
        cout << "Ninja! - " << attackPower << endl;
    }
};

class Monster : public Enemy {
public:
    void attack() {
        cout << "Monster! - " << attackPower << endl;
    }
};
```

Linjen `class Ninja : public Enemy` betyder, at `Ninja` arver fra `Enemy`. **En Ninja er en slags Enemy.**

Begge klasser får adgang til `attackPower` og arver funktionen `setAttackPower()`. De definerer hver deres `attack()`:

```cpp
Ninja n;
Monster m;

n.setAttackPower(20);
m.setAttackPower(80);

n.attack();
m.attack();
```

Resultat:

```text
Ninja! - 20
Monster! - 80
```

**Hvert objekt har sin egen angrebsstyrke.** Når vi ændrer Ninjaens styrke, ændrer vi ikke Monsterets.

*Disse første kodeblokke er uddrag. De bruger `cout` og `endl` fra `<iostream>` med `using namespace std;`, som vist i det komplette program.*

## 3. Hvad betyder Enemy* e1 = &n;?

```cpp
Ninja n;
Monster m;

Enemy* e1 = &n;
Enemy* e2 = &m;
```

Læs den første pointer sådan:

> `e1` er en pointer af typen `Enemy*`, som peger på Ninja-objektet `n`.

| Symbol | Betydning |
| --- | --- |
| `Enemy*` | En pointer til `Enemy`, som også kan pege på basedelen af et objekt fra en offentligt afledt klasse. |
| `&n` | Adressen på objektet `n`. |
| `e1` | Variablen, der gemmer adressen. |

Det er tilladt, fordi **en Ninja også er en Enemy**. Pointeren laver ikke en kopi af Ninjaen. Den peger på det eksisterende objekt.

Derfor ændrer `e1->setAttackPower(20);` angrebsstyrken i `n`. Disse to linjer har samme effekt:

```cpp
n.setAttackPower(20);     // Adgang direkte gennem objektet
e1->setAttackPower(20);  // Adgang gennem pointeren
```

Vi bruger **`.` med et objekt** og **`->` med en pointer**.

## 4. Fra nedarvning til dynamisk polymorfi

De første eksempler kalder `n.attack();` og `m.attack();` direkte. Her vælger vi Ninjaens og Monsterets funktioner via objekternes kendte typer.

Hvis vi med den første `Enemy`-klasse prøver:

```cpp
// Kan ikke kompileres med den første Enemy-klasse:
e1->attack();
```

får vi en kompileringsfejl, fordi `Enemy` **ikke har nogen `attack()`-funktion**.

For at kalde `attack()` gennem en `Enemy*` og få det faktiske objekts version skal baseklassen deklarere en **virtuel funktion**:

```cpp
virtual void attack();
```

Denne linje viser deklarationen. Det komplette program nedenfor giver også funktionen en implementation.

| Situation | Resultat ved `e1->attack()`, hvor e1 peger på Ninja |
| --- | --- |
| Ingen `attack()` i `Enemy` | Kompileringsfejl. |
| En ikke-virtuel `attack()` i `Enemy` | `Enemy::attack()` kaldes. |
| En virtuel `attack()` i `Enemy`, overridet i `Ninja` | `Ninja::attack()` kaldes. |

> **Husk:** Nedarvning giver fælles struktur. `virtual` muliggør valg af den afledte implementation gennem en baseklassepointer eller -reference.

## 5. Se dynamisk binding som animation

![Animation: Enemy-pointeren peger først på Ninja, derefter på Monster. Samme virtuelle kald vælger forskellige attack()-funktioner.](assets/polymorphism/dispatch.gif)

Animationen gentages automatisk. De samme trin står her som tekst:

| Trin | Pointer og objekt | Virtuelt kald | Valgt funktion |
| --- | --- | --- | --- |
| 1 | `Enemy* e1 = &n;` | Intet kald endnu | Pointeren peger på Ninja. |
| 2 | `e1` peger på `n` | `e1->attack();` | `Ninja::attack()` |
| 3 | `Enemy* e2 = &m;` | Intet kald endnu | Pointeren peger på Monster. |
| 4 | `e2` peger på `m` | `e2->attack();` | `Monster::attack()` |

Begge pointere har **statisk type `Enemy*`**. De faktiske objekter har forskellig **dynamisk type**: `Ninja` og `Monster`.

## 6. Komplet eksempel med dynamisk polymorfi

[Download C++-koden](examples/polymorphism/enemies.cpp).

```cpp
#include <iostream>
using namespace std;

class Enemy {
protected:
    int attackPower;
public:
    // Alle fjender starter med angrebsstyrke 0.
    Enemy() : attackPower(0) {}

    void setAttackPower(int power) {
        attackPower = power;
    }

    // Det faktiske objekt bestemmer versionen ved virtuelle kald.
    virtual void attack() {
        cout << "Enemy angriber med styrke " << attackPower << endl;
    }

    // Muliggør korrekt destruktion gennem en Enemy-pointer.
    virtual ~Enemy() = default;
};

class Ninja : public Enemy {
public:
    // Compileren kontrollerer, at en virtuel funktion overrides.
    void attack() override {
        cout << "Ninja angriber med et svaerd! Styrke: "
             << attackPower << endl;
    }
};

class Monster : public Enemy {
public:
    void attack() override {
        cout << "Monster angriber med kloer! Styrke: "
             << attackPower << endl;
    }
};

int main() {
    Ninja n;
    Monster m;

    Enemy* e1 = &n;
    Enemy* e2 = &m;

    e1->setAttackPower(20);
    e2->setAttackPower(80);

    // Samme pointertype, men forskellige implementeringer.
    e1->attack();
    e2->attack();
    return 0;
}
```

### Output

```text
Ninja angriber med et svaerd! Styrke: 20
Monster angriber med kloer! Styrke: 80
```

| Kald | Pointerens type | Faktisk objekt | Funktionen, der køres |
| --- | --- | --- | --- |
| `e1->attack()` | `Enemy*` | `Ninja` | `Ninja::attack()` |
| `e2->attack()` | `Enemy*` | `Monster` | `Monster::attack()` |

**`virtual` betyder her: “Brug funktionen fra det objekt, pointeren faktisk peger på.”** Valget følger objektets dynamiske type, mens programmet kører. Det kaldes **dynamisk binding**.

### De vigtigste nøgleord

| Kode | Hvorfor er den med? |
| --- | --- |
| `Enemy() : attackPower(0)` | Constructoren initialiserer angrebsstyrken til `0`. |
| `virtual void attack()` | Gør funktionskaldet polymorft. |
| `void attack() override` | Beder compileren kontrollere, at funktionen faktisk overrider en virtuel funktion i baseklassen. |
| `virtual ~Enemy() = default;` | Sikrer korrekt destruktion, hvis et afledt objekt slettes gennem en `Enemy*`. |

Objekterne `n` og `m` er lokale i dette eksempel. Pointerne ejer dem ikke, og vi skal **ikke** kalde `delete` på `e1` eller `e2`.

### Kør programmet

Med en installeret GCC-compiler kan du køre følgende fra repositoryets rod på Linux eller macOS:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic examples/polymorphism/enemies.cpp -o enemies
./enemies
```

På Windows med Visual Studio: opret et C++ Console App-projekt, indsæt koden i projektets `.cpp`-fil, og kør med **Ctrl+F5**.

## 7. Hvorfor er det nyttigt i et spil?

Du kan behandle forskellige fjender samlet. Erstat de to direkte pointerkald i `main()` med:

```cpp
Enemy* enemies[] = { &n, &m };

for (Enemy* enemy : enemies) {
    enemy->attack();
}
```

Løkken behøver ikke undersøge, om fjenden er en Ninja eller et Monster. Den siger bare:

> **“Fjende, angrib!”**

Hvert objekt udfører sin egen version af `attack()`. Det er fordelen ved dynamisk polymorfi. Løkken giver samme output som de to kald i det komplette program.

## 8. Prøv selv: Tilføj en Dragon

1. Opret `class Dragon : public Enemy`.
2. Skriv `void attack() override`, som udskriver, at dragen angriber med ild, og viser dens styrke.
3. Opret `Dragon d;`, og sæt dens styrke til `100`.
4. Tilføj `&d` til arrayet `enemies`.
5. Kør den samme løkke igen. Du skal nu få tre forskellige angreb.

**Refleksion:** Hvorfor kan løkkens indhold være uændret, selvom du tilføjer en ny slags fjende?

## 9. Udvidelsesopgaver: Byg videre på spillet

Tag udgangspunkt i det komplette program i afsnit 6. Færdiggør først Dragon-opgaven i afsnit 8. Opgave 1–2 bygger videre på denne version. Lav **separate kopier** til forsøgene i opgave 3, 4 og 5, da de ændrer baseklassen på forskellige måder.

| Opgave | Fokus | Niveau | Vejledende tid |
| --- | --- | --- | --- |
| 1. Alle fjender angriber | Fælles interface og løkke | 🟢 Begynder | 15–20 min. |
| 2. Send en fjende til en funktion | Baseklassereferencer | 🟡 Øvet | 15–20 min. |
| 3. Eksperimentér med virtual | Statisk og dynamisk binding | 🟡 Øvet | 20–25 min. |
| 4. Gør Enemy abstrakt | Pure virtual og override | 🔵 Udfordring | 20–25 min. |
| 5. Find object slicing | Kopiering kontra reference | 🔵 Udfordring | 20–25 min. |

### Opgave 1 – En fælles samling af fjender

**Mål:** Tilføj en ny type uden at ændre løkkens angrebslogik.

Opret en Ninja, et Monster og en Dragon. Sæt styrkerne til henholdsvis `20`, `80` og `100`. Lad Dragon udskrive:

```text
Dragon angriber med ild! Styrke: 100
```

Saml adresserne i et `Enemy*`-array. Kald alle angreb med én løkke.

**Krav:** Løkkens krop må kun kalde `enemy->attack();`. Brug ikke `if`, `switch` eller typekonverteringer til at vælge fjendetype.

**Forventet output:**

```text
Ninja angriber med et svaerd! Styrke: 20
Monster angriber med kloer! Styrke: 80
Dragon angriber med ild! Styrke: 100
```

<details>
<summary>Hint – samlingen gemmer adresser</summary>

Brug `Enemy* enemies[] = { &n, &m, &d };`. Objekterne skal eksistere, så længe løkken bruger dem. Pointerne ejer ikke de lokale objekter, så du skal ikke bruge `delete`.

</details>

**Kontrol:** Skift kun Dragonens styrke til `120`. Kun dens udskrift skal ændre styrke.

### Opgave 2 – En funktion, der kan modtage alle fjender

**Mål:** Brug polymorfi gennem en baseklassereference.

Tilføj følgende funktion uden for klasserne:

```cpp
void udfoerAngreb(Enemy& enemy) {
    // TODO: Kald fjendens virtuelle attack().
}
```

Kald funktionen med `n`, `m` og `d`.

**Forventning:** Du får de samme tre angreb som i opgave 1, med de styrker du har sat. Funktionen må ikke spørge efter fjendens konkrete type.

<details>
<summary>Hint – reference og punktum</summary>

En reference bruger `enemy.attack();`. Parameteren `Enemy&` henviser til det eksisterende objekt; den kopierer det ikke. Den virtuelle funktion vælger stadig den konkrete fjendes implementation.

</details>

**Forklar:** Hvad betyder `&` i parameteren? Hvorfor bruges `.` her, men `->` i pointerløkken?

### Opgave 3 – Hvad sker der uden virtual?

**Mål:** Se forskellen på statisk og dynamisk binding. Lav dette forsøg i en separat kopi af programmet fra afsnit 6.

1. Forudsig resultatet af `e1->attack();`.
2. Fjern kun `virtual` fra `Enemy::attack()`. Bevar den virtuelle destructor.
3. Prøv at kompilere med `override` bevaret i Ninja og Monster.
4. Notér fejlen. Fjern derefter `override` fra begge afledte `attack()`-funktioner, og kør igen.
5. Sammenlign `n.attack();` med `e1->attack();`.
6. Gendan `virtual` og `override` efter forsøget.

| Variant | Forventet resultat |
| --- | --- |
| `virtual` i Enemy og `override` i Ninja | Pointerkaldet bruger Ninjaens angreb. |
| Uden `virtual`, men med `override` | Kompileringsfejl: funktionen overrider ikke en virtuel basefunktion. |
| Uden både `virtual` og `override` | Pointerkaldet udskriver `Enemy angriber med styrke 20`. |
| Direkte `n.attack()` uden virtual | Ninjaens egen funktion kaldes stadig. |

<details>
<summary>Hint – pointerens type og objektets type</summary>

Uden en virtuel `attack()` afgøres `e1->attack()` ud fra den statiske type `Enemy*`. Med `virtual` bruges den konkrete implementation for det objekt, pointeren peger på.

At destructoren er virtuel gør ikke automatisk andre funktioner virtuelle.

</details>

**Forklar:** Hvorfor er `override` nyttigt som kontrol, selvom det er `virtual` i baseklassen, der etablerer den virtuelle funktion?

### Opgave 4 – Enemy skal være en abstrakt klasse

**Mål:** Kræv, at konkrete fjender implementerer deres eget angreb.

Lav en ny kopi af den fungerende version med `virtual`. Erstat hele baseklassens `attack()`-definition med:

```cpp
virtual void attack() = 0;
```

Dette kaldes en **pure virtual funktion**. En klasse med en sådan funktion, som endnu ikke har en konkret endelig override, er abstrakt og kan ikke oprettes som et selvstændigt objekt.

1. Kontrollér, at Ninja, Monster og Dragon stadig kan angribe gennem `Enemy*`.
2. Prøv midlertidigt at skrive `Enemy e;`. Notér kompileringsfejlen, og fjern linjen igen.
3. Fjern midlertidigt Dragonens `attack()`. Prøv at oprette `Dragon d;`.
4. Gendan Dragonens funktion.

**Forventning:** `Enemy e;` kan ikke kompileres. En Dragon uden en implementation af den pure virtual funktion er også abstrakt. Med alle tre overrides virker pointerløkken stadig.

<details>
<summary>Hint – behold resten af baseklassen</summary>

Behold constructor, `attackPower`, `setAttackPower()` og den virtuelle destructor. Du ændrer kun `attack()`. `= 0` betyder ikke, at funktionen returnerer tallet nul.

</details>

**Forklar:** Hvorfor kan `Enemy*` og `Enemy&` stadig bruges, selvom du ikke kan skrive `Enemy e;`?

### Opgave 5 – Opdag object slicing

**Mål:** Forstå, hvorfor polymorfe objekter normalt sendes med reference eller pointer.

Brug en separat kopi af det komplette program i afsnit 6, hvor `Enemy` **ikke er abstrakt**, og `attack()` stadig er virtuel. Tilføj:

```cpp
void angrebMedKopi(Enemy enemy) {
    enemy.attack();
}

void angrebMedReference(Enemy& enemy) {
    enemy.attack();
}
```

Afprøv i `main()`:

```cpp
Ninja n;
n.setAttackPower(20);
angrebMedKopi(n);
angrebMedReference(n);
```

**Forventet output:**

```text
Enemy angriber med styrke 20
Ninja angriber med et svaerd! Styrke: 20
```

<details>
<summary>Hint – hvad bliver kopieret?</summary>

Værdiparameteren `Enemy enemy` opretter et nyt `Enemy`-objekt fra Ninjaens basedel. Ninja-delen kommer ikke med. Dette kaldes **object slicing**.

Referencen `Enemy&` henviser til den oprindelige Ninja. Derfor virker dynamisk binding til `Ninja::attack()`. Det oprindelige objekt `n` ændrer ikke type i nogen af forsøgene.

</details>

**Forklar:** Hvorfor kan `virtual` ikke genskabe Ninja-delen, når objektet allerede er kopieret til et selvstændigt `Enemy`-objekt?

## 10. Mini-projekt og aflevering: Tre kamprunder

Brug den fungerende version med Ninja, Monster og Dragon. Kør tre kamprunder gennem det samme `Enemy*`-array.

**Regler:**

- Runde 1 bruger styrkerne `20`, `80` og `100`.
- Før hver efterfølgende runde øges hver fjendes styrke med `10`.
- Tilføj `int getAttackPower() const` til Enemy, så hovedprogrammet kan læse styrken.
- Udvid `setAttackPower()`, så negative værdier afvises, og den tidligere styrke bevares. Lad funktionen returnere `bool`: `true` ved accept og `false` ved afvisning.
- Bevar `override` i alle konkrete fjendeklasser og den virtuelle destructor.
- Brug samme løkke til alle fjendetyper; ingen typekontrol i angrebslogikken.

| Runde | Ninja | Monster | Dragon |
| --- | --- | --- | --- |
| 1 | 20 | 80 | 100 |
| 2 | 30 | 90 | 110 |
| 3 | 40 | 100 | 120 |

**Test også:** En ny fjende starter med styrke `0`; `setAttackPower(0)` accepteres; `setAttackPower(-5)` afvises uden at ændre den tidligere værdi.

**Ekstra udfordring:** Tilføj en `RobotEnemy`. Kun oprettelsen og samlingen skal udvides; selve angrebsløkken skal være uændret.

**Aflever:**

- En `.cpp`-fil med det færdige spil.
- En testtabel med forventede og faktiske resultater for alle tre runder samt negative værdier.
- En kort forklaring af `virtual`, `override` og forskellen på pointerens type og objektets type.
- Din forklaring på fejlen i opgave 3 og resultatet af object slicing i opgave 5.

**Selvkontrol:** Vælger det virtuelle kald den rigtige funktion? Har alle objekter deres egne styrker? Virker en ny fjendetype uden ændringer i angrebsløkken? Undgår du at kopiere de afledte objekter til `Enemy`-værdier?


---

**Materiale:** Bearbejdet fra den vedhæftede PDF *Polymorphism i C++: Use Case*, med nye diagrammer, animation, nøgleordsforklaring og øvelse. De tomme PDF-sider er udeladt.

**Visning:** Bevar `assets/polymorphism` og `examples/polymorphism` sammen med Markdown-filen. GIF-animationen virker i fx GitHub; ved PDF-udskrift bliver den normalt et stillbillede. Kodefarver afhænger af Markdown-læserens tema.
