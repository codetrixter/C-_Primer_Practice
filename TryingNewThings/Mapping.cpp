#include <iostream>
#include <map>
#include <iterator>

struct child
{
    int a;
    char c;
}c1;
int main(int argc, char const *argv[])
{
    std::map<int, child> mping = {
        {1, {10, 'a'}},
        {2, {20, 'b'}},
        {2, {30, 'c'}}
    };

    std::map<int, child>::iterator it;
    // it = mping.find(2);
    // std::cout << it->first << std::endl;

    for(it = mping.begin(); it != mping.end(); ++it)
    {
        std::cout << it->first << "\t" << it->second.a << std::endl;
    }
    return 0;
}
