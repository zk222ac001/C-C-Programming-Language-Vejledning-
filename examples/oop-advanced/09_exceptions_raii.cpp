#include <iostream>
#include <stdexcept>
#include <string>
class SensorFejl : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};
class ForLav : public SensorFejl {
public:
    using SensorFejl::SensorFejl;
};
class Vagt { // Simulerer en ejet ressource uden at åbne rigtige filer.
    std::string navn;
public:
    explicit Vagt(std::string n) : navn(n) { std::cout << "Hent " << navn << '\n'; }
    ~Vagt() noexcept { std::cout << "Frigiv " << navn << '\n'; }
    Vagt(const Vagt&) = delete;
    Vagt& operator=(const Vagt&) = delete;
};
void maal(int v) {
    Vagt laas("laas"), fil("fil");
    if (v < 0) throw ForLav("Negativ maaling");
    std::cout << "Maaling: " << v << '\n';
}
int main() {
    try { maal(-1); }
    catch (const ForLav& e) { std::cout << "Specifik catch: " << e.what() << '\n'; }
    catch (const SensorFejl& e) { std::cout << "Sensorfejl: " << e.what() << '\n'; }
    catch (const std::exception& e) { std::cout << "Standardfejl: " << e.what() << '\n'; }
    std::cout << "Fortsætter\n";
}
