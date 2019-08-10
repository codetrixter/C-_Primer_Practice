#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // decltype(c++11)
    /* int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d; */

    /* int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;      //(a = b) deduced to reference of int */

    return 0;
}
