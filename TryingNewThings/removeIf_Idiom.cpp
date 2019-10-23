#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

int main()
{
    std::string str1 = "Text with some   spaces";
    //str1.erase(std::remove(str1.begin(), str1.end(), ' '),str1.end());
    //std::remove(str1.begin(), str1.end(), ' ');
    std::cout << str1 << '\n';

    std::string str2 = "Text\n with\tsome \t  whitespaces\n";
    std::cout << "------------ BEFORE ------------\n";
    std::cout << str2 << '\n';
    std::cout << "------------ AFTER ------------\n";

#if 1
    str2.erase(std::remove_if(str2.begin(),
                              str2.end(),
                              [](unsigned char x){return std::isspace(x);}),
               str2.end());
#else
    std::remove_if(str2.begin(), 
                              str2.end(),
                              [](unsigned char x){return std::isspace(x);});
#endif


bool found = (10 == 0) && (20 == 20);
std::cout << found << std::endl;
    std::cout << str2 << '\n';
}