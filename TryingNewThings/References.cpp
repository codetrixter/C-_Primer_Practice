#include <iostream>
#include <string>

void getName(const bool& status)
{
    std::cout << status << std::endl;
}
int main(int argc, char const *argv[])
{
    std::string s = "Abhishek";
    bool flag = true;
    getName(flag);
    return 0;
}
