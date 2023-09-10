#include <string>
using namespace std;

class Vault{
    int gold;
    string owner;
public:
    Vault(int g, string o) {
        gold = g;
        owner = o;
    }

    int getGold() { return gold; }
    void setGold(int newGold) { gold = newGold; }

    string getOwner() { return owner; }
    void setOwner(string newOwner) { owner = newOwner; }
};