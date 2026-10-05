#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(void)
{
    int tast = 0;
    int bevaegelser = 0;

    SetConsoleOutputCP(CP_UTF8);

    printf("=== Styr spilleren ===\n");
    printf("Danske bogstaver: æ ø å Æ Ø Å\n");
    printf("W: Frem\n");
    printf("S: Tilbage\n");
    printf("A: Venstre\n");
    printf("D: Højre\n");
    printf("Q: Afslut\n");
    printf("Brug små eller store bogstaver uden Enter.\n\n");

    // Sentinelstyret løkke: q eller Q stopper løkken.
    while (tast != 'q' && tast != 'Q')
    {
        tast = _getch();

        switch (tast)
        {
        case 'w':
        case 'W':
            printf("Spilleren går frem\n");
            bevaegelser++;
            break;

        case 's':
        case 'S':
            printf("Spilleren går tilbage\n");
            bevaegelser++;
            break;

        case 'a':
        case 'A':
            printf("Spilleren går til venstre\n");
            bevaegelser++;
            break;

        case 'd':
        case 'D':
            printf("Spilleren går til højre\n");
            bevaegelser++;
            break;

        case 'q':
        case 'Q':
            printf("Spillet afsluttes\n");
            break;

            // Specialtaster, fx piletaster (arrow keys, giver to koder.
        case 0:
        case 224:
            _getch(); // Læs og ignorer den anden kode.
            printf("Ukendt tast\n");
            break;

        default:
            printf("Ukendt tast\n");
            break;
        }
    }

    printf("Antal bevægelser: %d\n", bevaegelser);

    return 0;
}
