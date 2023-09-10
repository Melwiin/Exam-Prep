class A {
protected:
    int x;
};
class B: public A {
protected:
    int x;
};

class C: public B {
private:
    int x;
    void stuff() {
        // C
        this->x;
        //B
        B::x;
        //C
        A::x;
    }
};

/*For which classes does the stuff method have access to the x attribute ? How would you change
the code so the stuff method has access to the x attribute of each class, and how to access each
attribute separately */

// Can only access x variable of C.