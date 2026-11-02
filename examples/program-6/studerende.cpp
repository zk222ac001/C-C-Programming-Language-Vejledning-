#include <iostream>
#include <string>

class Studerende
{
private:
    std::string navn;
    int alder;
    std::string uddannelse;

public:
    Studerende(std::string n, int a, std::string u)
        : navn(n), alder(a), uddannelse(u)
    {
    }

    void harFoedselsdag()
    {
        ++alder;
    }

    int hentAlder() const
    {
        return alder;
    }

    void visInfo() const
    {
        std::cout << navn << ", " << alder
                  << " aar, " << uddannelse << '\n';
    }
};

int main()
{
    Studerende anna("Anna", 22, "IT");
    Studerende ali("Ali", 24, "IT");

    anna.harFoedselsdag();
    anna.visInfo();
    ali.visInfo();

    return 0;
}
