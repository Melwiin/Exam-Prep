/*
    How should you modify this code for the id variable to get the expected value (i.e id==2) ?
*/
#include <iostream>

class Generic {
private:
    int i;
public:
    virtual int id() { return 1; }
};

class Specialized : public Generic {
public:
    int c;
private:
    int id() { return 2; }
};

int main() {
    Specialized obj;
    Generic &ref = obj;

    auto id = ref.id();
    std::cout << "ID:" << id << std::endl;
}