#include <iostream>
#include <string>

class Planet
{
public:
    std::string navn;
    int antalMaaner;
    double afstandTilSolen;

    Planet(std::string planetNavn, int maaner, double afstand)
        : navn(planetNavn),
          antalMaaner(maaner),
          afstandTilSolen(afstand)
    {
    }

    void visInfo() const
    {
        std::cout << navn << " har " << antalMaaner
                  << " maaner og en gennemsnitlig afstand paa "
                  << afstandTilSolen << " millioner km.\n";
    }

    bool harMaaner() const
    {
        return antalMaaner > 0;
    }

    bool erTaetterePaaSolenEndJorden() const
    {
        return afstandTilSolen < 149.6;
    }
};

int main()
{
    Planet merkur("Merkur", 0, 57.9);
    Planet jorden("Jorden", 1, 149.6);
    Planet mars("Mars", 2, 227.9);

    merkur.visInfo();
    jorden.visInfo();
    mars.visInfo();

    std::cout << std::boolalpha;
    std::cout << "Mars har maaner: " << mars.harMaaner() << '\n';
    std::cout << "Merkur er taettere paa Solen end Jorden: "
              << merkur.erTaetterePaaSolenEndJorden() << '\n';

    return 0;
}
