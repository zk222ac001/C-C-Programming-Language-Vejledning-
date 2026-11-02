# Program 10 · this-pointer og operatoroverloading

[Oversigt](OOP_Laeringsforloeb.md) · [Forrige](Program_9_Polymorfi_og_binding.md) · [Næste: Exceptions](Program_11_Exceptions_og_RAII.md)

## this: det aktuelle objekt

Når en almindelig, ikke-statisk medlemsfunktion bliver kaldt, har den adgang til en pointer til det aktuelle objekt: `this`. Ved `a.saetX(8)` peger `this` på `a`.

```cpp
Punkt& saetX(double x) {
    this->x = x;
    return *this;
}
```

`this->x` er medlemmet, mens `x` på højre side er parameteren. Det gør forskellen tydelig, når navnene er ens. I en almindelig `Punkt`-metode har `this` typen `Punkt*`; i en const-metode er adgangen gennem `const Punkt*`. `this` er et særligt pointerudtryk, som du ikke kan ombinde ved tildeling.

`*this` betyder objektet selv. Returtypen `Punkt&` gør, at vi kan kæde kald:

```cpp
a.saetX(8).saetY(9);
```

Begge kald ændrer samme objekt. Returnér kun sådan en reference, når objektet lever længe nok til brugen. Et kald på et midlertidigt objekt kan efterlade en hængende reference, hvis du gemmer den ud over objektets levetid.

Andre anvendelser er at sende det aktuelle objekt til en hjælpefunktion eller kontrollere selvtildeling i en håndskrevet copy-assignment. Det er ikke altid nødvendigt at skrive `this->`; sproget kan normalt finde medlemsnavnene. Statiske medlemsfunktioner og frie friend-funktioner har ingen implicit `this`-pointer.

## Operator function: en funktion med et særligt navn

Operatoroverloading definerer betydningen af en eksisterende operator for brugerdefinerede typer. `operator+` kan eksempelvis beskrive addition af to punkters koordinater.

Vi bruger her `Punkt` som en enkel koordinatmodel. `Punkt(1, 2) + Punkt(3, 4)` giver `Punkt(4, 6)`. I en mere streng geometrisk model ville man ofte skelne mellem punkt og forskydningsvektor. Det valg handler om modellens betydning, ikke om C++-syntaksen.

Operatoren er stadig en funktion. Den særlige syntaks gør et velkendt mønster lettere at læse. Brug den kun, når betydningen er naturlig for læseren. Lad eksempelvis ikke `+` slette data eller ændre begge sine input uventet.

## Member og non-member operatorer

| Form | Hvad er venstre operand? | Eksempel på et binært kald |
| --- | --- | --- |
| Medlemsfunktion | Det aktuelle objekt, `*this` | `a.operator+=(b)` |
| Fri funktion | Første eksplicitte parameter | `operator+(a, b)` |

En binær medlemsoperator har normalt ét eksplicit operand-argument. En binær fri operator har normalt to. Nogle operatorer, som tildeling `=`, indeks `[]` og funktionskald `()` skal være medlemmer i C++17. `+` kan implementeres på begge måder; vælg én konsistent variant, så du undgår konkurrerende overloads.

En fri operator kan bruge offentlige getters uden at være friend. Den skal kun være friend, hvis du vælger at give den adgang til private data. For `+=` er et medlem naturligt, fordi venstre objekt ændres. For `+` er en fri funktion ofte passende, fordi begge operander indgår symmetrisk.

Et udbredt mønster er at implementere `+=` og lade `+` genbruge det på en kopi. Så bevarer `a + b` inputtet `a`, mens `a += b` ændrer `a`.

## Hvad kan operatoroverloading ikke ændre?

Du kan ikke opfinde et nyt operatorsymbol eller ændre operatorernes prioritet og syntaktiske antal operander. `a + b * c` følger stadig de sædvanlige grupperingsregler. For almindelige overloadede operatorer skal mindst én operand have en klasse- eller enum-type. Du kan ikke gøre `2 + 3` til strengsammenkædning.

Nogle operatorer kan slet ikke overloades, fx `.` og `::`. En overloaded `&&` eller `||` giver heller ikke automatisk den indbyggede operators short-circuit-adfærd. Brug ikke operatoroverloading som et trick til at ændre grundlæggende kontrolflow.

## I/O-operatorer: << og >>

Ved `std::cout << p` står streamen til venstre. Derfor bruger vi typisk en fri funktion:

