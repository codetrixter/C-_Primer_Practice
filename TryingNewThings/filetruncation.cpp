#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char const *argv[])
{
    std::string filePath = "/home/bluegiant/Downloads/1";
    std::fstream myfile(filePath, std::ifstream::binary);
    myfile.open(filePath, std::fstream::binary | std::fstream::out | std::fstream::trunc);

    return 0;
}
