#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum PETS
{
    CAT,
    DOG,
};

// define a parent Error class
class Error
{
private:
    string errorMsg{};

public:
    // Define default constructor with unknown error
    Error() { errorMsg = "Unknown Error."; }
    // Define constructor with parameters creating an error message
    Error(string eMsg) { errorMsg = eMsg; }

    // define a function print(), print the underlying error message to the console
};

// define two specilized error class inheriting the Error class
// 1. PersonAgeError (check if the age is possible 0 - 100)

class Person
{
private:
    float age;
    int lifeExpectancy;
    int intelligence;
    vector<PETS> pets;

public:
    // Construct default constructor with default value
    Person() {}
    // Construct constructor with all necessary parameters age, lifeExp., intell. pets

    // Bonus: ostream operator << print out all person stats
};

int main()
{
    // Create a person with default constructor

    // Create a person with parameters add pets using the enum

    // Create a faulty person and try/catch possible errors defined previously
    try
    {
        
    }
    catch(const std::exception& e)
    {
    }
    
}