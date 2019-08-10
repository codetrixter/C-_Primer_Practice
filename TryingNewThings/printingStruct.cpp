#include <iostream>
#include <sstream>

struct dummy
{
    int a = 10;
    double dl = 10.00;
};
int main(int argc, char const *argv[])
{
    std::stringstream logStream;
    dummy dd1 = {230, 253.222};
    logStream << dd1.a;
    std::cout << logStream.str().c_str();
    return 0;
}
