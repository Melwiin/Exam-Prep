#include <iostream>

using namespace std;

class Error {
    string errorMessage;
public:
    Error(const string& errorMessage) : errorMessage(errorMessage) {}

    void what() const {
        cout << errorMessage << endl;
    }
};

class MyException : public Error {
public:
    MyException(const string& errorMessage) : Error("MyException: " + errorMessage) { }
};

int main(int argc, char const *argv[])
{
    try
    {
        /* Do something */
        throw MyException("Something went wrong!");
        throw Error("Something went wrong!");
        /* Do something */
    }
    catch(Error& e)
    {
        /*Handle error*/
        e.what();
    }
    
    return 0;
}
