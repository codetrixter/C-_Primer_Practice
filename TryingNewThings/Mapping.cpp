#include <iostream>
#include <map>

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
        {3, {30, 'c'}}
    };

    std::map<int, child>::iterator it;
    it = mping.find(2);
    std::cout << it->first << std::endl;
    return 0;
}
