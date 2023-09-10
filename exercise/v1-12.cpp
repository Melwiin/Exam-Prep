#include <iostream>
#include <string>	
using namespace std;

#include <utility>
class Object {};

void babaorum(Object& obj) {} // babaorum n°1
void babaorum(const Object& obj) {} // babaorum n°2
void babaorum(Object&& obj) {} // babaorum n°3
// ... somewhere in main() :

class Object {
    @property 
    value = 2
    @property 
    value2 = 3
    def __init__(self):
        pass
}


int main() {
    Object obj;
    const Object& ref = obj;
    babaorum(ref);
    babaorum(obj);
    babaorum(std::move(obj));
}