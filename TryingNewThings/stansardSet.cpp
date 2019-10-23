#include <iostream>
#include <set>
#include <list>
#include <iterator>
#include <algorithm>

struct message
{
    int id;
    int distance;
}mesg1;

std::list<message> mesgList;

int main(int argc, char const *argv[])
{
    bool flag = false;
    mesgList = {{111, 10},
                {2222, 20},
                {333, 30}};
    std::set<int> integerSet = {1, 2, 3, 222, 333};

    for(auto &item: integerSet )
    {
        //std::cout << item << std::endl;
        std::list<message>::iterator it = std::find_if(mesgList.begin(), mesgList.end(), 
                                                    [&item](message &mList)
                                                    {
                                                        return ((item == mList.id) && (mList.distance >=0));
                                                    });
        if(it != mesgList.end())
        {
            std::cout << "found..." << item << std::endl;
            flag = true;
        }
    }
    if (flag == false)
    {
        std::cout << "not found..." <<std::endl;
    } 
    return 0;
}
