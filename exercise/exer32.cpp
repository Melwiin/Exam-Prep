/*1. Implement the base constuctor and the getter/setter methods for the attributes of this class :*/

#include <string>

using std::string;

class Vault {
private:
    int gold;
    string _owner;
public:
    const string& owner;
public:
    Vault(int g, string o) : _owner(o), gold(g), owner(_owner) { }

    int getGold() const { return gold; }
    void setGold(int newGold) { gold = newGold; }

    string getOwner() const { return owner; }
    void setOwner(string newOwner) { _owner = newOwner; }
};

/*2. How would you transform the class so that the owner attribute is public, read-only, but its value
can still be modified with a setter method ? */