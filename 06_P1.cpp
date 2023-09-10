#include <iostream>
#include <string>
#include <cassert>

using std::cout, std::endl, std::string;

class NonCopyableObject {
private:
    string name;

    void use() { name += " (used)"; }
public:
    // Constructor
    NonCopyableObject(const string& name): name(name) {}
    NonCopyableObject(): NonCopyableObject("") {}
    
    void what() const { cout << "NonCopyableObject : " << name << endl; }
    friend NonCopyableObject use(NonCopyableObject obj) {
        obj.use();
        return obj;
    }

    // Copy constructor
    NonCopyableObject(const NonCopyableObject& other) = delete;
    // Copy assignment operator
    NonCopyableObject& operator=(const NonCopyableObject& other) = default;

    // Move constructor
    NonCopyableObject(NonCopyableObject&& other) = default;
    // Move assignment operator
    NonCopyableObject& operator=(NonCopyableObject&& other) {
        this->name = other.name;
        return *this;
    };
};

int main() {
    NonCopyableObject obj("thing");
    obj = use(std::move(obj));
    obj.what();
}
