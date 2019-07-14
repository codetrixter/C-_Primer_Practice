#include <iostream>
#include <string>

/* typedef double Money;
std::string bal;

class Account
{
    public:
    int balance(Money mm)               //Money type is atken from the global scope as the return type names must be resolved before use.
    {
        Money mm = 10.00;               //name Money is resoved from the in class declaration
        return 0;
    }            

    private:
    //typedef double Money;
    Money bal;
}; */

typedef std::string Type;
Type initVal();

class Exercise 
{
    public:
    //typedef double Type;
    Type setVal(Type);
    Type initVal();

    private:
    std::string val;
};

Type Exercise::setVal(Type parm) 
{
    val = parm + initVal();
    return val;
}

int main(int argc, char const *argv[])
{ 
    return 0;
}
