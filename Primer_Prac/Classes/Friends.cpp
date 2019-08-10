#include <iostream>

class Beta;

class Alpha
{
    int a = 10;

    public:
    Alpha()
    {
    }

    int printMembers()
    {
        return  this->a;
    }

    friend void printname(Alpha, Beta);

    //friend class Beta;
};

class Beta
{
    int b = 20;
    public:
    Beta()
    {
    }

    void getAccess(Alpha aa)
    {
        std::cout << aa.printMembers();             //can be accessed by a function having access to a private member.
        //std::cout << aa.a;                          //this cannot happen unless Beta is made friend of Alpha.
    }

    friend void printname(Alpha, Beta);
};


//Global function that is accessing private membrers from both Beta and Alpha classes.
void printname(Alpha alp, Beta bta)
{
    std::cout << "frient of class Alpha"; 
    std::cout << alp.a;
    std::cout << bta.b;
}

int main(int argc, char const *argv[])
{
    Alpha a1;
    Beta b2;
    //std::cout << b2.a;
    //printname(a1, b2);
    b2.getAccess(a1);
    return 0;
}
