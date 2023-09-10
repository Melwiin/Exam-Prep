/*
    Implement the default constructor, copy constructor and copy assignment operator of the
    following class (and be clever for the default constructor ...) :
*/

class Apple {
    double radius;
public:
    Apple() : radius(10) { };

    Apple(const Apple& other) {
        this->radius = other.radius;
    }

    Apple& operator=(const Apple& other) {
        this->radius = other.radius;
        return *this;
    }

    void getACrunch() { radius -= 0.1; }
};

int main()
{
    return 0;
}

/*
    How would you transform the following code such that no implicit copy of the Apple object
    is performed during the call of the eatSome function ?
*/

// Call by value
// Copy assignment operator

void eatSome(Apple& a) {
    a.getACrunch();
}

int main() {
    Apple a;
    eatSome(a);
}