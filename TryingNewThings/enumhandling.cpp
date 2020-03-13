#include <iostream>

class A
{
    public:
        enum state
        {
            all = 0,
            none = 1,
            some = 2,
        };

};

void function1(A::state temp)
{
    std::cout << temp;
}

int main(int argc, char const *argv[])
{
    A a;
    function1(A::state::some);
    return 0;
}
