#include <iostream>

void getName(const bool& status)
{
    std::cout << status << std::endl;
}
int main(int argc, char const *argv[])
{
    bool flag = true;
    getName(flag);
    return 0;
}
