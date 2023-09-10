#include <iostream>

using namespace std;

class Error{
public:
    Error() = default;
    virtual string getErrorMessage() const {
        return "Error: unknown error";
    }
};

class WrongInputError : public Error {
public:
    WrongInputError() = default;
    string getErrorMessage() const override {
        return "WrongInputError: input isn't an integer";
    }
};

class DenomError : public Error{
public:
    DenomError() = default;
    string getErrorMessage() const override  {
        return "DenomError: denomination is equal to 0";
    }
};

int main()
{   
    int denom;
    int num;


    try
    {
        cout << "Type in denominator: ";
        if(!(cin >> denom)) throw WrongInputError();
        if (denom == 0) throw DenomError();
        cout << "Type in numerator: ";
        if(!(cin >> num)) throw WrongInputError();
        cout << "Result: " << (float)num/(float)denom << endl;
    }
    catch(const Error& e)
    {
        cout << e.getErrorMessage() << endl;
    }
    

    return 0;
}
