/*
    How should you modify the divideBy function below to avoid a compilation error while still
    keeping the call by reference for each argument ?
*/

#include <iostream>

using std::cout, std::endl;

void divideBy(double &x, const int &div) {
    x /= div;
}

int main() {
    double x = 3;
    divideBy(x, 2);
    cout << x << endl;
}