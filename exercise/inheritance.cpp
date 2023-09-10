#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player;
class Item {
protected:
    bool isPhysical;
    double magicDamage, physicalDamage;
public:
    Item(bool _isPhysical, double _magicDamage = 0, double _physicalDamage = 0);

    void applyItemBaseDamage(Player* player);
    virtual void effectOpponent(Player* player);
    virtual void effectHolder(Player* player);
};

class Player {
private:
    double health;
    double magicResistance;
    double physicalResistance;

    double speed;
    vector<Item> items;
public:
    Player() { }

    /* Getter */
    double getMagicResistance() { return magicResistance; }
    double getPhysicalResistance() { return physicalResistance; }
    double getHealth() { return health; }

    /* Setter */
    void setMagicResistance(double newMagicResistance) { magicResistance = newMagicResistance; }
    void setPhysicalResistance(double newPhysicalResistance) { physicalResistance = newPhysicalResistance; }
    void setHealth(double newHealth) { health = newHealth; }

    void attackPlayer(Player* defender) {
        for (Item& item : items) {
            item.effectOpponent(defender);
            item.effectHolder(this);
        }
    }

    bool isAlive() const { return health > 0; }
};

Item::Item(bool _isPhysical, double _magicDamage = 0, double _physicalDamage = 0) 
        :   isPhysical(_isPhysical), 
            magicDamage(_magicDamage),
            physicalDamage(_physicalDamage) { }
void Item::applyItemBaseDamage(Player* player) { player->setHealth(player->getHealth() - magicDamage - physicalDamage); }
void Item::effectOpponent(Player* player) {}
void Item::effectHolder(Player* player) {}

class PoisonEdge : public Item {
public: 
    PoisonEdge() : Item(true, 0, 2) { }
    void effectOpponent(Player* player) override {
        applyItemBaseDamage(player);
        player->setPhysicalResistance(player->getPhysicalResistance() - 1);
    }
};

class ManaStar : public Item {
public:
    ManaStar() : Item(false, 2, 0) { }
    void effectOpponent(Player* player) override {
        applyItemBaseDamage(player);
        player->setMagicResistance(player->getMagicResistance() - 1);
    }
};



// Magic damage
class Mage : public Player {
public:
    Mage() {

    }
};

// Physical damage
class Warrior : public Player {
public:
    Warrior() {

    }
};

int main() {

    Player* player1 = new Warrior();
    Player* player2 = new Mage();

    while(player1->isAlive() && player2->isAlive()) {
        player1->attackPlayer(player2);
        player2->attackPlayer(player1);
    }

    if(player1->isAlive()) cout << "Player2 won";
    if(player2->isAlive()) cout << "Player1 won";


    return 0;
}