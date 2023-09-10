#include <iostream>
#include <string>
#include <cassert>

using std::cout, std::endl, std::string, std::move;

class NonCopyableObject {
    string name;
public:
    NonCopyableObject(const string& name): name(name) {}
    NonCopyableObject(): NonCopyableObject("") {}
    
    void what() const { 
        cout << "NonCopyableObject : " << (name != "" ? name : "empty") << endl; 
    }

    NonCopyableObject(const NonCopyableObject& other) = delete;
    NonCopyableObject& operator=(const NonCopyableObject& other) = delete;

    NonCopyableObject(NonCopyableObject&& other) {
        this->name = other.name;
        other.name = "";
    }
};

class Container {
    NonCopyableObject obj;
public:
    Container(NonCopyableObject obj) : obj(move(obj)) { }

    void what() const { obj.what(); }    
};

int main() {
    NonCopyableObject obj("thing");
    Container cont(move(obj));
    obj.what();
    cont.what();
    
}
