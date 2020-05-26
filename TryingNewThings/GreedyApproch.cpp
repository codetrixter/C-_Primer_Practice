#include <iostream>
#include <vector>
#include <algorithm>


int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        
        int satisfied = 0;
        std::sort(g.begin(), g.end(), std::greater<int>());
        std::sort(s.begin(), s.end(), std::greater<int>());
        // for(auto i = s.begin(); i != s.end(); ++i)
        // {
        //     for(auto j = g.begin(); j != g.end(); ++j)
        //     {
        //         if(*i >= *j)
        //         {
        //             ++satisfied;
        //             g.erase(j);
        //             break;
        //         }
        //     }
        // }
        auto i = s.begin(), j = g.begin();
        while(  (i != s.end()) && (j != g.end()) )
        {
            if(*i >= *j)
            {
                ++satisfied;
                ++i;
                ++j;
            }
            else
            {
                ++j;
            }
        }
        return satisfied;
    }


int main(int argc, char const *argv[])
{
    std::vector<int> g = {1, 2, 3}, s = {1, 1};
    std::cout << findContentChildren(g, s);
    return 0;
}
