#include <iostream>
using namespace std;

class Test
{
private:
    /* data */
public:
    Test(/* args */);

    void print() {
        std::cout << "test" << std::endl;
    }
    void print(int a) {
        std::cout << "test" << std::endl;
    }

    friend ostream& operator<<(ostream& os, const Test& t);
};


void print() {
    std::cout << "test" << std::endl;
}

void print(int a) {
    std::cout << "test" << std::endl;
}

int main() {
    if(2 == 2)
        if (2 == 2) 
            cout << "test" << endl;
        else 
            cout << "test" << endl;
        
    else cout << "test" << endl;
}