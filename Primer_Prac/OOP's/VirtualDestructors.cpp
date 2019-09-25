#include <iostream>
using namespace std;
class Base
{
    public:
        virtual ~Base()
        {
            std::cout << "Base::destructor called" << std::endl;
        }
};

class Derived : public Base
{
    public:
        ~Derived()
        {
            std::cout << "Derived::destructor called" << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    Base *baseobj = new Base();
    delete baseobj;
    baseobj = new Derived();
    //std::cout << sizeof(objDer);
    delete baseobj;
    return 0;
}