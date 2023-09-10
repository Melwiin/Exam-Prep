#include <iostream>

class Tlow {
public:
    int leanCount;
    int drunkCount;
public:
    Tlow(int leanCount = 69) : leanCount(leanCount) { }

    //int operator+(Tlow& other) { return leanCount + other.leanCount; }
};

// External operator overload
int operator+(Tlow& t1, Tlow& t2) {
    return t1.leanCount + t2.leanCount;
}

int operator*(Tlow& t1, Tlow& t2) {
    return t1.leanCount * t2.leanCount;
}

int main(int argc, char const *argv[])
{
    Tlow tlow1;
    Tlow tlow2;

    auto result2 = tlow1 + tlow2;
    auto result3 = tlow1 * tlow2;
    auto result5 = tlow1 / tlow2;

    return 0;
}
