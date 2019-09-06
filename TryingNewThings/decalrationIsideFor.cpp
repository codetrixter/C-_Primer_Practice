#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 0; float dd = 20.20;
    for( i = 0, dd = 2.22;i<10;++i, ++dd)
    {
        std::cout << "Hello" << i << "  " << dd;
    }
    return 0;
}
