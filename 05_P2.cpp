#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Error {
public:
    virtual void print() {
        cout << "Error" << endl;
    }
};

class NumericalError : public Error {
    virtual void print() override {
        cout << "Numerical Error" << endl;
    }
};

int main() {
    try {
        int n = 10;
        if (n != 1) {
            throw new NumericalError();
        }
    } catch (Error* e) {
        e->print();
    }
}

/*
    Error:
        print()
->    NummericalError:
        print()

*/