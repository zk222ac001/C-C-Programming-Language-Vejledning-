# Opgave: Game Control i C

Du skal udvikle et simpelt C-program, der simulerer tastaturstyring i et spil. Spilleren indtaster en tast, og programmet viser den tilhørende bevægelsesretning.

## Læringsmål

Du skal øve dig i at:

- Læse et tegn fra tastaturet.
- Gemme et tegn i en variabel af typen `char`.
- Anvende `switch-case` til at vælge mellem forskellige handlinger.
- Håndtere ugyldigt input med `default`.

## Opgavebeskrivelse

Programmet skal bede spilleren om at indtaste én af følgende taster:

| Tast | Bevægelse | Tekst, programmet skal vise |
|------|-----------|----------------------------|
| w | Op | Up |
| s | Ned | Down |
| a | Venstre | Left |
| d | Højre | Right |

Hvis spilleren indtaster en anden tast, skal programmet vise **Wrong**.

## Krav til programmet

1. Vis en kort vejledning med de fire gyldige taster.
2. Læs ét tegn fra tastaturet, og gem det i en `char`-variabel.
3. Brug `switch-case` til at undersøge den indtastede tast.
4. Vis den korrekte retning som angivet i tabellen.
5. Brug `default` til at håndtere alle andre taster.
6. Programmet skal behandle én indtastning og derefter afslutte.

I grundopgaven accepteres kun små bogstaver. Store bogstaver skal derfor give resultatet **Wrong**.

## Test dit program

Kontrollér, at programmet giver følgende resultater:

| Input | Forventet resultat |
|-------|--------------------|
| w | Up |
| s | Down |
| a | Left |
| d | Right |
| x | Wrong |
| 5 | Wrong |
| W | Wrong |

## Refleksionsspørgsmål

- Hvorfor passer datatypen `char` til denne opgave?
- Hvad bruges `default` til?
- Hvad kan der ske, hvis du glemmer `break` efter en `case`?
- Hvordan kunne opgaven løses med `if-else`?

## Ekstra udfordring – valgfri

Udvid programmet, så både små og store bogstaver accepteres.

Eksempelvis skal både **w** og **W** give resultatet **Up**.

## Aflevering

Aflever:

- Din C-fil.
- Skærmbilleder, der viser en gyldig og en ugyldig indtastning.
- En kort forklaring på, hvordan du har brugt `switch-case` og `default`.
