class Stuff {
public:
// Atrribute & methods
};

int main(int argc, char const *argv[])
{

    try {
        /* Do somehting */
        throw std::string("error");
    }catch(const char* e) {
        /* handle error */
    }


    return 0;
}
