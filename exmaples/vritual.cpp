class Virtual
{
public:
    Virtual();

    virtual void method2() = 0;
    virtual void method3() = 0;
};

class Pet : Virtual {
public:
    Pet() : Virtual() { }

    void method1() { }
    void method2() override { }
    void method3() override { }
};

class Human : Virtual {
public:
    Human() : Virtual() { }

    void method1() { }
    void method2() override { }
    void method3() override { }
};
int main(int argc, char const *argv[])
{
    Virtual* test;
    test = new Pet();
    test->method1();
    test = new Human();
    test->method1();
    
    return 0;
}
