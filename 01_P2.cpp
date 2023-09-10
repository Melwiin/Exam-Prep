#include <iostream>
using std::cout, std::endl, std::ostream;

class Rectangle {
private:
    double height;
    double width;
public:
    Rectangle(double height, double width): height(height), width(width) {}

    friend ostream& operator<<(ostream& out, const Rectangle& r);
};

ostream& operator<<(ostream& out, const Rectangle& r) {
    out << "height = " << r.height << ", width = " << r.width;
}

int main() {
    Rectangle r(4.5, 5.7);
    cout << r << endl;
}
