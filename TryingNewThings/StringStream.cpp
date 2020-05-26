#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

int main(int argc, char const *argv[])
{
    std::stringstream ss;
    uint32_t a = 10;
   // bool flag = false;

    ss << a;

    std::cout << ss.str().c_str();
    return 0;
}
