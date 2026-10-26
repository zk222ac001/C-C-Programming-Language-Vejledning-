# Pointere i C

## Hvad er en pointer?

En pointer er en variabel, der gemmer **hukommelsesadressen** på en anden variabel. En almindelig variabel gemmer en værdi, mens en pointer gemmer stedet, hvor værdien findes.

```c
int alder = 20;
int *peger = &alder;
```

Her betyder `&alder` adressen på variablen `alder`. Pointeren `peger` gemmer denne adresse. Tegnet `*` i `int *peger` angiver, at `peger` er en pointer til en `int`.

Når vi skriver `*peger` i et udtryk, følger vi adressen og får adgang til værdien dér. Det kaldes at dereferere pointeren.

```c
printf("%d\n", *peger);  // Udskriver 20
```

## Hvorfor er pointere vigtige?

Pointere giver C-programmer direkte adgang til data i hukommelsen. Det er vigtigt, når et program skal ændre data gennem funktioner, arbejde med arrays og tekststrenge, reservere hukommelse under kørslen eller bygge datastrukturer som sammenkædede lister og træer.

## Hvordan ændrer en funktion en variabel med en pointer?

Normalt får en funktion en kopi af den værdi, der sendes til den. Hvis funktionen skal ændre den oprindelige variabel, kan vi sende dens adresse:

```c
#include <stdio.h>

void laeg_en_til(int *tal) {
    *tal = *tal + 1;
}

int main(void) {
    int antal = 4;
    laeg_en_til(&antal);

    printf("%d\n", antal);  // Udskriver 5
    return 0;
}
```

Kaldet `laeg_en_til(&antal)` sender adressen på `antal`. Inde i funktionen ændrer `*tal` værdien på den adresse, så den oprindelige variabel bliver ændret.

## Fordele ved pointere

- **Ændring gennem funktioner:** En funktion kan ændre den oprindelige variabel.
- **Mindre kopiering:** Store data kan deles ved at sende en adresse i stedet for at kopiere hele dataene.
- **Dynamisk hukommelse:** Funktioner som `malloc` kan reservere hukommelse, mens programmet kører.
- **Fleksible datastrukturer:** Pointere forbinder elementer i blandt andet lister og træer.

## Vær forsigtig med pointere

En pointer skal pege på en gyldig adresse, før programmet bruger den. En ikke-initialiseret pointer eller en pointer til hukommelse, der allerede er frigivet, kan føre til fejl. Brug `NULL`, når en pointer endnu ikke peger på et objekt, og kontrollér den før dereferering.

```c
int *peger = NULL;

if (peger != NULL) {
    printf("%d\n", *peger);
}
```

## Kort opsummering

En variabel gemmer en værdi; en pointer gemmer adressen på en værdi. Pointere er centrale i C, fordi de gør det muligt at få effektiv og fleksibel adgang til hukommelsen. De kræver samtidig omhyggelig brug, så programmet kun læser og ændrer gyldige adresser.
