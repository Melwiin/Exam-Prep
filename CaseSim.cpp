#include <iostream>
#include <vector>
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
    Item() {}

    Item(Item& o) = delete; // Prohibite duplication glitch
    Item& operator=(Item& o) = delete; // Prohibite duplication glitch

    friend //ostream isCase, stattrack, rarity, name, float
};

class Case : public Item {
private:
public:
    Case() { }
};

class Player {
private:
    string name;
    int level;
    Item* invetory[100];
public:
    Player() {}

    void giveItem(Item* item) { }
    void open(Case* c) {
        // 
        // Give opened item to player inventory
    }

    friend //ostream print level, name and inventory
};

int main() {
    srand(time(NULL)); // Random seed = different outcomes

    Player csmelwin;
    Case* breakoutCase = new Case();
    csmelwin.giveItem(breakoutCase);
    csmelwin.open(breakoutCase);

    cout << csmelwin << endl;
}

/* 
    1. Constructor
    2. external ostream overload
*/