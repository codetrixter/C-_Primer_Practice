#include <iostream>
#include <fstream>
#include <string>

void writeIn(std::ostream &os, const std::string &str)
{
    os << str  << "\n";
}

int main(int argc, char const *argv[])
{
    std::ofstream file("Abhishek.txt", std::ios_base::trunc);
    for(int i = 0; i < 1000000; i++ )
        writeIn(file, "Hello Guys");

    return 0;
}
