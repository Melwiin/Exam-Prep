#include <iostream>
using std::cout, std::endl;

class Tocard {
public:
    virtual void salute() const = 0;
    void meet(const Tocard& other){
        this->salute();
        other.salute();
    }
};

class Human: public Tocard {
public:
    void salute() const override {
        cout << "Hi, nice to meet you !" << endl;
    }
};

int main() {
    Human().meet(Human());
}
