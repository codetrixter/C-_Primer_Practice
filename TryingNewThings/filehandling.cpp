#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    std::fstream fileStream("/home/bluegiant/Downloads/image1.jpg");

    if(fileStream.fail())
    {
        std::cout << "file not present";
    }
    else
    {
        std::cout << "file is present";
    }
    
    return 0;
}
