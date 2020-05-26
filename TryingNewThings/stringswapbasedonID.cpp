#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include <sstream>

class test
{

public:

struct alpha
{
    int UID;
    std::string name;
}qq;

struct beta
{
    int CatID;
    std::string catName;
} b1;

struct theta
{
    int CatID;
    std::string catName;
} bb;
std::deque<alpha> qAlpha;
    

    std::vector<beta> vecBeta = {{5000, "Abi"},
                                 {3000, "Hari"},
                                 {2000, "Mahaveer"},
                                 {5000, "Dinesh"},
                                 {2000, "Mahaveer"}};
//void filetr(qAlpha);
void sorting()
{
    qAlpha.push_back({3000, "Abhishek"});
    qAlpha.push_back({2000, "Ashish"});
    qAlpha.push_back({2000, "Ashish"});
    qAlpha.push_back({500, "sunil"});
    std::sort(qAlpha.begin(), qAlpha.end(),
              [](alpha &faa, alpha &saa) {
                  return (faa.UID < saa.UID);
              });

    qAlpha.erase(std::unique(qAlpha.begin(), qAlpha.end(),
                             [](alpha &faa, alpha &saa) {
                                 return ((faa.UID == saa.UID) && (faa.name == saa.name));
                             }));

    qAlpha = filetr(qAlpha);
}

std::deque<alpha> filetr(std::deque<alpha> &qq)
{
    std::stringstream logstream;
    for (beta &bb : vecBeta)
    {
        std::deque<alpha>::iterator it = std::find_if(qAlpha.begin(), qAlpha.end(),
                                                      [&bb](alpha &aa) {
                                                          return ((aa.UID == bb.CatID) && (aa.name != bb.catName));
                                                      });

        if (it != qAlpha.end())
        {
            it->name = bb.catName;
        }
    }

    for (auto it = qAlpha.begin(); it != qAlpha.end(); ++it)
    {
        logstream << it->UID << "  " << it->name << " || ";
        //std::cout << it->UID << "  " << it->name << std::endl;
    }

    logstream << "\n";
    std::cout << logstream.str();

    logstream = std::stringstream();

    for (auto it : vecBeta)
    {
        logstream << it.CatID << it.catName;
    }

    std::cout << logstream.str();

    return qq;
}


};
int main(int argc, char const *argv[])
{
    test t1;
    t1.sorting();


    return 0;
}
