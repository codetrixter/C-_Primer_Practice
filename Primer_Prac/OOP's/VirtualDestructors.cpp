#include <iostream>
using namespace std;
class Base
{
    public:
        virtual void t()=0;
          ~Base()
        {
            std::cout << "Base::destructor called" << std::endl;
        }
};
 void Base::t()
        {
         std::cout<<"base virtual ";
        }
class Derived : public Base
{
    public:
        void t()
        {

             std::cout<<"Drived  virtual ";
             Base::t();
        }
        ~Derived()
        {
            std::cout << "Derived::destructor called" << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    Derived objDer;
    Base *bobj = &objDer;
    std::cout << sizeof(objDer);
    delete bobj;
    return 0;
}