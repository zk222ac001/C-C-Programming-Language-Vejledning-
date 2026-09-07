# 🚀 Escape Characters i C

> En praktisk og begyndervenlig artikel om escape characters i C-programmering med forklaringer, eksempler, demo-programmer og øvelser.

---

## 📚 Indhold

1. Introduktion
2. Hvad er et Escape Character?
3. Oversigt over vigtige Escape Characters
4. Demo 1 – New Line med `\n`
5. Demo 2 – Tabulator med `\t`
6. Demo 3 – Citationstegn med `\"`
7. Demo 4 – Backslash med `\\`
8. Demo 5 – Kombination af Escape Characters
9. Bonus – Alert med `\a`
10. Typiske fejl
11. Cheat Sheet
12. Øvelser
13. Opsummering

---

# 🌟 Introduktion

Når vi arbejder med tekst i C, bruger vi ofte funktionen:

```c
printf();
```

Eksempel:

```c
printf("Hello World");
```

Output:

```text
Hello World
```

Men nogle gange ønsker vi mere kontrol over teksten. Vi vil måske:

- gå til en ny linje
- lave tabulatorafstand
- skrive citationstegn inde i en tekst
- vise en backslash
- lave et alarmsignal
- formatere output som en lille tabel

Her kommer **Escape Characters** ind i billedet.

---

# 🔤 Hvad er et Escape Character?

Et escape character er en speciel tegnsekvens i C. Den starter normalt med en backslash:

```text
\
```

Eksempel:

```c
\n
```

`\n` betyder:

> Gå til en ny linje.

Når C ser:

```c
printf("Hello\nWorld");
```

tolker C ikke `\n` som almindelig tekst. I stedet bliver output:

```text
Hello
World
```

---

# 📋 Oversigt over vigtige Escape Characters

| Escape Character | Navn | Funktion |
|---|---|---|
| `\n` | New Line | Flytter markøren til næste linje |
| `\t` | Horizontal Tab | Laver tabulatorafstand |
| `\"` | Double Quote | Skriver `"` inde i tekst |
| `\'` | Single Quote | Skriver `'` |
| `\\` | Backslash | Skriver en backslash |
| `\a` | Alert | Forsøger at lave et bip |
| `\b` | Backspace | Flytter én position tilbage |
| `\r` | Carriage Return | Flytter markøren til begyndelsen af linjen |
| `\0` | Null Character | Marker slutningen af en C-string |

---

# 🧪 Demo 1 – New Line med `\n`

## Formål

Denne demo viser, hvordan vi bruger `\n` til at gå til en ny linje.

```c
#include <stdio.h>

int main(void)
{
    printf("Welcome to C Programming!\n");
    printf("Today we learn Escape Characters.\n");
    printf("Happy Coding!\n");

    return 0;
}
```

### Output

```text
Welcome to C Programming!
Today we learn Escape Characters.
Happy Coding!
```

### Forklaring

Når C møder `\n`, flyttes output til næste linje.

```text
Welcome to C Programming!
             │
             ▼
            \n
             │
             ▼
Today we learn Escape Characters.
```

---

# 🧪 Demo 2 – Tabulator med `\t`

`\t` bruges til at lave tabulatorafstand mellem værdier.

```c
#include <stdio.h>

int main(void)
{
    printf("Name\tAge\tCity\n");
    printf("Ali\t22\tNastved\n");
    printf("Sara\t25\tRoskilde\n");
    printf("Anna\t21\tKoge\n");

    return 0;
}
```

### Output

```text
Name    Age     City
Ali     22      Nastved
Sara    25      Roskilde
Anna    21      Koge
```

### Forklaring

```text
Name
 │
 ▼
\t
 │
 ▼
Age
 │
 ▼
\t
 │
 ▼
City
 │
 ▼
\n
```

> `\t` er fint til simple tabeller. Til mere præcis kolonnejustering kan man senere lære feltbredder i `printf()`.

---

# 🧪 Demo 3 – Citationstegn med `\"`

C bruger dobbelt citationstegn til at markere tekst:

