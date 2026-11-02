# OOP i C++17 · fra objekter til sikker ressourcehåndtering

Dette forløb fortsætter efter [Program 6: klasser, objekter og constructors](Program_6_klasser-og-Objekter-i-cpp.md). Vi genbruger den viden og undersøger de mekanismer, der gør større C++-programmer forståelige og sikre at ændre.

**[Åbn filen til det nye interaktive lab](interactive/oop-videre.html)**. Download repositoryet som ZIP, pak det ud, og åbn `interactive/oop-videre.html` i din browser. Behold filerne `oop-videre.css` og `oop-videre.js` i samme mappe. GitHubs normale filvisning viser kildekode, ikke den aktive øvelse.

## Læserækkefølge

| Kapitel | Det undersøger du | Interaktive forsøg |
| --- | --- | --- |
| [7 · Abstraktion og klassemedlemmer](Program_7_Abstraktion_og_klassemedlemmer.md) | Adgang, destructor, inline, friend, static og references | 1–2 |
| [8 · Arv og livscyklus](Program_8_Arv_og_livscyklus.md) | Hierarkier, diamant og initialiseringsrækkefølge | 3–4 |
| [9 · Polymorfi og binding](Program_9_Polymorfi_og_binding.md) | Overloading, virtual, slicing og abstrakte klasser | 5–7 |
| [10 · Operatoroverloading](Program_10_Operatoroverloading.md) | this, medlemsoperatorer, frie operatorer og streams | 8–9 |
| [11 · Exceptions og RAII](Program_11_Exceptions_og_RAII.md) | Fejlforløb, noexcept og oprydning | 10 |

Alle fem artikler indeholder forklaringer, kode og opgaver med fold-ud-løsninger. Det interaktive lab viser udvalgte centrale mekanismer; det er ikke en erstatning for alle detaljer i artiklerne og kompilerer ikke C++.

## Dækning af emnerne

| Ønsket emne | Hvor findes forklaringen? |
| --- | --- |
| Classes, objects og constructors | Program 6, allerede gennemført |
| Abstraction mechanism; member data; member functions; private/public | Program 7, de første tre afsnit |
| Destructors | Program 7 samt livscyklus i Program 8 og unwind i Program 11 |
| Inline function | Program 7: inline og ODR |
| Friend functions | Program 7 og I/O i Program 10 |
| Static members | Program 7: klassens fælles data |
| References | Program 7; videreført til polymorfi i Program 9 |
| Class hierarchy; derived classes | Program 8 |
| Single, multiple, multilevel, hierarchical og hybrid inheritance | Program 8: sammenligningstabel og diamant |
| Role of virtual base class | Program 8: én fælles base i diamanten |
| Constructor/destructor execution; base initialization from derived constructors | Program 8: kørbart sporingsprogram |
| Binding; static og dynamic binding; late binding | Program 9 |
| Static polymorphism; function overloading; ambiguity | Program 9: overload resolution |
| Base class pointer; object slicing | Program 9: pointer-, værdi- og referenceforsøg |
| Method overriding with virtual functions | Program 9: virtual og override |
| Pure virtual functions; abstract classes | Program 9: Figur-eksemplet |
| This pointer og applications | Program 10: medlemsnavne, kædning og objektadgang |
| Operator function; member/non-member operators | Program 10: plus og plus-lig-med |
| Operator overloading; I/O operators | Program 10: operator+, operator+=, operator<< og operator>> |
| Try, throw, catch; exceptions og derived classes | Program 11 |
| Function exception declaration; unexpected exceptions | Program 11: moderne noexcept og historisk throw(T) |
| Exception when handling exceptions | Program 11: genkast, nye fejl i catch og destructor-fejl under unwind |
| Resource capture and release | Program 11: RAII og ejerskab |

## Sådan arbejder du med hvert emne

1. Læs en forklaring, og skriv din egen forudsigelse af resultatet.
2. Afprøv mekanismen i labbet. Brug Næste trin, når du vil studere rækkefølgen uden automatisk animation.
3. Kompilér det tilhørende [selvstændige program](examples/oop-advanced).
4. Ændr én ting, og forklar ændringen i output. Arbejd først derefter med næste koncept.

De komplette `.cpp`-filer i `examples/oop-advanced` har hver sin `main()`. Kompilér dem hver for sig. Kommandoerne kræver en installeret C++17-compiler.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic examples/oop-advanced/06_binding_slicing.cpp -o binding
./binding
```

På Windows med Visual Studio kan du bruge en Developer Command Prompt:

```text
cl /std:c++17 /EHsc /W4 /utf-8 examples\oop-advanced\06_binding_slicing.cpp /Fe:binding.exe
binding.exe
```

## Test af eksemplerne

Fra repositoryets rod kan du køre:

```bash
python3 tests/test_oop_advanced.py
```

Testen kræver Python 3 og `g++` i PATH. Den bygger i en midlertidig mappe, kontrollerer output fra de 12 programmer og tester bevidst ugyldig C++ separat. Der indgår også kontrollerede terminate-forsøg i underprocesser med en eksplicit exitkode, så de ikke afslutter testprocessen.

## Moderne og historisk C++

Materialet bruger C++17. `inline static`-data er derfor tilgængelige. Gamle dynamiske exception specifications som `throw(Type)` og `std::unexpected` forklares kun historisk; de skal ikke bruges i de moderne programmer. `noexcept` og RAII er de relevante mekanismer her.
