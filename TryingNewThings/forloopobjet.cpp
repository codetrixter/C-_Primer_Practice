#include <iostream>

class abstract
{
    public:
    abstract(int i): count(i)
    {}

    int count;
};

int main(int argc, char const *argv[])
{
    abstract *ab;
    for(int i = 0; i < 5; i ++)
    {
        ab = new abstract(i);
        std::cout << &ab << ab << "\t" << ab->count << std::endl;
    }
        

    std::cout << "Memory address of latest object is " <<  &ab << ab << "\t" << (*ab).count << std::endl;

}
