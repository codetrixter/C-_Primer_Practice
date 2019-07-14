#include <iostream>

struct shape1
{
    int a;
    char b;
};

class shape2
{
    public:
    int abhi = 10;
    char charrr = 'a';
};

int main(int argc, char const *argv[])
{
    // shape1 ss = {10, 'a'}, ss1 = {20, 'l'};
    // std::cout << "address of struct1 is:" << &ss << "\n" << &ss.a << "\n" << &(ss.b) << std::endl;
    // std::cout << "address of struct2 is:" << &ss1 << "\n" << &ss1.a << "\n" << &(ss1.b) << std::endl;   

    shape2 shaping1, shaping2;
    std::cout << "address of obj shaping1 is:" << &shaping1 << "\n" << &shaping1.abhi << "\n" << (void*)&shaping1.charrr << std::endl;
    std::cout << "address of obj shaping2 is:" << &shaping2 << "\n" << &shaping2.abhi << "\n" << (void*)&shaping2.charrr << std::endl;
    return 0;
}
