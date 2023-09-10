#include <memory>

using std::unique_ptr;

void set(unique_ptr<double>& ptr, double newVal) {
    *ptr = newVal;
}

int main() {
    unique_ptr<double> ptr(new double);
    set(ptr, 1.3);
}
