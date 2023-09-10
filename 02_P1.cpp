#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Person {
private:
    string name;
    size_t age;
public:
    Person(const string& n, const size_t& a): name(n), age(a) {}

    friend Employee;
};

class Employee : public Person {
private:
    double salary;
public:
    Employee(const string& n, const size_t& a, const double& s): Person(n, a), salary(s) { }
 
    void report() const {
        cout << name << " is " << age << " years old and earns " << salary << endl; 
    }
};

int main() {
    Employee e("name", 27, 2334.67);
    e.report();
}
