#include <iostream>

int copyTimes = 0;

class Object {
public:
    int i;
    Object(int i) : i(i) {}

    Object(Object& other) {
        std::cout << "Copy constructor. Copied: " << copyTimes << std::endl;
        this->i = other.i;
    }

    Object& operator=(Object& other) {
        std::cout << "Copy assignment operator. Copied: "<< copyTimes << std::endl;
        this->i = other.i;
        return *this;
    }

    void operator()(Object& other){
        std::cout << "Operator ()" << std::endl;
    }
};

Object& createObject(int i) {
    Object *obj = new Object(i);
    return *obj;
}

int main() {
    Object &obj = createObject(7);
    int attr = obj.i;
    std::cout << attr << std::endl;

    Object obj1(1);
    Object obj2(2);
    obj1(obj2);
}

/*
    What kind of problem would occur with such code and how would you rewrite it to avoid any
    issue ? Note : no memory leak nor copy is tolerated !
*/