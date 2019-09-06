#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>

// enum mesgType
// {
//     DEQ = 27,
//     VWCW = 30
// };

void getName(std::vector<int> vec)
{
    std::cout << "inside getName..." << std::endl;
    
}

int main(int argc, char const *argv[])
{
    std::vector<int> vecIter;
    ::getName(std::vector<int>());

    //---------------------------------
    std::set<int> setVal;
    //std::vector<int> newvec;
    std::map<int, std::set<int>> mapping;
    setVal.insert(100);
    setVal.insert(200);

     //elements with duplicate key is inserted only once
    mapping.insert(std::pair<int, std::set<int>>(10, setVal));     
    mapping.insert(std::pair<int, std::set<int>>(10, setVal));

    std::map<int, std::set<int>>::iterator it;
    std::set<int>::iterator setIT;

    for(it = mapping.begin(); it != mapping.end(); ++it)
    {
        std::cout << it->first;

        for(setIT = it->second.begin(); setIT != it->second.end(); ++setIT)
        {
            std::cout << "\t" <<*setIT;
        }

        std::cout << std::endl;
    }

    return 0;
}
