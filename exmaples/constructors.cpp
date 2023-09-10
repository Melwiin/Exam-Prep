#include <iostream>


class Apple {
private:
    int *weight;
    int color;
public:
    Apple(int weight, int color) : weight(weight), color(color) { };
    Apple() : weight(0), color(0) { };

    Apple(const Apple& other) = delete;
    Apple(Apple&& other) {
        this->weight = other.weight;
        this->color = other.color;
        delete other.weight;
        other.color = 0;
    }
};

int main(int argc, char const *argv[])
{
    Apple apple1(1, 2);
    Apple apple2(move(apple1));

    return 0;
}
