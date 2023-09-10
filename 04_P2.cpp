#include <iostream>
#include <string>
#include <memory>
using std::cout, std::endl, std::string, std::unique_ptr;

class Object {
    string name;
public:
    Object(const string& n): name(n) {}
    friend void whoAreYou(unique_ptr<Object>);
};

class Tree: public Object {
    public: Tree(): Object("Tree") {}
};

class Item: public Object {
    public: Item(): Object("Item") {}
};

unique_ptr<Object> createObject(const string& name) {
    unique_ptr<Object> ptr;
    if (name == "Tree") {
        ptr.reset(new Tree());
    } else if (name == "Item") {
        ptr.reset(new Item());
    }
    return ptr;
}

void whoAreYou(unique_ptr<Object> obj) {
    cout << "I'm a " + obj->name << endl;
}

int main() {
    unique_ptr<Object> obj = createObject("Tree");
    whoAreYou(std::move(obj));
}
