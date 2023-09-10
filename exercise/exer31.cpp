/* 
    Implement the base, default and copy constructor for the following class. They should use an
    initialization section, and output in the console the memory address of the object, using a specific
    message differentiating each constructor. 
*/

#include <iostream>

using std::cout, std::endl;

class Stuff {
private:
    double value;
    int number;
public:
    Stuff() : value(0), number(0) {
        std::cout << "Default constructor called. Address: " << this << std::endl;
    }
    Stuff(double value, int number) : value(value), number(number) {
        std::cout << "Base constructor called. Address: " << this << std::endl;
    }
    Stuff(const Stuff& other) : value(other.value), number(other.number) {
        std::cout << "Copy constructor called. Copied to " << this << " from: " << &other << std::endl;
    }
};
