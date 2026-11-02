#include <iostream>
int hent() noexcept { return 7; }
void kanFejle() noexcept(false) { /* Kan tillade exceptions at forlade funktionen. */ }
int main() {
    std::cout << std::boolalpha;
    std::cout << "hent: " << noexcept(hent()) << '\n';
    std::cout << "kanFejle: " << noexcept(kanFejle()) << '\n';
} // noexcept(udtryk) undersøger egenskaben uden at udføre udtrykket.
