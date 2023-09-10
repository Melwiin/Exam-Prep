#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Person {
    string name;
    size_t age;

public:
    Person(const string& n, const size_t& a): name(n), age(a) {}
    void speak() const {
        cout << "Hi my name is " << name << " and I'm " << age << " years old" << endl;
    }
};

class Student: public Person {
public:
    Student(const string& name, const size_t& age) : Person(name, age) { }
    void speak() const {
        Person::speak();            // Must call parent method ! 
        cout << "And I love drinking bier !" << endl;
    }
};

int main() {
    Student s("Jack", 27);
    s.speak();
}