```cpp
std::ostream& operator<<(std::ostream& out, const Punkt& p);
```

Den returnerer den samme stream som reference, så flere kald kan kædes: `std::cout << a << b`. Punktet læses gennem en const-reference.

Input-operatoren får derimod `Punkt&`, fordi den skal kunne ændre punktet. I eksemplet læser vi først to lokale tal. Kun hvis begge kan læses, opdaterer vi objektet. Ved fejl bevarer vi den tidligere værdi og returnerer streamens fejltilstand. Vi bruger streamens egne parse-regler og ændrer ikke dens exception-indstillinger.

Formatet for input er to tal adskilt af mellemrum, fx `5 6`. Output-formatet er `(5, 6)`. De to formater er bevidst forskellige i denne undervisningsdemo; output kan derfor ikke direkte læses tilbage med den viste input-operator.

## Komplet program

[08_operatorer.cpp](examples/oop-advanced/08_operatorer.cpp):

```cpp
#include <iostream>
#include <sstream>
class Punkt {
    double x, y;
public:
    Punkt(double x = 0, double y = 0) : x(x), y(y) {}
    Punkt& saetX(double x) { this->x = x; return *this; }
    Punkt& saetY(double y) { this->y = y; return *this; }
    Punkt& operator+=(const Punkt& anden) {
        x += anden.x; y += anden.y; return *this;
    }
    friend Punkt operator+(Punkt venstre, const Punkt& hoejre) {
        venstre += hoejre; return venstre;
    }
    friend std::ostream& operator<<(std::ostream& out, const Punkt& p) {
        return out << '(' << p.x << ", " << p.y << ')';
    }
    friend std::istream& operator>>(std::istream& in, Punkt& p) {
        double nx, ny;
        if (in >> nx >> ny) { p.x = nx; p.y = ny; }
        return in; // Bevar p, hvis et af de to tal mangler/er ugyldigt.
    }
};
int main() {
    Punkt a(1, 2), b(3, 4);
    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a uændret = " << a << '\n';
    a += b;
    std::cout << "a += b: " << a << '\n';
    a.saetX(8).saetY(9);
    std::cout << "Kaede: " << a << '\n';
    std::istringstream god("5 6"), daarlig("7 fejl");
    god >> a;
    std::cout << "Input: " << a << '\n';
    if (!(daarlig >> a)) std::cout << "Afvist input, stadig: " << a << '\n';
}
```

Forventet output:

```text
a + b = (4, 6)
a uændret = (1, 2)
a += b: (4, 6)
Kaede: (8, 9)
Input: (5, 6)
Afvist input, stadig: (5, 6)
```

`std::istringstream` lader os teste input uden at indtaste det manuelt. Den første stream indeholder gyldige tal. Den anden læser først 7, men fejler ved ordet `fejl`. Fordi vi bruger lokale variabler, bliver punktet ved med at være `(5, 6)`.

Denne model bruger `double`. Tilføjer du sammenligning af beregnede koordinater, skal du tænke over afrunding og tolerancer; præcis lighed er ikke altid den rette test for flydende tal.

## Opgaver

1. Implementér `operator-=` og en fri `operator-` efter samme mønster som addition.
2. Hvorfor returnerer `operator+=` en reference, mens `operator+` returnerer en værdi?
3. Skift den ugyldige inputstream til `"7 8"`. Hvad bliver objektet?
4. Hvad sker der, hvis `saetX()` returnerer `Punkt` i stedet for `Punkt&`, og du kæder `saetY()`?

<details><summary>Løsningsforslag</summary>

1. Medlemmet udfører `x -= anden.x; y -= anden.y; return *this;`. Den frie funktion modtager venstre som værdi, bruger `venstre -= hoejre`, og returnerer kopien.
2. `+=` skal returnere det ændrede, eksisterende objekt. `+` skaber et nyt resultat. Returnér aldrig en reference til den lokale kopi i `operator+`.
3. Punktet bliver `(7, 8)`.
4. Første kald ændrer originalens x, men returnerer derefter en kopi. Det kædede kald ændrer kopiens y, ikke originalens y.

</details>

## Videre læsning

Microsoft: [operatoroverloading](https://learn.microsoft.com/en-us/cpp/cpp/operator-overloading), [this-pointer](https://learn.microsoft.com/en-us/cpp/cpp/this-pointer) og [overloading af stream-operatorer](https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes).
