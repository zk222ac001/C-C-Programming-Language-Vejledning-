#include <iostream>
using namespace std;

class Enemy {
protected:
    int attackPower;
public:
    // Alle fjender starter med angrebsstyrke 0.
    Enemy() : attackPower(0) {}

    void setAttackPower(int power) {
        attackPower = power;
    }

    // Det faktiske objekt bestemmer versionen ved virtuelle kald.
    virtual void attack() {
        cout << "Enemy angriber med styrke " << attackPower << endl;
    }

    // Muliggør korrekt destruktion gennem en Enemy-pointer.
    virtual ~Enemy() = default;
};

class Ninja : public Enemy {
public:
    // Compileren kontrollerer, at en virtuel funktion overrides.
    void attack() override {
        cout << "Ninja angriber med et svaerd! Styrke: "
             << attackPower << endl;
    }
};

class Monster : public Enemy {
public:
    void attack() override {
        cout << "Monster angriber med kloer! Styrke: "
             << attackPower << endl;
    }
};

int main() {
    Ninja n;
    Monster m;

    Enemy* e1 = &n;
    Enemy* e2 = &m;

    e1->setAttackPower(20);
    e2->setAttackPower(80);

    // Samme pointertype, men forskellige implementeringer.
    e1->attack();
    e2->attack();
    return 0;
}
