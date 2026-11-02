#include <iostream>
void vis(int) { std::cout << "vis(int)\n"; }
void vis(double) { std::cout << "vis(double)\n"; }
void bland(int, double) { std::cout << "bland(int, double)\n"; }
void bland(double, int) { std::cout << "bland(double, int)\n"; }
int main() {
    vis(3);
    vis(3.5);
    // bland(1, 1); // Bevidst udeladt: tvetydigt, kan ikke kompilere.
    bland(1, 1.0);
    bland(1.0, 1);
}