```c
printf("Hello");
```

Hvis vi vil skrive citationstegn **inde i teksten**, bruger vi `\"`.

```c
#include <stdio.h>

int main(void)
{
    printf("My teacher said: \"Practice C every day!\"\n");

    return 0;
}
```

### Output

```text
My teacher said: "Practice C every day!"
```

### Visualisering

```text
Code:
\"Hello\"

   ↓

Output:
"Hello"
```

---

# 🧪 Demo 4 – Backslash med `\\`

Backslash har en særlig betydning i C, fordi den bruges til escape characters.

Hvis vi vil vise én rigtig backslash:

```text
\
```

skal vi skrive:

```c
\\
```

### Program

```c
#include <stdio.h>

int main(void)
{
    printf("My project is located here:\n");
    printf("C:\\Users\\Student\\Documents\\CProgramming\n");

    return 0;
}
```

### Output

```text
My project is located here:
C:\Users\Student\Documents\CProgramming
```

### Forklaring

```text
C Code              Output

\\          →          \
```

Windows-stier skrives derfor ofte sådan i C:

```c
"C:\\Users\\Student\\Documents"
```

---

# 🧪 Demo 5 – Kombination af Escape Characters

Nu kombinerer vi:

- `\n`
- `\t`
- `\"`
- `\\`

i ét program.

```c
#include <stdio.h>

int main(void)
{
    printf("====================================\n");
    printf("\tSTUDENT INFORMATION\n");
    printf("====================================\n");

    printf("Name:\t\tZuhair\n");
    printf("Course:\t\tC Programming\n");
    printf("Message:\t\"Welcome to Programming!\"\n");
    printf("Folder:\t\tC:\\CProgramming\\Projects\n");

    printf("====================================\n");

    return 0;
}
```

### Output

```text
====================================
        STUDENT INFORMATION
====================================
Name:           Zuhair
Course:         C Programming
Message:        "Welcome to Programming!"
Folder:         C:\CProgramming\Projects
====================================
```

### Programflow

```text
┌─────────────────────────┐
│          START          │
└────────────┬────────────┘
             │
             ▼
        Print Header
             │
             ▼
      Use \t for tabs
             │
             ▼
      Use \" for quotes
             │
             ▼
      Use \\ for path
             │
             ▼
      Use \n for lines
             │
             ▼
        Print Footer
             │
             ▼
┌─────────────────────────┐
│           END           │
└─────────────────────────┘
```

---

# 🔔 Bonus – Alert med `\a`

`\a` betyder **Alert**.

```c
#include <stdio.h>

int main(void)
{
    printf("Warning!\a\n");
    printf("An error has occurred.\n");

    return 0;
}
```

På nogle computere kan terminalen lave et lille bip. På moderne terminaler er lyden dog ofte deaktiveret.

---

# 🧠 Samlet konceptdiagram

```text
                 ESCAPE CHARACTERS
                        │
        ┌───────────────┼────────────────┐
        │               │                │
        ▼               ▼                ▼
       \n              \t               \"
    New Line           Tab             Quote
        │               │                │
        └───────────────┼────────────────┘
                        │
             ┌──────────┴──────────┐
             │                     │
             ▼                     ▼
            \\                    \a
         Backslash               Alert
             │                     │
             └──────────┬──────────┘
                        │
                        ▼
                  Formatted Output
```

---

# ⚠️ Typiske fejl

## Fejl 1 – Bruge `/n` i stedet for `\n`

Forkert:

```c
printf("Hello/nWorld");
```

Korrekt:

```c
printf("Hello\nWorld");
```

---

## Fejl 2 – Glemme escape foran citationstegn

Forkert:

```c
printf("He said "Hello"");
```

Korrekt:

```c
printf("He said \"Hello\"");
```

---

## Fejl 3 – Skrive Windows-sti direkte

Problem:

```c
printf("C:\Users\Student");
```

I C kan dele af stien blive fortolket som escape-sekvenser.

Korrekt C-kode:

```c
printf("C:\\Users\\Student");
```

