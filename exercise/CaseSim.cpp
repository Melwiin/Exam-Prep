#include <iostream>
#include <vector>
#include <random>
#include <time.h>

#define BLUE_PROP   0.7992
#define PURPLE_PROP 0.1598
#define PINK_PROP   0.032
#define RED_PROP    0.0064
#define GOLD_PROP   0.0026

using namespace std;

enum RARITY {
    BLUE,
    PURPLE,
    PINK,
    RED,
    GOLD
};

string rareToString(RARITY rarity) {
    if(rarity == BLUE) return "Blue";
    if(rarity == PURPLE) return "Purple";
    if(rarity == PINK) return "Pink";
    if(rarity == RED) return "Red";
    if(rarity == GOLD) return "Gold";
    return "Unknown rarity";
}


class Item {
protected:
    // Used only for cases
    bool isCase;

    // Item properties
    bool isStatTrack;
    RARITY itemRarity;
    string itemName;
    float itemFloat;
public:
    Item(string _itemName, RARITY _itemRarity, float _itemFloat, bool _isStatTrack, bool _isCase = false) 
        : itemName(_itemName), itemRarity(_itemRarity), itemFloat(_itemFloat), isStatTrack(_isStatTrack), isCase(_isCase) { }

    Item(Item& o) = delete; // Prohibite duplication glitch
    ~Item() { }
    Item& operator=(Item& o) = delete; // Prohibite duplication glitch

    friend ostream& operator<<(ostream& os, const Item& item);
};

ostream& operator<<(ostream& os, const Item& item) {
    os << "[" << rareToString(item.itemRarity) << "] " << item.itemName << (item.isStatTrack ? "(ST)" : "") << endl;
    return os;
}

class Case : public Item {
private:
public:
    Case() : Item("Case", BLUE, 0, false, true) { }
};

class Player {
private:
    string name;
    int level;
    Item* inventory[100];
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
public:
    Player(string _name, int _level) : name(_name), level(_level) {
        for(int i = 0; i < 100; i++) inventory[i] = nullptr;
        generator = std::default_random_engine(time(nullptr));
        distribution = std::uniform_real_distribution(0.0, 1.0);
    }

    void giveItem(Item* item) {
        try
        {
            if(item == nullptr) throw "item doesn't exist";
            for(int i = 0; i < 100; i++) {
                if(inventory[i] == nullptr) {
                    inventory[i] = item;
                    return;
                }
            }
            throw "inventory full";
        }
        catch(const char* e)
        {
            cout << "Error: " << e << endl;
        }
    }

    int findItemIndex(Item* item) {
        for(int i = 0; i < 100; i++) {
            if(inventory[i] == item) return i;
        }
        return -1;
    }

    void open(Case* c) {
        double randomValue = distribution(generator);
        double itemFloat = distribution(generator);
        double statTrackRange = distribution(generator);
        bool isStatTrack = statTrackRange >= 0.9 ? true : false;

        // Delete case
        inventory[findItemIndex(c)] = nullptr;
        delete c;
        cout << randomValue << endl;
        if(randomValue <= BLUE_PROP) {
            giveItem(new Item("SSG 08 | Abyss", BLUE, itemFloat, isStatTrack));
        }else if(randomValue <= BLUE_PROP + PURPLE_PROP) {
            giveItem(new Item("Nova | Koi", PURPLE, itemFloat, isStatTrack));
        }else if(randomValue <= BLUE_PROP + PURPLE_PROP + PINK_PROP) {
            giveItem(new Item("Glock-18 | Water Elemental", PINK, itemFloat, isStatTrack));
        }else if(randomValue <= BLUE_PROP + PURPLE_PROP + PINK_PROP + RED_PROP) {
            giveItem(new Item("P90 | Asiimov", RED, itemFloat, isStatTrack));
        }else if(randomValue <= BLUE_PROP + PURPLE_PROP + PINK_PROP + RED_PROP + GOLD_PROP) {
            giveItem(new Item("Butterfly Knife | Case Hardened (Blue Gem)", GOLD, itemFloat, isStatTrack));
        }
    }

    friend ostream& operator<<(ostream& os, const Player& player);
};

ostream& operator<<(ostream& os, const Player& player) {
    os << "Player name: " << player.name << " with level: " << player.level << endl;
    os << "Inventory: " << endl;
    int itemCount = 0;
    for (int i = 0; i < 100; i++) {
        if (player.inventory[i] == nullptr) continue;
        itemCount++;
        cout << "   " << itemCount << ". " << *(player.inventory[i]) << endl;
    }
    return os;
}

int main() {


    Player csmelwin("Melwin :)", 8);
    for(int i = 0; i < 100; i++) {
        Case* c = new Case();
        csmelwin.open(c);
    }

    cout << csmelwin << endl;
}