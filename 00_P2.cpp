class Rectangle {
public:
    double height;
    double width;
    Rectangle() : height(10), width(10) { }
    Rectangle(double height, double width): height(height), width(width) {}
};

class Box {
public:
    Rectangle rect;
    double depth;

    Box() : depth(10) { };
};

int main() {
    Box b;
}
