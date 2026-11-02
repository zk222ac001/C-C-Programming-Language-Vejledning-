#include <iostream>
#include <stdexcept>
struct Del {
    Del() { std::cout << "+ Del\n"; }
    ~Del() { std::cout << "- Del\n"; }
};
struct Helhed {
    Del del;
    Helhed() {
        std::cout << "Helhed-krop starter\n";
        throw std::runtime_error("Kunne ikke starte");
    }
    ~Helhed() { std::cout << "- Helhed\n"; }
};
int main() {
    try { Helhed h; }
    catch (const std::exception& e) { std::cout << "Catch: " << e.what() << '\n'; }
} // ~Helhed bliver ikke kaldt; det fuldt oprettede medlem Del ryddes op.
