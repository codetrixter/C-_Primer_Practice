#include <iostream>
#include <string>

class HasPtr
{
    public:
        //constructor
        HasPtr(const std::string &str = std::string()):
        ps(new std::string(str)), i(0)
        {}
        //copy constructor
        HasPtr(const HasPtr &hp):
        ps(new std::string(*(hp.ps))), i(hp.i)
        {}
        //copy-assignment operator
        HasPtr& operator=(const HasPtr&);
        //destructor
        ~HasPtr()
        {
            delete ps;
        }
    private:
        int i;
        std::string *ps;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    //create a local temp object.
    auto newptr = new std::string(*(rhs.ps));
    //delete the lhs object, if we delete this pointer first and a self assignment is done, then there will be an error.
    delete ps;
    //copy the object from rhs to lhs
    ps = newptr;
    i = rhs.i;

    return *this;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
