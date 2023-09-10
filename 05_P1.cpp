#include <iostream>
#include <string>
using std::cout, std::endl, std::cin, std::string;

double divide(double denom, double num) {
    if (denom == 0) throw "division by zero";
    return num/denom;
}

int main() {
    try {
        double denom;
        double num;
        cout << "Enter Denominator : ";
        if (!(cin >> denom)) throw "wrong format for denom";

        cout << "Enter Numerator : ";
        if (!(cin >> num)) throw "wrong format for num";
        

        double res = divide(denom, num);
        cout << "Division : " << res << endl;
    } catch (char const* e) {
        cout << "Error : " << e << endl;
    }
}
