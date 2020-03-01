#include <iostream>

class foo
{
    int a=0;

    ~foo() = delete;
};

int main(int argc, char const *argv[])
{
    foo f;
    return 0;
}

