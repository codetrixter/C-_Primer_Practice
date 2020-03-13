#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

class abstract
{
    public:
    abstract(int i): count(i)
    {}

    ~abstract()
    {
        std::cout << "Destructor called..." << std::endl;
    }

    int count;
};

void* operator new(size_t size)
{
    std::cout << "Allocating memory = " << size << "bytes" << std::endl;
    return malloc(size);
} 

int main(int argc, char const *argv[])
{ 
    abstract *ab;

    for(int i = 0; i < 5; i ++)
    {
        //ab = new abstract(i);
        std::shared_ptr<abstract> abShared(new abstract(i));
        //std::cout << &ab << "" << ab << "\t" << ab->count << std::endl;
        std::cout << abShared << "\t" << abShared->count << std::endl;
    }//destructor for ab is called here.

    //delete ab;
    //std::cout << "Memory address of latest object is " <<  &ab << "\t" << ab << "\t" << (*ab).count << std::endl;
}
