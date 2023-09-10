#include <iostream>

using std::cout, std::ostream, std::endl;

class ComplexNumber
{
private:
    double real;
    double imaginary;
public:
    ComplexNumber() : real(0), imaginary(0) { }
    ComplexNumber(double r, double i) {
        real = r;
        imaginary = i;
    }
    ComplexNumber(const ComplexNumber& other) {
        real = other.real;
        imaginary = other.imaginary;
    }
    ~ComplexNumber() { 
        cout << "Complex number deinialized\n";
    }
    ComplexNumber operator+(const ComplexNumber& other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }
    ComplexNumber operator-(const ComplexNumber& other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const ComplexNumber& num);
};

// External << operator overload
ostream& operator<<(ostream& os, const ComplexNumber& num) {
    os << "Real: " << num.real << ", Imaginary: " << num.imaginary;
    return os;
}

int main()
{
    // Print out complex
    ComplexNumber c1(4, 3);
    ComplexNumber c2(6, 2);
    ComplexNumber c3(c1);

    int i = 20;
    cout << i;

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;

    return 0;
}
