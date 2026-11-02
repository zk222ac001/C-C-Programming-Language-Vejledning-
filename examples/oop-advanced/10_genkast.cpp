#include <iostream>
#include <stdexcept>
void nederst() { throw std::out_of_range("Indeks 8 findes ikke"); }
void mellem() {
    try { nederst(); }
    catch (const std::exception&) {
        std::cout << "Log i mellem\n";
        throw; // Bevar den oprindelige exception og dens dynamiske type.
    }
}
int main() {
    try { mellem(); }
    catch (const std::out_of_range& e) { std::cout << "Yderst: " << e.what() << '\n'; }
}