---

# 📌 Escape Character Cheat Sheet

```c
// New line
printf("Hello\nWorld");

// Tab
printf("Name\tAge");

// Double quotation mark
printf("\"Hello\"");

// Single quotation mark
printf("\'A\'");

// Backslash
printf("C:\\Users\\Student");

// Alert
printf("\a");

// Backspace
printf("\b");

// Carriage Return
printf("\r");
```

---

# 📝 Øvelse 1 – Personligt ID-kort

Lav et C-program, der viser:

```text
==============================
        STUDENT CARD
==============================
Name:       Anna Jensen
Course:     IT Technology
Semester:   1
==============================
```

Brug mindst:

```text
\n
\t
```

---

# 📝 Øvelse 2 – Citat

Lav et program, som viser:

```text
Teacher said: "Programming is learned by practice."
```

Du skal bruge:

```c
\"
```

---

# 📝 Øvelse 3 – Windows-filplacering

Lav et program, som viser:

```text
C:\Students\Projects\MyProgram
```

Brug:

```c
\\
```

---

# 📝 Øvelse 4 – Restaurant Menu

Lav et program med dette output:

```text
================================
          FOOD MENU
================================
Burger      80 DKK
Pizza       90 DKK
Salad       65 DKK
================================
```

Brug `\n` og `\t`.

---

# 📝 Øvelse 5 – Mini profil

Lav et program, som viser:

```text
====================================
            USER PROFILE
====================================
Name:       Ali Khan
Course:     "C Programming"
Folder:     C:\Programming\CProjects
====================================
```

Programmet skal bruge mindst:

```text
\n
\t
\"
\\
```

---

# 🎯 Mini Assignment – Escape Character Challenge

Design et terminalbaseret **Student Registration Card**.

Eksempel på ønsket output:

```text
========================================
          STUDENT REGISTRATION
========================================

Name:           Sara Jensen
Programme:      "IT Technology"
Semester:       1
Project Folder: C:\Students\CProjects

========================================
          Registration Complete
========================================
```

## Krav

Du skal bruge mindst:

- `\n`
- `\t`
- `\"`
- `\\`

---

# 🔄 Læringsrækkefølge

```text
printf()
   │
   ▼
Simple Text Output
   │
   ▼
\n New Line
   │
   ▼
\t Tab
   │
   ▼
\" Quotes
   │
   ▼
\\ Backslash
   │
   ▼
Combine Escape Characters
   │
   ▼
Formatted Console Programs
```

---

# ✅ Opsummering

Escape characters bruges til at kontrollere og formatere tekst i C.

De vigtigste for begyndere er:

```text
\n   → New Line
\t   → Tab
\"   → Double Quote
\\   → Backslash
\a   → Alert
```

Et samlet eksempel:

```c
#include <stdio.h>

int main(void)
{
    printf("Name:\tZuhair\n");
    printf("Course:\t\"C Programming\"\n");
    printf("Folder:\tC:\\Programming\\Projects\n");

    return 0;
}
```

Output:

```text
Name:   Zuhair
Course: "C Programming"
Folder: C:\Programming\Projects
```

---

# 🏁 Konklusion

Escape characters er et lille, men meget vigtigt emne i C-programmering.

Når man forstår `\n`, `\t`, `\"` og `\\`, bliver det meget lettere at skabe:

- pænt terminaloutput
- tabeller
- studentkort
- menuer
- rapporter
- filstier
- beskeder
- simple tekstbaserede brugergrænseflader

---

## 👨‍💻 Learning Goals

Efter denne artikel bør den studerende kunne:

- definere begrebet escape character
- forklare hvorfor backslash bruges i C
- bruge `\n` til nye linjer
- bruge `\t` til tabulatorafstand
- bruge `\"` til citationstegn
- bruge `\\` til backslash
- kende formålet med `\a`, `\b` og `\r`
- kombinere escape characters i `printf()`
- identificere typiske fejl i escape-sekvenser
- designe et simpelt formateret terminalprogram

---

**Happy Coding! 🚀💻**
