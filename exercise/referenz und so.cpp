#include <iostream>

using std::cout, std::endl;

void divideBy(double& x, int& div) {
    x /= div;
}

int main() {
    double x = 3;
    divideBy(x, 2);
    cout << x << endl;
}