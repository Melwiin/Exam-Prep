#include <memory>
#include <iostream>

using std::unique_ptr;

void set(unique_ptr<double>& ptr, double newVal) {
    *ptr = newVal;
}

int main() {
    unique_ptr<double> ptr(new double());
    set(ptr, 1.3);
    std::cout << *ptr << std::endl;
}

/* How should you modify the set function to avoid a compilation error ? */