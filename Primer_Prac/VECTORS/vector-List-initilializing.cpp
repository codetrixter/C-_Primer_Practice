#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    std::vector<int> v1(10);            //v1 has ten elements with value 0.
    std::vector<int> v2{10};            //v2 has one element with value 10.
    std::vector<int> v3(10, 1);         //v3 has 10 elements with value 1.
    std::vector<int> v4{10, 1};         //v4 has two elements with values 10 amd 1.
    std::vector<std::string> v5("Abhishek");    //error
    return 0;
}
