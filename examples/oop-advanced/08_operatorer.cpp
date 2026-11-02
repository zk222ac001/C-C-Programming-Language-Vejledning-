#include <iostream>
#include <sstream>
class Punkt {
    double x, y;
public:
    Punkt(double x = 0, double y = 0) : x(x), y(y) {}
    Punkt& saetX(double x) { this->x = x; return *this; }
    Punkt& saetY(double y) { this->y = y; return *this; }
    Punkt& operator+=(const Punkt& anden) {
        x += anden.x; y += anden.y; return *this;
    }
    friend Punkt operator+(Punkt venstre, const Punkt& hoejre) {
        venstre += hoejre; return venstre;
    }
    friend std::ostream& operator<<(std::ostream& out, const Punkt& p) {
        return out << '(' << p.x << ", " << p.y << ')';
    }
    friend std::istream& operator>>(std::istream& in, Punkt& p) {
        double nx, ny;
        if (in >> nx >> ny) { p.x = nx; p.y = ny; }
        return in; // Bevar p, hvis et af de to tal mangler/er ugyldigt.
    }
};
int main() {
    Punkt a(1, 2), b(3, 4);
    std::cout << "a + b = " << a + b << '\n';
    std::cout << "a uændret = " << a << '\n';
    a += b;
    std::cout << "a += b: " << a << '\n';
    a.saetX(8).saetY(9);
    std::cout << "Kaede: " << a << '\n';
    std::istringstream god("5 6"), daarlig("7 fejl");
    god >> a;
    std::cout << "Input: " << a << '\n';
    if (!(daarlig >> a)) std::cout << "Afvist input, stadig: " << a << '\n';
}
