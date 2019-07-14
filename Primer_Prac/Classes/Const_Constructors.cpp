#include <iostream>

class parent
{
    public:
    //cannot add const to a constructor.
    constexpr parent(int a)
    {
        std::cout << "Hello constructor" << std::endl;
    }
};
int main(int argc, char const *argv[])
{
    parent p(10);
    return 0;
}
