#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

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

    auto result = std::find_if(std::begin(mping), std::end(mping),
                [&](const std::pair<int, child> &pair)
                {
                    return pair.second.a == 20;
                });

    if(result != std::end(mping))
    {
        int key = result->first;
        std::cout << key;
    }
    return 0;
}
