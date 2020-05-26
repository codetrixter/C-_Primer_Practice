#include <iostream>
#include <map>
#include <iterator>
#include <string>

struct child
{
    int a;
    char c;
}c1;
int main(int argc, char const *argv[])
{
    // std::map<int, child> mping = {
    //     {1, {10, 'a'}},
    //     {2, {20, 'b'}},
    //     {2, {30, 'c'}}
    // };

    std::map<int, std::string> mping;

    // if(mping[4].empty())
    //     std::cout << true;
    // else
    // {
    //     std::cout << false;
    // }
    
    mping[5] = "Abhishek";

    //std::map<int, std::string>::iterator it;
    // it = mping.find(2);
    // std::cout << it->first << std::endl;

    // for(it = mping.begin(); it != mping.end(); ++it)
    // {
    //     std::cout << it->first << "\t" << it->second << std::endl;
    // }

    for(auto item: mping)
    {
        std::cout << item.first << "   " << item.second;
    }
    return 0;
}
