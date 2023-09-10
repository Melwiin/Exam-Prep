#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

namespace TLOW {
    class Klasse
    {
    private:
        int value{};
    public:
        Klasse(int v = 1) : value(v) { }

        int getValue() const { return value; }

        friend ostream& operator<<(ostream& os, Klasse& k);
    };

    ostream& operator<<(ostream& os, Klasse& k) {
        os << "Value: " << k.getValue();
        return os;
    }
}

int main()
{
    TLOW::Klasse k(6);
    cout << k << endl;

    return 0;
}

/* Naming conventions

Classes (CamelCase): class Sniper; class MonkeyMan; class ThisIsCamelCase;
Global constants (ALL CAPS): const double TWO_PI = 6.283; #define CONSTANT 40.f;
Functions (verb + noun): void getValue(); string setHeight()
    -> prefixes: get, set, change, reverse etc...
    -> suffixes: Height, Count, Key, etc...
Or Functions (CamelCase): void SolveEquation(); string GetKeys();

// Stick to one
Variables (CamelCase with lowser-case beginning): int rectLength; double keyCount; // Preferrable
Applicable to CamelCase not SnakeCase (marking specific properties):
    like: static, pointer (most common, especially in classes): int* pKeyCount, static double sHealthStat;


Variables (SnakeCase, all lowercase with _): int rect_length; double key_count;
*/