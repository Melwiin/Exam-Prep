#include <cmath>
/* We give the following implementations : */
class Point1D {
public:
    double x;
    Point1D(double xVal) : x(xVal) {}
};

class Point2D : public Point1D {
public:
    double y;
    Point2D(double yVal, double xVal) : y(yVal), Point1D(xVal) { }
};

class Vector : public Point2D {
public:
    Vector(double yVal, double xVal) : Point2D(yVal, xVal) { }
    // =
    using Point2D::Point2D;

    double norm() { return sqrt(x * x + y * y); }
};

/*
What is wrong with the constructor of Point2D ? 
Write below it one of its correct implementation. Why is the current Vector class of no practical use ? 
Complete its implementation to solve this problem.
*/