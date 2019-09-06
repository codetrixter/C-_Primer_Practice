#include <iostream>

class Base
{
    public:
        static void statemen(){}
};

class Derived : public Base
{
    public:
    void f(const Derived &);
};

void Derived::f(const Derived &dr_obj)
{
    Base::statemen();       //base defines statemen.
    Derived::statemen();    //Derived inherits statemen.
    dr_obj.statemen();      //access via derived object.
    statemen();             //accessed  via this object.
}
int main(int argc, char const *argv[])
{
    Derived d;
    Derived *b = new Derived();
    b->f(d);
    return 0;
}
