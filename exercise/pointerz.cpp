#include <string>
#include <iostream>

using std::string, std::cout, std::endl;

class Stuff {
    string name;
    double value;
public:
    Stuff() : name(""), value(0) {
        cout << this << " Default " << endl;
    }
    Stuff(string n, double v) : name(n), value(v) {
        cout << this << " Base" << endl;
    } 

    Stuff(const Stuff& other) {
        this->name = other.name;
        this->value = other.value;
        cout << this << " Copied to." << endl;
        cout << &other << " Origin." << endl;
    }

    Stuff(Stuff&& other) {
        value = 0;
        name = "";
        std::swap(name, other.name);
        std::swap(value, other.value);
        cout << this << " Copied to." << endl;
        cout << &other << " Origin." << endl;
    }
};
