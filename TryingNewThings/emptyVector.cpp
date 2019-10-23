#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    std::vector<int> myvec = {};
    for(int i: myvec)
    {
        std::cout << i;
    }

    std::cout << "\n" << myvec.size();
    std::string ss = "abi";
    std::printf("%s", ss.c_str());
    return 0;
}
