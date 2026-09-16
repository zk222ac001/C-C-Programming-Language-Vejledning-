# Personoplysninger i C

Dette program beder brugeren om at indtaste:

- Navn
- Alder
- Højde
- Vægt
- Køn

Programmet kontrollerer, om talværdierne er indtastet korrekt, og udskriver derefter oplysningerne.

## Kode

```cpp
#include <stdio.h>
#include <string.h>

int main() {

    // Trin 1: Opret variabler
    char navn[50];
    int alder;
    float hoejde;
    double vaegt;
    char koen;

    // Trin 2: Læs navn
    printf("Indtast dit navn: ");
    fgets(navn, sizeof(navn), stdin);

    // Fjern linjeskiftet fra navnet
    navn[strcspn(navn, "\n")] = '\0';

    // Trin 3: Læs alder
    printf("Indtast din alder: ");

    if (scanf_s("%d", &alder) != 1) {
        printf("Fejl: Alderen skal være et helt tal.\n");
        return 1;
    }

    // Trin 4: Læs højde
    printf("Indtast din højde i meter, f.eks. 1.85: ");

    if (scanf_s("%f", &hoejde) != 1) {
        printf("Fejl: Højden skal være et tal med punktum.\n");
        return 1;
    }

    // Trin 5: Læs vægt
    printf("Indtast din vægt i kg, f.eks. 75.5: ");

    if (scanf_s("%lf", &vaegt) != 1) {
        printf("Fejl: Vægten skal være et tal med punktum.\n");
        return 1;
    }

    // Trin 6: Læs køn
    printf("Indtast dit køn (M/K): ");

    if (scanf_s(" %c", &koen, (unsigned)sizeof(koen)) != 1) {
        printf("Fejl: Du skal indtaste ét tegn.\n");
        return 1;
    }

    // Trin 7: Udskriv oplysninger
    printf("\n--- Dine oplysninger ---\n");
    printf("Mit navn er %s\n", navn);
    printf("Min alder er %d år\n", alder);
    printf("Min højde er %.2f meter\n", hoejde);
    printf("Min vægt er %.2f kg\n", vaegt);
    printf("Mit køn er %c\n", koen);

    return 0;
}
```

## Formatkoder

| Formatkode | Datatype | Eksempel |
|---|---|---|
| `%s` | Tekst (`char[]`) | Navn |
| `%d` | Heltal (`int`) | Alder |
| `%f` | Decimaltal (`float`) | Højde |
| `%lf` | Decimaltal (`double`) | Vægt |
| `%c` | Enkelt tegn (`char`) | Køn |

## Bemærkninger

- Brug punktum i decimaltal, eksempelvis `1.85`.
- `fgets()` gør det muligt at indtaste navne med mellemrum.
- Mellemrummet i `" %c"` ignorerer tidligere linjeskift.
- Programmet anvender `scanf_s()`, som understøttes af Visual Studio.
