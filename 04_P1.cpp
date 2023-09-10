#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Object {
    string name;
public:
    Object(const string& n): name(n) {}
    string whoAmI() const { return name; }
};

class Tree: public Object {
    public: Tree(): Object("Tree") {}
};

class Item: public Object {
    public: Item(): Object("Item") {}
};

Object* createObject(const string& name) {
    if (name == "Tree") {
        Tree* obj = new Tree();
        return obj;
    } else if (name == "Item") {
        Item* obj = new Item();
        return obj;
    }

    return nullptr;
}

int main() {
    Object* obj = createObject("Item");
    cout << obj->whoAmI() << endl;
}
