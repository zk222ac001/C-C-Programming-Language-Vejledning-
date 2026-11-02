#include <iostream>
#include <string>
struct Spor {
    std::string navn;
    explicit Spor(std::string n) : navn(n) { std::cout << "+ " << navn << '\n'; }
    ~Spor() { std::cout << "- " << navn << '\n'; }
};
struct BaseA {
    explicit BaseA(int id) { std::cout << "+ BaseA " << id << '\n'; }
    ~BaseA() { std::cout << "- BaseA\n"; }
};
struct BaseB {
    BaseB() { std::cout << "+ BaseB\n"; }
    ~BaseB() { std::cout << "- BaseB\n"; }
};
struct Robot : BaseA, BaseB {
    Spor kamera;
    Spor motor;
    explicit Robot(int id) : BaseA(id), BaseB(), kamera("kamera"), motor("motor") {
        std::cout << "+ Robot-krop\n";
    }
    ~Robot() { std::cout << "- Robot-krop\n"; }
};
int main() { Robot r(7); }
