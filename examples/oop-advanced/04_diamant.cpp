#include <iostream>
namespace almindelig {
struct Enhed { int id; explicit Enhed(int i) : id(i) {} };
struct Laeser : Enhed { Laeser() : Enhed(1) {} };
struct Skriver : Enhed { Skriver() : Enhed(2) {} };
struct Scanner : Laeser, Skriver {};
}
namespace delt {
struct Enhed { int id; explicit Enhed(int i) : id(i) {} };
struct Laeser : virtual Enhed { Laeser() : Enhed(1) {} };
struct Skriver : virtual Enhed { Skriver() : Enhed(2) {} };
struct Scanner : Laeser, Skriver {
    Scanner() : Enhed(99), Laeser(), Skriver() {}
};
}
int main() {
    almindelig::Scanner a;
    // a.id er tvetydigt: der er to Enhed-delobjekter.
    std::cout << "Uden virtual: " << a.Laeser::id << ", " << a.Skriver::id << '\n';
    delt::Scanner b;
    b.Laeser::id = 42;
    std::cout << "Med virtual: " << b.id << ", " << b.Skriver::id << '\n';
}
