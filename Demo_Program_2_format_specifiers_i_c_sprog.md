# 🎯 Format Specifiers i C

> En praktisk og begyndervenlig artikel om **format specifiers i C** med forklaringer, tabeller, demo-programmer, output, diagrammer og øvelser.

---

## 📚 Indhold

1. [Introduktion](#-introduktion)
2. [Hvad er en Format Specifier?](#-hvad-er-en-format-specifier)
3. [Hvor bruger vi Format Specifiers?](#-hvor-bruger-vi-format-specifiers)
4. [Oversigt over de vigtigste Format Specifiers](#-oversigt-over-de-vigtigste-format-specifiers)
5. [Demo 1 – Integer med `%d`](#-demo-1--integer-med-d)
6. [Demo 2 – Decimal-tal med `%f`](#-demo-2--decimal-tal-med-f)
7. [Demo 3 – Character og String med `%c` og `%s`](#-demo-3--character-og-string-med-c-og-s)
8. [Demo 4 – Flere datatyper i samme program](#-demo-4--flere-datatyper-i-samme-program)
9. [Demo 5 – Formatering med bredde og decimaler](#-demo-5--formatering-med-bredde-og-decimaler)
10. [`printf()` vs. `scanf()`](#-printf-vs-scanf)
11. [`float` vs. `double`](#-float-vs-double)
12. [Andre nyttige Format Specifiers](#-andre-nyttige-format-specifiers)
13. [Typiske fejl](#-typiske-fejl)
14. [Cheat Sheet](#-cheat-sheet)
15. [Øvelser](#-øvelser)
16. [Mini Assignment](#-mini-assignment)
17. [Opsummering](#-opsummering)

---

# 🌟 Introduktion

Når vi programmerer i C, arbejder vi med forskellige datatyper.

Eksempel:

```c
int age = 25;
float price = 99.95f;
char grade = 'A';
char name[] = "Zuhair";
```

Disse værdier har forskellige datatyper:

```text
age      → int
price    → float
grade    → char
name     → string / char array
```

Når vi bruger `printf()` eller `scanf()`, skal C vide, **hvilken datatype** vi vil udskrive eller læse.

Her bruger vi **Format Specifiers**.

---

# 🔤 Hvad er en Format Specifier?

En format specifier er en særlig kode, der begynder med:

```text
%
```

Eksempel:

```c
%d
```

`%d` fortæller C:

> Denne værdi er et heltal (`int`).

Eksempel:

```c
int age = 25;

printf("Age: %d\n", age);
```

Output:

```text
Age: 25
```

---

# 🧠 Grundideen

Vi kan visualisere det sådan:

```text
Variable
   │
   ▼
Datatype
   │
   ▼
Format Specifier
   │
   ▼
printf() / scanf()
   │
   ▼
Output / Input
```

Eksempel:

```text
age
 │
 ▼
int
 │
 ▼
%d
 │
 ▼
printf("Age: %d", age)
 │
 ▼
Age: 25
```

---

# 🖥️ Hvor bruger vi Format Specifiers?

Format specifiers bruges især sammen med:

```c
printf()
```

og:

```c
scanf()
```

I Microsoft Visual Studio bruges ofte:

```c
scanf_s()
```

---

## Eksempel med `printf()`

```c
int number = 10;

printf("%d\n", number);
```

Output:

```text
10
```

---

## Eksempel med `scanf_s()`

```c
int number;

printf("Enter a number: ");
scanf_s("%d", &number);
```

Her fortæller:

```c
%d
```

at programmet skal læse et heltal.

---

# 📋 Oversigt over de vigtigste Format Specifiers

| Format Specifier | Datatype | Eksempel |
|---|---|---|
| `%d` | `int` | `25` |
| `%i` | `int` | `25` |
| `%f` | `float` / decimal output | `10.50` |
| `%lf` | `double` ved `scanf()` | `10.500000` |
| `%c` | `char` | `A` |
| `%s` | string / `char[]` | `Zuhair` |
| `%u` | `unsigned int` | `100` |
| `%ld` | `long int` | `100000` |
| `%lld` | `long long int` | `9000000000` |
| `%x` | hexadecimal | `ff` |
| `%X` | hexadecimal med store bogstaver | `FF` |
| `%o` | octal | `377` |
| `%p` | pointer-adresse | `0x...` |
| `%zu` | `size_t` | resultat fra `sizeof()` |
| `%%` | procenttegn | `%` |

---

# 🧪 Demo 1 – Integer med `%d`

## Formål

Denne demo viser, hvordan vi arbejder med heltal.

```c
#include <stdio.h>

int main(void)
{
    int age = 25;
    int students = 30;

    printf("Age: %d\n", age);
    printf("Number of students: %d\n", students);

    return 0;
}
```

---

## Output

```text
Age: 25
Number of students: 30
```

---

## Forklaring

Variablen:

```c
int age = 25;
```

har datatypen:

```text
int
```

Derfor bruger vi:

```c
%d
```

---

## Visualisering

```text
int age = 25
     │
     ▼
    %d
     │
     ▼
printf()
     │
     ▼
Age: 25
```

---

## Input med `%d`

```c
#include <stdio.h>

int main(void)
{
    int age;

    printf("Enter your age: ");
    scanf_s("%d", &age);

    printf("Your age is: %d\n", age);

    return 0;
}
```

Eksempel:

```text
Enter your age: 22
Your age is: 22
```

Bemærk:

```c
&age
```

betyder:

> Adressen på variablen `age`.

---

# 🧪 Demo 2 – Decimal-tal med `%f`

## Formål

`%f` bruges til decimal-tal i output.

```c
#include <stdio.h>

int main(void)
{
    float price = 99.95f;
    float temperature = 21.5f;

    printf("Price: %f\n", price);
    printf("Temperature: %f\n", temperature);

    return 0;
}
```

---

## Output

```text
Price: 99.949997
Temperature: 21.500000
```

En `float` har begrænset præcision, så nogle decimalværdier kan ikke repræsenteres helt nøjagtigt.

Ofte ønsker vi kun to decimaler.

Så skriver vi:

```c
printf("Price: %.2f\n", price);
```

Output:

```text
Price: 99.95
```

---

## Hvad betyder `%.2f`?

```text
% . 2 f
│   │ │
│   │ └── floating-point
│   └──── 2 decimaler
└──────── format specifier
```

---

## Program med to decimaler

```c
#include <stdio.h>

int main(void)
{
    float price = 99.95f;

    printf("Price: %.2f DKK\n", price);

    return 0;
}
```

Output:

```text
Price: 99.95 DKK
```

---

# 🧪 Demo 3 – Character og String med `%c` og `%s`

## `%c` – ét tegn

```c
#include <stdio.h>

int main(void)
{
    char grade = 'A';

    printf("Grade: %c\n", grade);

    return 0;
}
```

Output:

```text
Grade: A
```

---

## `%s` – tekst

```c
#include <stdio.h>

int main(void)
{
    char name[] = "Zuhair";

    printf("Name: %s\n", name);

    return 0;
}
```

Output:

```text
Name: Zuhair
```

---

## Kombination

```c
#include <stdio.h>

int main(void)
{
    char name[] = "Sara";
    char grade = 'A';

    printf("Student: %s\n", name);
    printf("Grade: %c\n", grade);

    return 0;
}
```

Output:

```text
Student: Sara
Grade: A
```

---

## Visualisering

```text
char grade = 'A'
      │
      ▼
     %c

char name[] = "Sara"
      │
      ▼
     %s
```

---

# 🧪 Demo 4 – Flere datatyper i samme program

Nu kombinerer vi flere format specifiers.

```c
#include <stdio.h>

int main(void)
{
    char name[] = "Ali";
    int age = 23;
    char grade = 'B';
    float average = 8.75f;

    printf("================================\n");
    printf("       STUDENT INFORMATION\n");
    printf("================================\n");

    printf("Name:    %s\n", name);
    printf("Age:     %d\n", age);
    printf("Grade:   %c\n", grade);
    printf("Average: %.2f\n", average);

    printf("================================\n");

    return 0;
}
```

---

## Output

```text
================================
       STUDENT INFORMATION
================================
Name:    Ali
Age:     23
Grade:   B
Average: 8.75
================================
```

---

## Format Specifiers i programmet

```text
%s → Name
%d → Age
%c → Grade
%f → Average
```

---

## Dataflow

```text
name ----------> %s -----┐
age -----------> %d -----│
grade ----------> %c ----├──► printf() ──► Terminal
average --------> %.2f ---│
                         ┘
```

---

# 🧪 Demo 5 – Formatering med bredde og decimaler

Format specifiers kan gøre mere end bare at fortælle datatypen.

Vi kan også styre:

- antal decimaler
- minimumsbredde
- venstrejustering
- højrejustering

---

## Program

```c
#include <stdio.h>

int main(void)
{
    printf("%-15s %10s\n", "Product", "Price");
    printf("--------------------------------\n");

    printf("%-15s %10.2f\n", "Keyboard", 299.95);
    printf("%-15s %10.2f\n", "Mouse", 149.50);
    printf("%-15s %10.2f\n", "Monitor", 1899.00);

    return 0;
}
```

---

## Output

```text
Product              Price
--------------------------------
Keyboard            299.95
Mouse               149.50
Monitor            1899.00
```

---

## Forklaring

### `%-15s`

```text
% - 15 s
│ │ │  │
│ │ │  └── string
│ │ └───── minimum 15 tegn
│ └─────── venstrejusteret
└───────── format
```

### `%10.2f`

```text
% 10 . 2 f
│ │    │ │
│ │    │ └── floating-point
│ │    └──── 2 decimaler
│ └───────── minimum 10 tegn bred
└─────────── format
```

---

# 🔄 `printf()` vs. `scanf()`

Det er vigtigt at forstå, at samme format specifier ikke altid bruges helt ens i `printf()` og `scanf()`.

---

## `printf()`

Bruges til:

```text
Program → Screen
```

Eksempel:

```c
int age = 22;

printf("%d\n", age);
```

---

## `scanf_s()`

Bruges til:

```text
Keyboard → Program
```

Eksempel:

```c
int age;

scanf_s("%d", &age);
```

---

## Diagram

```text
                INPUT

Keyboard
   │
   ▼
scanf_s()
   │
   ▼
Variable


                OUTPUT

Variable
   │
   ▼
printf()
   │
   ▼
Screen
```

---

# 📌 `float` vs. `double`

Dette er et vigtigt område.

## Ved `scanf()` / `scanf_s()`

For `float`:

```c
float number;

scanf_s("%f", &number);
```

For `double`:

```c
double number;

scanf_s("%lf", &number);
```

---

## Ved `printf()`

Til almindeligt decimal-output bruger man:

```c
%f
```

også når variablen er `double`.

Eksempel:

```c
double pi = 3.14159265;

printf("%f\n", pi);
printf("%.2f\n", pi);
```

Output:

```text
3.141593
3.14
```

---

## Vigtig huskeregel

```text
              scanf()
                 │
        ┌────────┴────────┐
        │                 │
      float             double
        │                 │
        ▼                 ▼
       %f                %lf


              printf()
                 │
                 ▼
         floating values
                 │
                 ▼
                %f
```

---

# 🔢 Andre nyttige Format Specifiers

## `%u` – Unsigned Integer

```c
unsigned int count = 100;

printf("%u\n", count);
```

Output:

```text
100
```

---

## `%ld` – Long Integer

```c
long int population = 6000000;

printf("%ld\n", population);
```

---

## `%lld` – Long Long Integer

```c
long long int bigNumber = 9000000000LL;

printf("%lld\n", bigNumber);
```

---

# 🧮 Hexadecimal med `%x` og `%X`

```c
#include <stdio.h>

int main(void)
{
    int number = 255;

    printf("Decimal: %d\n", number);
    printf("Hex: %x\n", number);
    printf("HEX: %X\n", number);

    return 0;
}
```

Output:

```text
Decimal: 255
Hex: ff
HEX: FF
```

---

# 🔢 Octal med `%o`

```c
int number = 64;

printf("%o\n", number);
```

Output:

```text
100
```

---

# 📍 Pointer med `%p`

```c
#include <stdio.h>

int main(void)
{
    int number = 10;

    printf("Value: %d\n", number);
    printf("Address: %p\n", (void *)&number);

    return 0;
}
```

Outputtet for adressen varierer:

```text
Value: 10
Address: 0x7ff...
```

---

# 📏 `sizeof()` med `%zu`

`sizeof()` returnerer en værdi af typen:

```text
size_t
```

Derfor bruges normalt:

```c
%zu
```

Eksempel:

```c
#include <stdio.h>

int main(void)
{
    int number;

    printf("Size of int: %zu bytes\n", sizeof(number));

    return 0;
}
```

Et almindeligt resultat kan være:

```text
Size of int: 4 bytes
```

Den præcise størrelse kan afhænge af systemet og datatypen.

---

# 💯 Udskriv procenttegn med `%%`

Hvis vi vil vise:

```text
50%
```

kan vi ikke bare bruge `%` som et formattegn.

Vi skriver:

```c
printf("Progress: 50%%\n");
```

Output:

```text
Progress: 50%
```

---

# 🧠 Samlet konceptdiagram

```text
                    FORMAT SPECIFIERS
                           │
           ┌───────────────┼───────────────┐
           │               │               │
           ▼               ▼               ▼
      Integers          Decimal           Text
           │               │               │
      ┌────┼────┐          │          ┌────┴────┐
      │    │    │          │          │         │
      ▼    ▼    ▼          ▼          ▼         ▼
     %d   %u   %ld        %f         %c        %s
                           │
                           ▼
                      Precision
                           │
                           ▼
                         %.2f
```

---

# 🚨 Typiske fejl

## Fejl 1 – Forkert format specifier

Forkert:

```c
int age = 25;

printf("%f", age);
```

Korrekt:

```c
printf("%d", age);
```

---

## Fejl 2 – `%d` til decimal-tal

Forkert:

```c
float price = 10.5f;

printf("%d", price);
```

Korrekt:

```c
printf("%f", price);
```

eller:

```c
printf("%.2f", price);
```

---

## Fejl 3 – `%c` og `%s` blandes sammen

Ét tegn:

```c
char grade = 'A';

printf("%c", grade);
```

Tekst:

```c
char name[] = "Ali";

printf("%s", name);
```

---

## Fejl 4 – Glemme `&` i `scanf_s()`

Forkert:

```c
int age;

scanf_s("%d", age);
```

Korrekt:

```c
scanf_s("%d", &age);
```

---

## Fejl 5 – Forkert format til `double` ved input

Forkert:

```c
double value;

scanf_s("%f", &value);
```

Korrekt:

```c
scanf_s("%lf", &value);
```

---

## Fejl 6 – String med `scanf_s()`

Ved Microsofts `scanf_s()` skal `%s` også have bufferstørrelsen.

```c
char name[100];

scanf_s("%s", name, (unsigned)sizeof(name));
```

---

# 📝 Format Specifier Cheat Sheet

```c
// Integer
int age = 25;
printf("%d\n", age);

// Unsigned integer
unsigned int count = 100;
printf("%u\n", count);

// Float / decimal output
float price = 19.95f;
printf("%.2f\n", price);

// Double output
double pi = 3.14159;
printf("%.2f\n", pi);

// Character
char grade = 'A';
printf("%c\n", grade);

// String
char name[] = "Ali";
printf("%s\n", name);

// Long
long value = 100000L;
printf("%ld\n", value);

// Long long
long long big = 9000000000LL;
printf("%lld\n", big);

// Hexadecimal
printf("%x\n", 255);

// Octal
printf("%o\n", 64);

// Pointer
int number = 10;
printf("%p\n", (void *)&number);

// sizeof()
printf("%zu\n", sizeof(number));

// Percentage sign
printf("50%%\n");
```

---

# 📝 Øvelse 1 – Student Information

Opret variabler til:

```text
Name
Age
Grade
Average
```

Programmet skal vise:

```text
==============================
      STUDENT INFORMATION
==============================
Name:       Anna
Age:        22
Grade:      A
Average:    9.25
==============================
```

Brug:

```text
%s
%d
%c
%.2f
```

---

# 📝 Øvelse 2 – Product Information

Opret:

```text
Product Name
Quantity
Price
```

Eksempel:

```text
Product: Keyboard
Quantity: 2
Price: 299.95 DKK
```

Brug korrekte format specifiers.

---

# 📝 Øvelse 3 – Temperatur

Lav et program med:

```c
float temperature = 21.567f;
```

Vis temperaturen med:

1. standard `%f`
2. én decimal
3. to decimaler

Eksempel:

```text
Standard: 21.566999
1 decimal: 21.6
2 decimals: 21.57
```

---

# 📝 Øvelse 4 – Number Converter

Opret:

```c
int number = 255;
```

Programmet skal vise:

```text
Decimal:     255
Hexadecimal: ff
Octal:       377
```

Brug:

```text
%d
%x
%o
```

---

# 📝 Øvelse 5 – Formateret produktliste

Lav denne tabel:

```text
-----------------------------------
Product                 Price
-----------------------------------
Keyboard               299.95
Mouse                  149.50
Monitor               1899.00
-----------------------------------
```

Prøv at bruge:

```text
%-20s
%10.2f
```

---

# 🎯 Mini Assignment

## Student Registration System

Lav et lille C-program, som indsamler eller gemmer følgende oplysninger:

```text
Student Name
Age
Grade
Average Score
```

Programmet skal derefter vise:

```text
========================================
          STUDENT REGISTRATION
========================================
Name:           Sara Jensen
Age:            23
Grade:          A
Average Score:  9.45
========================================
```

## Krav

Brug mindst disse format specifiers:

```text
%s
%d
%c
%.2f
```

### Ekstra udfordring

Vis også:

```text
Student ID
Course
Completion Percentage
```

Eksempel:

```text
Student ID:     1024
Course:         C Programming
Completion:     75%
```

Husk:

```c
%%
```

for at udskrive et procenttegn.

---

# 🎓 Learning Goals

Efter denne artikel bør den studerende kunne:

- forklare hvad en format specifier er
- bruge `%d` til `int`
- bruge `%f` til decimal-output
- bruge `%c` til ét tegn
- bruge `%s` til tekst
- bruge `%u`, `%ld` og `%lld`
- bruge `%x` og `%o`
- forstå forskellen på `%f` og `%lf` ved input
- formatere decimaler med eksempelvis `%.2f`
- bruge feltbredde som `%10.2f`
- venstrejustere tekst med `%-15s`
- udskrive `%` med `%%`
- bruge `%zu` sammen med `sizeof()`
- vælge den korrekte format specifier til en datatype

---

# 🔄 Læringsrækkefølge

```text
Variables
   │
   ▼
Data Types
   │
   ▼
Format Specifiers
   │
   ├── %d  → int
   ├── %f  → decimal
   ├── %c  → char
   └── %s  → string
   │
   ▼
printf()
   │
   ▼
scanf_s()
   │
   ▼
Width + Precision
   │
   ▼
Formatted Console Applications
```

---

# ✅ Opsummering

Format specifiers er en vigtig del af C-programmering.

De fortæller `printf()` og `scanf()` hvilken type data der arbejdes med.

De vigtigste for begyndere er:

```text
%d     → int
%f     → decimal / floating-point output
%c     → char
%s     → string
%u     → unsigned int
%ld    → long
%lld   → long long
%x     → hexadecimal
%o     → octal
%p     → pointer
%zu    → size_t
%%     → procenttegn
```

Til decimalformatering:

```text
%.1f   → 1 decimal
%.2f   → 2 decimaler
%.3f   → 3 decimaler
```

Eksempel:

```c
#include <stdio.h>

int main(void)
{
    char name[] = "Zuhair";
    int age = 25;
    char grade = 'A';
    double average = 9.456;

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Grade: %c\n", grade);
    printf("Average: %.2f\n", average);

    return 0;
}
```

Output:

```text
Name: Zuhair
Age: 25
Grade: A
Average: 9.46
```

---

# 🏁 Konklusion

Når du forstår format specifiers, bliver det meget lettere at arbejde med:

- brugerinput
- variabler
- beregninger
- tabeller
- rapporter
- studentinformation
- produktdata
- temperaturer
- priser
- simple terminalprogrammer

En god huskeregel er:

```text
Datatype first
      │
      ▼
Choose correct format specifier
      │
      ▼
Use printf() or scanf_s()
      │
      ▼
Correct Input / Output
```

---

**Happy Coding! 🚀💻**
