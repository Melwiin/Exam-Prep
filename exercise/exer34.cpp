/*For which classes does the stuff method have access to the x attribute ? How would you change
the code so the stuff method has access to the x attribute of each class, and how to access each
attribute separately */
class A {
    int x;
    friend class B;
    friend class C;
};

class B : public A {
    int x;
    friend class C;
};

class C : public B {
    int x;
    void stuff()
    {
        C::x; // von C
        B::x; C::B::x;
        A::x; C::B::A::x; B::A::x;

    }
};

