#include <iostream>
struct Dyr {
    virtual ~Dyr() = default;
    const char* kategori() const { return "Dyr"; } // Ikke virtual.
    virtual const char* lyd() const { return "Generisk lyd"; }
};
struct Hund : Dyr {
    const char* kategori() const { return "Hund"; } // Skjuler, overrider ikke.
    const char* lyd() const override { return "Vov"; }
};
void somVaerdi(Dyr d) { std::cout << "Vaerdi: " << d.lyd() << '\n'; }
void somReference(const Dyr& d) { std::cout << "Reference: " << d.lyd() << '\n'; }
int main() {
    Hund hund;
    Dyr* p = &hund; // Ikke-ejende pointer; hund lever længere end p bruges.
    std::cout << "Statisk: " << p->kategori() << '\n';
    std::cout << "Dynamisk: " << p->lyd() << '\n';
    somVaerdi(hund);       // Et nyt Dyr-objekt: Hund-delen skæres væk.
    somReference(hund);   // Samme Hund-objekt: polymorfien bevares.
}
