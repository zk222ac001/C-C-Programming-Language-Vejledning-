# 💻 Tekstinput i C – `char`, Strings, `scanf_s()` og `fgets()`

> En praktisk introduktion til, hvordan man arbejder med navne, tekst og brugerinput i C.

---

## 📚 Indhold

1. [Introduktion](#-introduktion)
2. [Hvad er en `char`?](#-hvad-er-en-char)
3. [Hvad er en character array?](#-hvad-er-en-character-array)
4. [Hvordan gemmer C tekst?](#-hvordan-gemmer-c-tekst)
5. [Demo 1 – Et simpelt navn med `scanf_s()`](#-demo-1--et-simpelt-navn-med-scanf_s)
6. [Forklaring af Demo 1](#-forklaring-af-demo-1)
7. [`sizeof()` og sikker input](#-sizeof-og-sikker-input)
8. [Problemet med mellemrum](#-problemet-med-mellemrum)
9. [Demo 2 – Fuldt navn med `fgets()`](#-demo-2--fuldt-navn-med-fgets)
10. [Hvorfor får vi `\n`?](#-hvorfor-får-vi-n)
11. [Demo 3 – Fornavn og efternavn separat](#-demo-3--fornavn-og-efternavn-separat)
12. [Demo 4 – Navn og alder](#-demo-4--navn-og-alder)
13. [Demo 5 – Kontrol af brugerinput](#-demo-5--kontrol-af-brugerinput)
14. [Demo 6 – Gentag en personlig hilsen](#-demo-6--gentag-en-personlig-hilsen)
15. [`scanf_s()` vs. `fgets()`](#-scanf_s-vs-fgets)
16. [Typiske fejl](#-typiske-fejl)
17. [Programflow](#-programflow)
18. [Vigtige begreber](#-vigtige-begreber)
19. [Øvelser](#-øvelser)
20. [Opsummering](#-opsummering)

---

# 🌟 Introduktion

Når vi programmerer i C, har vi ofte brug for at få information fra brugeren.

Det kan eksempelvis være:

- 👤 navn
- 🎂 alder
- 🏙️ by
- 📧 e-mail
- 🎓 uddannelse
- 💬 en kort besked

Et program kan eksempelvis spørge:

```text
Enter your name: Zuhair
Hello, Zuhair!
```

For at kunne gøre dette skal vi forstå nogle centrale C-begreber:

- `char`
- arrays
- strings
- `printf()`
- `scanf_s()`
- `fgets()`
- `sizeof()`
- `\0`
- `\n`

---

# 🔤 Hvad er en `char`?

I C bruges datatypen `char` til at gemme **ét enkelt tegn**.

Eksempel:

```c
char letter = 'A';
```

Her gemmer variablen `letter` ét tegn:

```text
A
```

Et tegn skrives normalt med **enkelt citationstegn**:

```c
'A'
'B'
'7'
'#'
```

## Eksempel

```c
#include <stdio.h>

int main(void)
{
    char grade = 'A';

    printf("Your grade is: %c\n", grade);

    return 0;
}
```

Output:

```text
Your grade is: A
```

Her bruger vi `%c`, fordi vi udskriver **ét tegn**.

---

# 📦 Hvad er en character array?

Et navn består ikke kun af ét tegn.

Navnet:

```text
Zuhair
```

består af flere tegn:

```text
Z  u  h  a  i  r
```

Derfor bruger vi et **array af `char`**.

```c
char name[100];
```

Det betyder:

> Opret et område i hukommelsen, der kan bruges til at gemme op til 100 `char`-elementer.

Forenklet kan vi forestille os det sådan:

```text
name
 ↓

+---+---+---+---+---+---+---+---+-----+
| Z | u | h | a | i | r |\0 |   | ... |
+---+---+---+---+---+---+---+---+-----+
  0   1   2   3   4   5   6
```

---

# 🧠 Hvordan gemmer C tekst?

C har ikke en indbygget `string`-datatype på samme måde som eksempelvis Python eller C++.

I C gemmes tekst som:

> Et array af `char`, der afsluttes med specialtegnet `\0`.

Eksempel:

```c
char name[] = "Zuhair";
```

I hukommelsen ser det cirka sådan ud:

```text
Index:     0    1    2    3    4    5    6
          +----+----+----+----+----+----+----+
Value:    | Z  | u  | h  | a  | i  | r  |\0 |
          +----+----+----+----+----+----+----+
```

`\0` kaldes:

**Null terminator**

Det fortæller C:

> Her slutter teksten.

---

# 🧪 Demo 1 – Et simpelt navn med `scanf_s()`

Denne version passer godt til Microsoft Visual Studio.

```c
#include <stdio.h>

int main(void)
{
    char name[100];

    printf("Enter your name: ");

    scanf_s("%s", name, (unsigned)sizeof(name));

    printf("Hello, %s!\n", name);

    return 0;
}
```

Eksempel:

```text
Enter your name: Zuhair
Hello, Zuhair!
```

---

# 🔍 Forklaring af Demo 1

## 1. Header-fil

```c
#include <stdio.h>
```

`stdio.h` betyder:

**Standard Input/Output**

Biblioteket giver os blandt andet adgang til:

```c
printf()
scanf_s()
```

---

## 2. Programmets startpunkt

```c
int main(void)
```

`main()` er den funktion, hvor C-programmet starter.

```text
Operating System
      │
      ▼
   main()
      │
      ▼
 Program code
```

---

## 3. Opret tekstvariablen

```c
char name[100];
```

Her opretter vi et character array med plads til 100 tegn.

Vi kan visualisere det sådan:

```text
name[100]

+-----+-----+-----+-----+-----+-----+---------+
| [0] | [1] | [2] | [3] | [4] | ... | [99] |
+-----+-----+-----+-----+-----+-----+---------+
```

---

## 4. Vis en besked

```c
printf("Enter your name: ");
```

Programmet viser:

```text
Enter your name:
```

`printf()` betyder grundlæggende:

> Print formatted output.

---

## 5. Læs brugerens navn

```c
scanf_s("%s", name, (unsigned)sizeof(name));
```

Her sker flere ting.

### `%s`

```c
"%s"
```

`%s` fortæller C:

> Jeg forventer en string.

### `name`

```c
name
```

Her skal inputtet gemmes.

### `sizeof(name)`

```c
sizeof(name)
```

Finder størrelsen af arrayet.

Da vi har:

```c
char name[100];
```

vil størrelsen være 100 bytes på almindelige C-systemer, fordi `sizeof(char)` altid er 1.

### `(unsigned)`

Microsofts `scanf_s()` forventer en størrelsesværdi for `%s`.

Derfor skriver vi:

```c
(unsigned)sizeof(name)
```

---

## 6. Udskriv navnet

```c
printf("Hello, %s!\n", name);
```

Hvis:

```text
name = Zuhair
```

bliver resultatet:

```text
Hello, Zuhair!
```

Her bliver `%s` erstattet med teksten fra variablen `name`.

---

## 7. Afslut programmet

```c
return 0;
```

Det betyder:

> Programmet blev afsluttet korrekt.

---

# 📏 `sizeof()` og sikker input

Antag, at vi skriver:

```c
char name[100];
```

Så kan vi undersøge størrelsen:

```c
printf("%zu\n", sizeof(name));
```

Output:

```text
100
```

`sizeof()` er nyttig, fordi programmet selv kan finde arrayets størrelse.

I stedet for at skrive:

```c
scanf_s("%s", name, 100);
```

kan vi bruge:

```c
scanf_s("%s", name, (unsigned)sizeof(name));
```

Det reducerer risikoen for, at størrelsen bliver forkert, hvis arrayet senere ændres.

---

# ⚠️ Problemet med mellemrum

Der er en vigtig begrænsning ved:

```c
scanf_s("%s", name, (unsigned)sizeof(name));
```

Hvis brugeren skriver:

```text
Zuhair Ahmed Khan
```

vil `%s` normalt stoppe ved det første mellemrum.

Resultatet bliver derfor:

```text
Zuhair
```

og ikke:

```text
Zuhair Ahmed Khan
```

For fulde navne og hele sætninger er `fgets()` normalt et bedre valg.

---

# 🧪 Demo 2 – Fuldt navn med `fgets()`

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];

    printf("Enter your full name: ");

    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    printf("Hello, %s!\n", name);

    return 0;
}
```

Eksempel:

```text
Enter your full name: Zuhair Ahmed Khan
Hello, Zuhair Ahmed Khan!
```

---

# 🔎 Hvordan virker `fgets()`?

Denne linje:

```c
fgets(name, sizeof(name), stdin);
```

kan opdeles i tre dele.

```text
fgets(
      name,
      sizeof(name),
      stdin
     );
```

## `name`

```c
name
```

Det er arrayet, hvor teksten skal gemmes.

## `sizeof(name)`

```c
sizeof(name)
```

Fortæller, hvor meget plads der er tilgængelig.

## `stdin`

```c
stdin
```

betyder:

**Standard Input**

Normalt er det tastaturet.

Flow:

```text
Keyboard
   │
   ▼
 stdin
   │
   ▼
 fgets()
   │
   ▼
 name[]
```

---

# ↩️ Hvorfor får vi `\n`?

Når brugeren skriver:

```text
Zuhair Khan
```

og trykker **Enter**, kan `fgets()` gemme:

```text
Zuhair Khan\n
```

`\n` betyder:

**New line**

Derfor fjerner vi den ofte med:

```c
name[strcspn(name, "\n")] = '\0';
```

Denne linje:

1. finder `\n`
2. finder positionen i arrayet
3. erstatter `\n` med `\0`

Før:

```text
Z u h a i r   K h a n \n \0
```

Efter:

```text
Z u h a i r   K h a n \0
```

---

# 🧪 Demo 3 – Fornavn og efternavn separat

Nogle gange vil vi have fornavn og efternavn i forskellige variabler.

```c
#include <stdio.h>

int main(void)
{
    char firstName[50];
    char lastName[50];

    printf("Enter first name: ");
    scanf_s("%s", firstName, (unsigned)sizeof(firstName));

    printf("Enter last name: ");
    scanf_s("%s", lastName, (unsigned)sizeof(lastName));

    printf("Hello, %s %s!\n", firstName, lastName);

    return 0;
}
```

Eksempel:

```text
Enter first name: Zuhair
Enter last name: Khan
Hello, Zuhair Khan!
```

### Dataflow

```text
         Keyboard
            │
       ┌────┴─────┐
       ▼          ▼
 firstName     lastName
       │          │
       └────┬─────┘
            ▼
         printf()
            │
            ▼
   Hello, Zuhair Khan!
```

---

# 🧪 Demo 4 – Navn og alder

Nu kombinerer vi tekst med et heltal.

```c
#include <stdio.h>

int main(void)
{
    char name[100];
    int age;

    printf("Enter your name: ");
    scanf_s("%s", name, (unsigned)sizeof(name));

    printf("Enter your age: ");
    scanf_s("%d", &age);

    printf("\n--- User Information ---\n");
    printf("Name: %s\n", name);
    printf("Age : %d\n", age);

    return 0;
}
```

Eksempel:

```text
Enter your name: Anna
Enter your age: 22

--- User Information ---
Name: Anna
Age : 22
```

## Hvorfor bruges `&age`?

Ved heltalsinput skriver vi:

```c
scanf_s("%d", &age);
```

`&` betyder:

> Adressen på variablen.

Visualisering:

```text
Keyboard input: 22
       │
       ▼
   scanf_s()
       │
       ▼
 Memory address of age
       │
       ▼
   age = 22
```

Ved et `char`-array som `name` bruges array-navnet direkte:

```c
scanf_s("%s", name, ...);
```

---

# 🧪 Demo 5 – Kontrol af brugerinput

Det er god programmeringspraksis at kontrollere, om input faktisk lykkedes.

```c
#include <stdio.h>

int main(void)
{
    char name[100];

    printf("Enter your name: ");

    if (scanf_s("%s", name, (unsigned)sizeof(name)) == 1)
    {
        printf("Hello, %s!\n", name);
    }
    else
    {
        printf("Input error.\n");
    }

    return 0;
}
```

Her kontrollerer vi returværdien fra `scanf_s()`.

Hvis én værdi blev læst korrekt:

```c
== 1
```

udskrives navnet.

Ellers vises:

```text
Input error.
```

### Flow

```text
          START
            │
            ▼
       Read input
            │
            ▼
    Was input valid?
        /       \
      Yes        No
       │          │
       ▼          ▼
 Print name    Print error
       \          /
        \        /
            ▼
           END
```

---

# 🧪 Demo 6 – Gentag en personlig hilsen

Vi kan kombinere string-input med en løkke.

```c
#include <stdio.h>

int main(void)
{
    char name[100];
    int times;

    printf("Enter your name: ");
    scanf_s("%s", name, (unsigned)sizeof(name));

    printf("How many greetings do you want? ");
    scanf_s("%d", &times);

    for (int i = 1; i <= times; i++)
    {
        printf("%d. Hello, %s!\n", i, name);
    }

    return 0;
}
```

Eksempel:

```text
Enter your name: Ali
How many greetings do you want? 3

1. Hello, Ali!
2. Hello, Ali!
3. Hello, Ali!
```

Her kombinerer vi:

- string
- heltal
- input
- output
- `for`-loop

---

# ⚖️ `scanf_s()` vs. `fgets()`

| Funktion | Ét ord | Mellemrum | Sikker størrelse | God til begyndere |
|---|---:|---:|---:|---:|
| `scanf_s("%s", ...)` | ✅ | ❌ | ✅ | ✅ |
| `fgets()` | ✅ | ✅ | ✅ | ✅ |
| `scanf("%s", ...)` uden feltbredde | ✅ | ❌ | ⚠️ | ⚠️ |

## Eksempel

Input:

```text
Zuhair Khan
```

Med:

```c
scanf_s("%s", name, (unsigned)sizeof(name));
```

kan resultatet være:

```text
Zuhair
```

Med:

```c
fgets(name, sizeof(name), stdin);
```

kan resultatet være:

```text
Zuhair Khan
```

---

# 🚨 Typiske fejl

## Fejl 1 – For lille array

```c
char name[5];
```

Der er kun meget lidt plads til navnet.

Til almindelige eksempler kan man eksempelvis bruge:

```c
char name[100];
```

Det betyder dog ikke, at man altid skal vælge 100. Størrelsen bør passe til programmets krav.

---

## Fejl 2 – Glemme størrelsen ved `scanf_s()`

Forkert i Microsoft Visual C ved `%s`:

```c
scanf_s("%s", name);
```

Korrekt:

```c
scanf_s("%s", name, (unsigned)sizeof(name));
```

---

## Fejl 3 – Forvente at `%s` læser hele sætninger

```c
scanf_s("%s", name, (unsigned)sizeof(name));
```

stopper normalt ved whitespace.

Til:

```text
Zuhair Ahmed Khan
```

er `fgets()` derfor ofte mere passende.

---

## Fejl 4 – Glemme `&` ved heltal

Forkert:

```c
scanf_s("%d", age);
```

Korrekt:

```c
scanf_s("%d", &age);
```

---

## Fejl 5 – Glemme at fjerne newline efter `fgets()`

Hvis vi skriver:

```c
fgets(name, sizeof(name), stdin);
```

kan `name` indeholde `\n`.

Det kan fjernes med:

```c
name[strcspn(name, "\n")] = '\0';
```

Husk derfor:

```c
#include <string.h>
```

---

# 🔄 Programflow

Et simpelt program med navn kan beskrives sådan:

```text
┌──────────────────────────┐
│          START           │
└─────────────┬────────────┘
              │
              ▼
      Declare name[100]
              │
              ▼
     "Enter your name"
              │
              ▼
        User types name
              │
              ▼
       Read the input
              │
              ▼
       Store in name[]
              │
              ▼
       Print greeting
              │
              ▼
┌──────────────────────────┐
│           END            │
└──────────────────────────┘
```

---

# 🧩 Vigtige begreber

## `char`

Gemmer ét tegn.

```c
char letter = 'A';
```

---

## Character array

Gemmer flere tegn.

```c
char name[100];
```

---

## String

En sekvens af tegn, der slutter med:

```c
'\0'
```

---

## `%c`

Bruges til ét tegn:

```c
printf("%c", letter);
```

---

## `%s`

Bruges til en string:

```c
printf("%s", name);
```

---

## `%d`

Bruges til et heltal:

```c
printf("%d", age);
```

---

## `printf()`

Viser output.

```c
printf("Hello");
```

---

## `scanf_s()`

Læser formateret input. I Microsoft Visual Studio bruges den ofte i undervisning som den sikre variant af `scanf()`.

```c
scanf_s("%d", &age);
```

---

## `fgets()`

Læser en hel linje og kan derfor håndtere mellemrum.

```c
fgets(name, sizeof(name), stdin);
```

---

## `sizeof()`

Finder størrelsen på en datatype, variabel eller et array.

```c
sizeof(name)
```

---

## `\n`

Newline:

```c
printf("Hello\n");
```

---

## `\0`

Markerer slutningen på en C-string.

```text
H e l l o \0
```

---

# 🧠 Samlet konceptdiagram

```text
                         C TEXT INPUT
                              │
          ┌───────────────────┼───────────────────┐
          │                   │                   │
          ▼                   ▼                   ▼
        char               char array           string
          │                   │                   │
          │                   │                   ▼
          │                   │             ends with \0
          │                   │
          └────────────┬──────┘
                       │
                       ▼
                 User Input
                       │
              ┌────────┴────────┐
              │                 │
              ▼                 ▼
          scanf_s()           fgets()
              │                 │
              ▼                 ▼
        good for words     good for lines
              │                 │
              └────────┬────────┘
                       │
                       ▼
                    printf()
                       │
                       ▼
                     Output
```

---

# 📝 Øvelser

## 🟢 Øvelse 1 – Personlig hilsen

Lav et program, som:

1. opretter et `char`-array til et navn
2. spørger brugeren om navnet
3. læser navnet
4. skriver:

```text
Welcome, Anna!
```

---

## 🟢 Øvelse 2 – Fornavn og efternavn

Lav to arrays:

```text
firstName
lastName
```

Programmet skal spørge efter begge værdier og derefter vise:

```text
Your full name is: Ali Hassan
```

---

## 🟡 Øvelse 3 – Fuldt navn

Brug `fgets()` til at læse:

```text
Muhammad Ali Khan
```

Programmet skal vise hele navnet og ikke kun det første ord.

---

## 🟡 Øvelse 4 – Studentprofil

Lav et program, som spørger efter:

- navn
- alder
- studieretning

Eksempel:

```text
Enter name: Sara
Enter age: 21
Enter study programme: IT Technology
```

Output:

```text
-------------------------
      STUDENT PROFILE
-------------------------
Name: Sara
Age: 21
Programme: IT Technology
-------------------------
```

Overvej hvilken inputfunktion der er bedst til studieretningen, fordi den kan indeholde mellemrum.

---

## 🟠 Øvelse 5 – Login-navn

Lav et simpelt program, som spørger efter et brugernavn.

Hvis navnet blev læst korrekt, skal programmet skrive:

```text
Login name accepted.
```

Ellers:

```text
Invalid input.
```

---

## 🔴 Øvelse 6 – Mini Registration System

Lav et program, der indsamler:

```text
Full Name
Age
City
Study Programme
```

Programmet skal derefter præsentere informationen pænt.

Eksempel:

```text
================================
       REGISTRATION DATA
================================
Name       : Anna Jensen
Age        : 24
City       : Næstved
Programme  : IT Technology
================================
```

### Ekstra udfordring

Prøv at bruge:

- `fgets()`
- `sizeof()`
- `strcspn()`
- mindst én `if`-sætning

---

# 🎯 Hvilken metode skal jeg vælge?

En god tommelfingerregel er:

```text
Ét ord?
   │
   ├── YES ──► scanf_s("%s", ...)
   │
   └── NO
        │
        ▼
  Indeholder input mellemrum?
        │
        ├── YES ──► fgets()
        │
        └── NO  ──► scanf_s() kan bruges
```

Til større programmer er det ofte en fordel at være konsekvent og bruge `fgets()` til tekstinput, efterfulgt af validering eller konvertering efter behov.

---

# 📌 Cheat Sheet

```c
// One character
char letter = 'A';

// Character array
char name[100];

// Print one character
printf("%c\n", letter);

// Print string
printf("%s\n", name);

// Read one word in Microsoft Visual Studio
scanf_s("%s", name, (unsigned)sizeof(name));

// Read an integer
scanf_s("%d", &age);

// Read a complete line
fgets(name, sizeof(name), stdin);

// Remove newline from fgets()
name[strcspn(name, "\n")] = '\0';

// Finish program successfully
return 0;
```

---

# ✅ Opsummering

I denne artikel har vi arbejdet med de grundlæggende teknikker til tekstinput i C.

Du har set, at:

- `char` bruges til ét tegn.
- `char name[100]` kan bruges til tekst.
- C-strings afsluttes med `\0`.
- `%s` bruges til strings.
- `%c` bruges til enkelte tegn.
- `%d` bruges til heltal.
- `printf()` viser output.
- `scanf_s()` kan bruges til formateret input i Microsoft Visual Studio.
- `sizeof()` hjælper med at arbejde sikkert med arraystørrelser.
- `scanf_s("%s", ...)` stopper normalt ved mellemrum.
- `fgets()` kan læse hele linjer med mellemrum.
- `fgets()` kan gemme `\n`, som vi ofte fjerner.
- Det er god praksis at kontrollere, om input blev læst korrekt.

---

# 🚀 Næste emne

Efter dette emne vil det være naturligt at fortsætte med:

```text
char og Strings
      │
      ▼
User Input
      │
      ▼
if / else
      │
      ▼
Loops
      │
      ▼
Arrays
      │
      ▼
Functions
      │
      ▼
Simple C Projects
```

Mulige projekter:

- 👤 Student Registration System
- 🔐 Simple Login System
- 📇 Contact Information Program
- 🧾 Customer Registration
- 🎓 Student Profile Generator
- 🏨 Hotel Guest Registration
- 📚 Simple Library Member System

---

## 👨‍💻 Learning Goal

Efter at have arbejdet med artiklen bør den studerende kunne:

- forklare forskellen mellem `char` og et character array
- forklare, hvordan C repræsenterer strings
- bruge `printf()` til tekstoutput
- bruge `scanf_s()` til simpelt input
- bruge `fgets()` til tekst med mellemrum
- forklare `sizeof()`
- forklare forskellen mellem `\n` og `\0`
- vælge en passende metode til forskellige typer brugerinput
- kombinere tekstinput med heltal, betingelser og løkker

---

**Happy Coding! 🚀💻**
