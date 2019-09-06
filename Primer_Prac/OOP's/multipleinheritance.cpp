#include <iostream>

class parent
{
    public:
    virtual void get();
};

class derived1 : public parent
{
    public:
    void get()
    {

    }
};

class derived2 : public derived1
{
    public:
    void get2()
    {
        std::cout << "inside derived 2" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    derived2 p;
    p.get2();

    return 0;
}
