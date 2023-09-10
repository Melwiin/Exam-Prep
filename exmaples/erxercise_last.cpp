#include <string>
using namespace std;







class Object {
public:
    static string msg;

    int a;
    string b;

    Object(int a, string b) {
        msg = "Test";

        a = a;
        b = b;
    }
};

string Object::msg = "Penis";

int main(int argc, char const *argv[])
{
    

    return 0;
}
