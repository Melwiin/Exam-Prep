class Rectangle {
private:
    double height;
    double width;
public:
    Rectangle() : height(10), width(10) { }
    Rectangle(double height, double width): height(height), width(width) {}
};

int main() {
    Rectangle r1;
    Rectangle r2(r1);
}
