#include <iostream>
using std::cout, std::endl;

class Tocard {
public:
    virtual void salute() {
        cout << "Who's your daddy ?" << endl;
    }

    void meet(Tocard* other) {
        this->salute();
        other->salute();
    }
};

class Human: public Tocard {
public:
    void salute() override {
        cout << "Hi, nice to meet you !" << endl;
    }
};

int main() {
    Human ana;
    Human bob;
    ana.meet(&bob);
}
