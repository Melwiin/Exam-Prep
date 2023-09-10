#include <iostream>
using namespace std;

class Apple {
    double radius;
public:
    Apple() : radius(10) { }
    void getACrunch() { radius -= 0.1; }

    Apple(const Apple& s) {
        cout << "Copied.";
    }
    Apple& operator=(const Apple& other) {
        cout << "Copied.";
        return *this;
    }
};

void eatSome(Apple* a) {
    a->getACrunch();
}

int main() {
    Apple a;
    eatSome(&a);
}