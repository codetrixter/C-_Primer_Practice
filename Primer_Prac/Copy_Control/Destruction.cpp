#include <iostream>
#include <memory>
#include <vector>

class destructing
{
    public:
    ~destructing()
    {
        std::cout << "Start destroying..." << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    destructing *d1 = new destructing;              //d1 is built-in pointer.
    auto ptr = std::make_shared<destructing>();     //ptr is a shared pointer.
    destructing d2(*d1);                            //copy constructor is called.
    std::vector<destructing> vec;                   //local variable
    vec.push_back(*ptr);                            //object pointer by ptr is pushed in the vector.
    delete d1;                                      //destructor called on the object pointed by d1.
    return 0;
}
/**
 * out of scope, hence destructor called on d1, ptr and vec.
 * destroying vec destroys elements in vec.
 * destroying ptr decreases its use count, once it reaches zero the object is freed.
 */
