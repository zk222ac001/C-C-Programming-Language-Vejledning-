#include <iostream>
#include <memory>
#include <vector>
class Figur {
public:
    virtual ~Figur() = default;
    virtual double areal() const = 0;
};
class Rektangel : public Figur {
    double bredde, hoejde;
public:
    Rektangel(double b, double h) : bredde(b), hoejde(h) {}
    double areal() const override { return bredde * hoejde; }
};
class Kvadrat : public Figur {
    double side;
public:
    explicit Kvadrat(double s) : side(s) {}
    double areal() const override { return side * side; }
};
int main() {
    std::vector<std::unique_ptr<Figur>> figurer;
    figurer.push_back(std::make_unique<Rektangel>(3, 4));
    figurer.push_back(std::make_unique<Kvadrat>(5));
    for (const auto& f : figurer) std::cout << f->areal() << '\n';
} // unique_ptr rydder op gennem en virtual destructor.
