#include <iostream>

using namespace std;

class Stuff {
private:
    double value;
    int number;
public:
    Stuff() {
        this->value = 0;
        this->number = 0;      
        cout << this << " in Default" << endl;
    }

    Stuff(double v, int n) : value(v), number(n) {
        cout << this << " in Base" << endl;
    }

    Stuff(const Stuff& other) {
        this->value = other.value;
        this->number = other.number;
        cout << this << " in Copy Con. " << endl;
    }

    Stuff(Stuff&& other) {
        this->number = other.number;
        this->value = other.value;
        other.value = 0;
        other.number = 0;
    }

    Stuff& operator=(const Stuff& other) {
        this->number = other.number;
        this->value = other.value;
        cout << this << " as Copy assignment from " << &other << endl;
        return *this;
    }

    Stuff& operator=(Stuff&& other) {
        this->value = 0;
        this->number = 0;
        std::swap(value, other.value);
        std::swap(number, other.number);
        cout << this << " as Move assignment from " << &other << endl;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Stuff& stuff);
};    

ostream& operator<<(ostream& os, const Stuff& stuff) {
    os << "Stuff Value: " << stuff.value << " Stuff number" << stuff.number << endl;
    return os;
}