#include <iostream>
#include <cassert>

using namespace std;

#define assertm(exp, msg) assert(((void)msg, exp))

class Error : public std::exception
{
private:
    std::string msg;
public:
    Error(std::string msg) : msg(msg) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

int main()
{
    double val = 3.14;
    double ref = val;
    
}
