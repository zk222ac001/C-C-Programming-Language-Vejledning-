#include <iostream>
#include <string>
class Sensor {
    std::string navn;                // Hvert objekt har sit eget navn.
    double maaling;
    inline static int levende = 0;   // Fælles for klassen (C++17).
public:
    Sensor(std::string n, double m) : navn(n), maaling(m) { ++levende; }
    Sensor(const Sensor&) = delete;  // Hold tælleren enkel i denne demo.
    Sensor& operator=(const Sensor&) = delete;
    ~Sensor() noexcept { --levende; }
    double hent() const { return maaling; } // Implicit inline i C++17.
    void saet(double v) { maaling = v; }
    static int antal() { return levende; }
    friend void rapport(const Sensor& s);
};
void rapport(const Sensor& s) { // Fri funktion med eksplicit adgang.
    std::cout << s.navn << ": " << s.maaling << '\n';
}
int main() {
    std::cout << "Antal: " << Sensor::antal() << '\n';
    {
        Sensor a("A", 20), b("B", 25);
        Sensor& alias = a;
        alias.saet(21);
        rapport(a);
        rapport(b);
        std::cout << "Antal: " << Sensor::antal() << '\n';
    } // b og derefter a destrueres.
    std::cout << "Antal: " << Sensor::antal() << '\n';
}
