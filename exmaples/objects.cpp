class Object{
private:    
    @property
    string name;
public:
    babaorum() { }
}

int main(int argc, char const *argv[])
{
    Object obj;
    babaorum(obj);

    const Object& obj2(obj);
    babaorum(obj2);

    return 0;
}
