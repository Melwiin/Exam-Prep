#include <iostream>
using std::cout, std::endl, std::ostream;

class Complex {
public:
    double real;
    double imag;
public:
    Complex(double real, double imag): real(real), imag(imag) {}

    Complex operator*(const Complex& other) {
        real *= other.real;
        imag *= other.imag;

        return *this;
    }
};

int main() {
    Complex z(0.5, 0.5);
    Complex j(0, 2);

    Complex res = z*z*j;
}
