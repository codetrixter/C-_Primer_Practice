#include <iostream>

class protector
{
    int a;
    void getName();
};

class destroyer
{
    int a;
    char c;
    void getName();
};

class Abhishek
{
    // /Abhishek abhi;                  //gives error as the object can only be created after the class has been defined.
    Abhishek *abhiptr;              //same is not true for references and pointers.
    Abhishek &abhiref;
};

int main(int argc, char const *argv[])
{
    destroyer d;
    std::cout << sizeof(d); 
    return 0;
}
