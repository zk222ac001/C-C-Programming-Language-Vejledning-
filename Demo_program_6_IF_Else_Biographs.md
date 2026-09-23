# Demo: If-else i C – Billetpris i en biograf

Dette demoprogram bestemmer billetprisen ud fra brugerens alder. Det viser, hvordan `if`, `else if` og `else` bruges til at træffe beslutninger.

## Billetpriser

| Alder | Billetpris |
|-------|------------|
| Under 0 | Ugyldig alder |
| 0–11 år | 50 kr. |
| 12–17 år | 80 kr. |
| 18–64 år | 120 kr. |
| 65 år og derover | 70 kr. |

## C-program til Visual Studio Community

```c
#include <stdio.h>

int main(void) {
    int alder;

    printf("=== Biografens billetpris ===\n");
    printf("Indtast din alder: ");

    // Kontroller, at der kan laeses et helt tal.
    if (scanf_s("%d", &alder) != 1) {
        printf("Fejl: Du skal indtaste et helt tal.\n");
        return 1;
    }

    // Betingelserne kontrolleres oppefra og ned.
    if (alder < 0) {
        printf("Fejl: Alderen kan ikke vaere negativ.\n");
    }
    else if (alder < 12) {
        printf("Boernebillet: 50 kr.\n");
    }
    else if (alder < 18) {
        printf("Ungdomsbillet: 80 kr.\n");
    }
    else if (alder < 65) {
        printf("Voksenbillet: 120 kr.\n");
    }
    else {
        printf("Seniorbillet: 70 kr.\n");
    }

    return 0;
}
```

> Bruger du GCC, kan du erstatte `scanf_s` med `scanf` i dette program.

## Forklaring til undervisningen

- **`if`** undersøger den første betingelse.
- **`else if`** undersøger en ny betingelse, hvis de tidligere var falske.
- **`else`** køres, hvis ingen af de tidligere betingelser var sande.
- Kun **én gren** i den sammenhængende kæde udføres.

### Eksempel: Brugeren indtaster 15

1. `alder < 0` er falsk.
2. `alder < 12` er falsk.
3. `alder < 18` er sand.
4. Programmet viser **Ungdomsbillet: 80 kr.** og springer resten af kæden over.

Vi behøver ikke skrive `alder >= 12 && alder < 18`. Når programmet når denne gren, ved vi allerede, at alderen ikke er under 12.

### Indlæsning af alder

`scanf_s("%d", &alder)` forsøger at læse et helt tal og gemme det i variablen `alder`. Returværdien er `1`, når ét tal er blevet læst. Ellers viser programmet en fejl og afslutter med `return 1`.

Bemærk: Denne enkle kontrol validerer ikke hele inputlinjen. Input som `15abc` kan stadig blive læst som tallet `15`.

## Øvelse til de studerende

1. Test med alderen `-1`, `11`, `12`, `17`, `18`, `64` og `65`.
2. Tilføj gratis adgang for børn under 3 år.
3. Forklar, hvorfor betingelsernes rækkefølge betyder noget.

## Forventede testresultater

| Input | Forventet resultat |
|-------|--------------------|
| -1 | Fejl: Alderen kan ikke være negativ |
| 11 | Børnebillet: 50 kr. |
| 12 | Ungdomsbillet: 80 kr. |
| 17 | Ungdomsbillet: 80 kr. |
| 18 | Voksenbillet: 120 kr. |
| 64 | Voksenbillet: 120 kr. |
| 65 | Seniorbillet: 70 kr. |
