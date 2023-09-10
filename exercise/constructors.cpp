#include <string>
#include <iostream>

using namespace std;

class Stuff
{
public:
    string name;
    double value;
public:
    Stuff() : name(""), value(0) {
        cout << "Init at adress: " << this << endl;
    }
    Stuff(string n, double v) : name(n), value(v) { 
        cout << "Init at adress: " << this << endl;
    }
    Stuff(Stuff&& other) : name(), value() {
        cout << "Init at adress: " << this << endl;
        cout << "Copied from: " << &other << endl;
        std::swap(other.name, this->name);
        std::swap(other.value, this->value);
    }
    Stuff(const Stuff& other) : name(other.name), value(other.value) {
        cout << "Init at adress: " << this << endl;
        cout << "Copied from: " << &other << endl;
    }
    
    Stuff& operator=(const Stuff& other) {
        name = other.name;
        value = other.value;
        return *this;
    }

    Stuff& operator=(Stuff&& other) {
        std::swap(other.name, this->name);
        std::swap(other.value, this->value);
        other.name = "";
        other.value = 0;
        return *this;
    }
};

int main()
{
    Stuff stuff1;
    Stuff stuff2("Ak47", 69);
    Stuff copyStuff1(stuff1);
    Stuff moveStuff2(std::move(stuff2));

    Stuff stuff3 = moveStuff2;
    Stuff stuff4 = std::move(stuff3);

    return 0;
}