#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum PETS {
    CAT,
    DOG,
};

class Error{
private:
    string errorMsg{};
public:
    Error() : errorMsg("Error: something unexpected happend") { }
    Error(string msg) : errorMsg("Error: " + msg) { }
    
    void print() const { cout << errorMsg << endl; }
};

class PersonAgeError : public Error {
public:
    PersonAgeError() : Error("the initialized person has the wrong age") { }
};

class Person {
private:
    float age;
    int lifeExpectancy;
    int intelligence;
    vector<PETS> pets;
public:
    Person(float a = 0, int le = 20, int i = 90, vector<PETS> p = {}) : age(a), lifeExpectancy(le), intelligence(i), pets(p) { }

    float getAge() const { return age; }
    
    friend ostream& operator<<(ostream& os, const Person& p);
};

ostream& operator<<(ostream& os, const Person& p) { 
    os  << "The person is " << p.age << " old, has a intelligence of " 
        << p.intelligence << " IQ points and a life expectency of" << p.lifeExpectancy
        << " furthermore has the person the following pets: \n";
    for (const auto &pet : p.pets) {
        if (pet == CAT) os << "CAT\n";
        else            os << "DOG\n";
    }

    return os;    
}

int main() {
    Person baby;
    Person normalPerson(22.4, 100, 90, {DOG, CAT});
    Person faultyPerson(-20, 40, 20, {DOG, DOG});

    try
    {
        if(0 > faultyPerson.getAge() || faultyPerson.getAge() > 100) throw PersonAgeError();
    }
    catch(const Error& e)
    {
        e.print();
    }
    
}