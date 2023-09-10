#include <cmath>

class Point1D
{
public:
    double x;
    Point1D(double xVal) : x(xVal) {}
};

class Point2D : public Point1D
{
public:
    double y;
    Point2D(double yVal, double xVal) : y(yVal), Point1D(xVal) { }
};

class Vector : public Point2D
{
public:
    using Point2D::Point2D;
    double norm() { return sqrt(x * x + y * y); }
};

int main(int argc, char const *argv[])
{
    Vector v(2, 2);
    return 0;
}
