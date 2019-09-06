#include <iostream>

class Base
{
    public:
        virtual int fnc()
        {
            std::cout <<"Base::";
            return 0;
        }

        virtual ~Base(){}
};

class D1 : public Base
{
    public:
        int fnc(int)
        {
            std::cout << "Derived1::";
            return 0;
        }
        virtual void f2()
        {
            std::cout << "Derived1::f2()";
        }

};

class D2 : public D1
{
    public:
        int fnc(int);
        int fnc()
        {
            std::cout << "Derived2::";
            return 0;
        }
        void f2()
        {
            std::cout << "Derived2::f2()";
        }
};

int main(int argc, char const *argv[])
{
    Base bobj; D1 d1obj; D2 d2obj;
    Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
    bp1->fnc();         //calls base::fnc()
    bp2->fnc();         //calls base::fnc()
    //bp2->f2();          //error: class base has no member named f2()
    bp3->fnc();         //calls D2::fnc()
    D1 *do1 = &d1obj;
    D2 *do2 = &d2obj;
    do1->f2();        //calls Derived1::f2()
    do2->f2();        //calls Derived2::f2()
    
    return 0;
}
