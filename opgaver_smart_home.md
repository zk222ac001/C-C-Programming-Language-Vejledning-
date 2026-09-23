# Opgave: Smart Home-styring i C

Du skal udvikle et C-program, der simulerer styringen af lys og varme i et hjem. Brugeren indtaster en tast og trykker **Enter** for at vælge en handling.

## Menu

| Tast | Handling |
|---|---|
| **L** | Tænd eller sluk lyset |
| **V** | Tænd eller sluk varmen |
| **S** | Vis status for lys og varme |
| **Q** | Afslut programmet |

## Sådan skal du bygge programmet

- Brug `<stdio.h>` til input og output.
- Gem brugerens valg i en `char`-variabel.
- Læs valget med `scanf_s()` i Visual Studio på Windows:

```c
char valg;
scanf_s(" %c", &valg, (unsigned)sizeof(valg));
```

Mellemrummet foran `%c` springer tidligere linjeskift over. Indtast ét bogstav ad gangen, og tryk Enter.

- Opret to `int`-variabler: `lys` og `varme`. Brug `0` for slukket og `1` for tændt. Begge skal starte som slukket.
- Brug `switch-case` til at håndtere brugerens valg. Accepter både store og små bogstaver.
- Brug `if-else` til at skifte mellem tændt og slukket.
- Brug `default` til at vise **“Ugyldigt valg!”**.
- Brug en løkke, så programmet fortsætter, indtil brugeren vælger **Q** eller **q**.

## Eksempel

Brugeren indtaster **L** og trykker Enter. Lyset tændes. Når brugeren vælger **L** igen, slukkes lyset. Programmet skal vise den nye tilstand efter hvert valg.

Ved **S** skal programmet vise status for både lys og varme.

## Test

Indtast `L`, `V`, `L`, `S`, `9` og `Q`, og tryk Enter efter hvert valg. Kontrollér, at status viser slukket lys og tændt varme, at `9` giver en fejlbesked, og at `Q` afslutter programmet.

## Aflevering

Aflever din `.c`-fil med korte kommentarer, der forklarer din `switch-case`.
