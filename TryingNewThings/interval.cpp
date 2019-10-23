#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << " 4050 " << std::endl;
    for (int i =4050; i >= 0; i--)
    {
        if((i%1000) == 0)
        std::cout << i << std::endl;
    }
    return 0;
}
