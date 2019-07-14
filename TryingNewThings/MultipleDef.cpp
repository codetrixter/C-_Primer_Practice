#include <iostream>

struct parent
{
    int a = 0;

    parent() {}

};
int main(int argc, char const *argv[])
{
    parent pp;
    std::cout << pp.a;
    int a;
    return 0;
}
