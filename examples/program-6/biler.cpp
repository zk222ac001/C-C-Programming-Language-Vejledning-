#include <iostream>
#include <string>

class Bil
{
private:
    std::string maerke;
    int hastighed;

public:
    Bil(std::string bilMaerke)
        : maerke(bilMaerke), hastighed(0)
    {
    }

    void accelerer()
    {
        hastighed += 10;
    }

    int hentHastighed() const
    {
        return hastighed;
    }

    void visInfo() const
    {
        std::cout << maerke << " koerer "
                  << hastighed << " km/t.\n";
    }
};

int main()
{
    Bil bil1("Toyota");
    Bil bil2("Volvo");

    bil1.accelerer();
    bil1.accelerer();
    bil2.accelerer();
    bil1.accelerer();

    bil1.visInfo();
    bil2.visInfo();
    return 0;
}
