# Input-validering med `scanf_s()` i C

## Koden

```c
if (scanf_s("%d", &alder) != 1) {
    printf("Fejl: Alderen skal være et helt tal.\n");
    return 1;
}
```

## Hvad gør koden?

Denne kode bruges til at kontrollere, om brugeren har indtastet et **gyldigt helt tal**.

---

## 1. `scanf_s("%d", &alder)`

```c
scanf_s("%d", &alder)
```

`scanf_s()` forsøger at læse brugerens input.

Her betyder:

* `%d` → læs et helt tal (`int`)
* `&alder` → adressen på variablen `alder`
* Den indtastede værdi gemmes i `alder`

Eksempel:

```text
Indtast din alder: 35
```

Så bliver:

```c
alder = 35;
```

---

## 2. Hvad returnerer `scanf_s()`?

`scanf_s()` returnerer antallet af værdier, som blev læst korrekt.

Hvis brugeren skriver:

```text
35
```

returnerer:

```c
scanf_s("%d", &alder)
```

værdien:

```text
1
```

fordi **én værdi** blev læst korrekt.

---

## 3. Hvad betyder `!= 1`?

Operatoren:

```c
!=
```

betyder:

```text
ikke lig med
```

Derfor betyder:

```c
scanf_s("%d", &alder) != 1
```

> Hvis `scanf_s()` ikke kunne læse præcis én gyldig værdi.

---

## Eksempel med korrekt input

Brugeren skriver:

```text
25
```

`scanf_s()` returnerer:

```text
1
```

Betingelsen bliver:

```c
if (1 != 1)
```

Dette er:

```text
FALSE
```

Programmet fortsætter derfor normalt.

---

## Eksempel med forkert input

Brugeren skriver:

```text
abc
```

`abc` kan ikke konverteres til et helt tal.

`scanf_s()` returnerer derfor typisk:

```text
0
```

Betingelsen bliver:

```c
if (0 != 1)
```

Dette er:

```text
TRUE
```

Programmet går derfor ind i `if`-blokken.

---

## 4. Vis fejlbesked

```c
printf("Fejl: Alderen skal være et helt tal.\n");
```

Brugeren får:

```text
Fejl: Alderen skal være et helt tal.
```

---

## 5. `return 1`

```c
return 1;
```

Dette stopper programmet.

Som en almindelig konvention betyder:

```c
return 0;
```

at programmet sluttede normalt.

Mens:

```c
return 1;
```

angiver, at programmet sluttede med en fejlstatus.

---

## Flowdiagram

```text
Bruger indtaster alder
        |
        v
scanf_s("%d", &alder)
        |
        v
Kunne scanf_s læse et helt tal?
       / \
      /   \
    JA     NEJ
    |       |
    v       v
Returnerer 1   Returnerer 0
    |             |
    v             v
Fortsæt       Vis fejlbesked
programmet        |
                  v
              return 1
                  |
                  v
             Stop programmet
```

---

## Kommenteret kode

```c
// Forsøg at læse et helt tal fra brugeren
if (scanf_s("%d", &alder) != 1) {

    // Hvis input ikke er et gyldigt helt tal
    printf("Fejl: Alderen skal være et helt tal.\n");

    // Stop programmet med fejlstatus
    return 1;
}
```

## Kort opsummering

| Kode        | Betydning                                       |
| ----------- | ----------------------------------------------- |
| `scanf_s()` | Læser input fra brugeren                        |
| `%d`        | Forventer et helt tal                           |
| `&alder`    | Adressen på variablen `alder`                   |
| `!=`        | Ikke lig med                                    |
| `!= 1`      | Kontrollerer om én værdi ikke blev læst korrekt |
| `printf()`  | Viser fejlbeskeden                              |
| `return 1`  | Stopper programmet med fejlstatus               |

### Huskeregel

```text
scanf_s()
    |
    v
Læs input
    |
    v
Returnerer 1?
  /       \
JA         NEJ
|           |
OK         FEJL
|           |
v           v
Fortsæt   return 1
```
