#include <iostream>
#include <vector>

class NoDefault
{
    public:
    No_default(int val)
    {}
};

class C
{
    public:
    NoDefault mem_default;      //it is not initialized untill C is initilialized.

    C()
    {}
};

int main(int argc, char const *argv[])
{
    std::vector<NoDefault> vec(5);          //valid call as vector does not create any obj of NoDefault.
    std::vector<C> vec_C(4);                //valid
    return 0;
}
