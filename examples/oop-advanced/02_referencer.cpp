#include <iostream>
void kopi(int x) { x = 99; std::cout << "Lokal kopi: " << x << '\n'; }
void original(int& x) { x = 30; }
void laes(const int& x) { std::cout << "Laest: " << x << '\n'; }
inline int dobbelt(int x) { return x * 2; }
int main() {
    int a = 10, b = 20;
    int& r = a;
    r = b; // Skriver 20 i a; r bliver ved med at referere til a.
    b = 50;
    kopi(a);
    std::cout << "a: " << a << ", b: " << b << '\n';
    original(a);
    laes(a);
    std::cout << "Dobbelt: " << dobbelt(a) << '\n';
}
