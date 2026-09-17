# `strcspn()` i C-sprog

## Introduktion

`strcspn()` er en funktion i C, som bruges til at finde **positionen af det første tegn i en tekst, som matcher et af tegnene i en anden tekst**.

Funktionen findes i biblioteket:

```c
#include <string.h>
```

---

## Syntax

```c
size_t strcspn(const char *str, const char *reject);
```

Navnet kan huskes som:

> **strcspn = String Complement Span**

Funktionen tæller tegn fra begyndelsen af `str`, indtil den finder et tegn, som også findes i `reject`.

---

# Simpelt eksempel

```c
#include <stdio.h>
#include <string.h>

int main() {

    char tekst[] = "Hello,World";

    size_t position = strcspn(tekst, ",");

    printf("Komma findes på position: %zu\n", position);

    return 0;
}
```

Output:

```text
Komma findes på position: 5
```

Teksten kan visualiseres sådan:

```text
H  e  l  l  o  ,  W  o  r  l  d
0  1  2  3  4  5  6  7  8  9  10
               ↑
             komma
```

Derfor returnerer:

```c
strcspn(tekst, ",")
```

værdien:

```text
5
```

---

# `strcspn()` sammen med `fgets()`

En af de mest almindelige anvendelser af `strcspn()` er sammen med `fgets()`.

Når brugeren skriver tekst og trykker **Enter**, kan `fgets()` gemme newline-tegnet:

```text
\n
```

Eksempel:

```c
#include <stdio.h>
#include <string.h>

int main() {

    char navn[50];

    printf("Indtast dit navn: ");

    fgets(navn, sizeof(navn), stdin);

    printf("Hej %s", navn);

    return 0;
}
```

Hvis brugeren skriver:

```text
Zuhair
```

kan arrayet indeholde:

```text
Z u h a i r \n \0
```

Visualisering:

```text
Index:   0   1   2   3   4   5    6    7

Data:    Z   u   h   a   i   r   \n   \0
                              ↑
                         Enter/newline
```

---

# Fjern `\n` med `strcspn()`

Vi kan bruge:

```c
strcspn(navn, "\n")
```

til at finde positionen af `\n`.

Eksempel:

```c
#include <stdio.h>
#include <string.h>

int main() {

    char navn[50];

    printf("Indtast dit navn: ");

    fgets(navn, sizeof(navn), stdin);

    // Find newline og erstat den med null-terminator
    navn[strcspn(navn, "\n")] = '\0';

    printf("Hej %s!\n", navn);

    return 0;
}
```

---

# Hvordan virker denne linje?

```c
navn[strcspn(navn, "\n")] = '\0';
```

Lad os dele den op i trin.

## Trin 1 – Brugeren skriver

```text
Zuhair
```

Efter `fgets()` kan arrayet se sådan ud:

```text
Z u h a i r \n \0
0 1 2 3 4 5  6   7
```

---

## Trin 2 – `strcspn()` finder `\n`

```c
strcspn(navn, "\n")
```

returnerer:

```text
6
```

fordi `\n` ligger på index `6`.

---

## Trin 3 – Index bruges i arrayet

Resultatet bliver derfor:

```c
navn[6] = '\0';
```

---

## Trin 4 – `\n` erstattes

Før:

```text
Z u h a i r \n \0
0 1 2 3 4 5  6   7
```

Efter:

```text
Z u h a i r \0
0 1 2 3 4 5  6
```

Nu slutter C-strengen efter `Zuhair`.

---

# Før og efter

### Før

```text
fgets()
   │
   ▼
"Zuhair\n"
```

### `strcspn()`

```text
strcspn(navn, "\n")
        │
        ▼
      index 6
```

### Erstatning

```text
navn[6] = '\0'
```

### Efter

```text
"Zuhair"
```

---

# Flere tegn kan søges

`strcspn()` kan også søge efter flere forskellige tegn.

Eksempel:

```c
char tekst[] = "Hello,World!";

size_t position = strcspn(tekst, ",!");
```

Her leder funktionen efter det første:

```text
,
eller
!
```

Da kommaet kommer først, returneres dets position.

---

# Komplet eksempel

```c
#include <stdio.h>
#include <string.h>

int main() {

    char navn[50];
    int alder;

    printf("Indtast dit navn: ");

    // Læs en hel tekstlinje
    fgets(navn, sizeof(navn), stdin);

    // Fjern newline fra fgets()
    navn[strcspn(navn, "\n")] = '\0';

    printf("Indtast din alder: ");
    scanf("%d", &alder);

    printf("\n--- Bruger information ---\n");

    printf("Navn: %s\n", navn);
    printf("Alder: %d\n", alder);

    return 0;
}
```

Eksempel på output:

```text
Indtast dit navn: Zuhair
Indtast din alder: 35

--- Bruger information ---
Navn: Zuhair
Alder: 35
```

---

# Kort opsummering

| Funktion     | Formål                              |
| ------------ | ----------------------------------- |
| `fgets()`    | Læser en tekstlinje                 |
| `strcspn()`  | Finder positionen af bestemte tegn  |
| `"\n"`       | Newline/Enter                       |
| `'\0'`       | Markerer slutningen på en C-string  |
| `<string.h>` | Biblioteket hvor `strcspn()` findes |

Den mest almindelige kombination er:

```c
fgets(navn, sizeof(navn), stdin);

navn[strcspn(navn, "\n")] = '\0';
```

Flowet er:

```text
Bruger indtaster tekst
        │
        ▼
      fgets()
        │
        ▼
"Zuhair\n"
        │
        ▼
strcspn(navn, "\n")
        │
        ▼
Find positionen af \n
        │
        ▼
Erstat \n med \0
        │
        ▼
    "Zuhair"
```

**Huskeregel:**

> `fgets()` læser teksten → `strcspn()` finder `\n` → `'\0'` afslutter strengen.
