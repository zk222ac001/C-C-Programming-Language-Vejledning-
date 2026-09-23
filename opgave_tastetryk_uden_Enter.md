# Opgave: Styr en spiller med tastaturet i C

Lav et C-program, der simulerer styring af en spiller. Programmet skal reagere på tastetryk **uden Enter**.

## Læringsmål

Du skal øve tastaturinput med `_getch()`, betingelser med `if-else` og gentagelse med en løkke.

## Krav til programmet

1. Vis en vejledning med de tilgængelige taster.
2. Brug `_getch()` fra `<conio.h>` til at læse tastetryk.
3. Brug `if`, `else if` og `else` til følgende handlinger:

| Tast | Besked |
|---|---|
| W | Spilleren går frem |
| S | Spilleren går tilbage |
| A | Spilleren går til venstre |
| D | Spilleren går til højre |
| Q | Spillet afsluttes |
| Andre taster | Ukendt tast |

4. Accepter både små og store bogstaver.
5. Fortsæt med at læse tastetryk, indtil brugeren trykker **Q**.

## Test

Afprøv alle retninger, et stort bogstav, en ugyldig tast og afslutning med Q.

## Ekstra udfordring

Tæl spillerens bevægelser, og vis antallet, når spillet afsluttes.

## Aflevering

Aflever din fil `game_control.c` og en kort forklaring af forskellen mellem `scanf_s()` og `_getch()`.

*Brug Visual Studio på Windows til denne opgave.*
