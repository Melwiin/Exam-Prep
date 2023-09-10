#include <iostream>
#include <cmath>

using namespace std;

class Vector2d {
public:
    double x, y;
    Vector2d(double x = 0, double y = 0) : x(x), y(y) {}
};
// Norm
double* norm(Vector2d* v) {
    return new double(sqrt(v->x*v->x + v->y*v->y));
}
// Add 
Vector2d* add(Vector2d* v, int* num) {
    return new Vector2d(v->x + *num, v->y + *num);
}   
// Sub
void sub(Vector2d* v) {
    v->x - 2.3;
    v->y - 2.3;
}

int main() {
    Vector2d* one = new Vector2d(1, 1);
    Vector2d* zero = new Vector2d();

    double* normResult = norm(one);
    cout << *normResult << endl;

    int* num = new int(10);
    Vector2d* addResult = add(one, num);
    cout << addResult->x << " " << addResult->y << endl;

    sub(one);
    cout << one->x << " " << one->y << endl;
}