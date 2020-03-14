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

        //swap overload
        void swap(HasPtr &lhs, HasPtr &rhs)
        {
            using std::swap;
            swap(lhs.ps, rhs.ps);
            swap(lhs.i, rhs.i);
        }

        //getter function
        void getDetails()
        {
          std::cout << *ps << '\t' << i << std::endl;
        }

        //setter function
        void setDetails(int number)
        {
            i = number;
        }

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
    HasPtr hp1("Abhishek");
    HasPtr hp2("Ashish");
    hp1.setDetails(100);
    hp2.setDetails(1000);

    std::cout << "Before swapping" << std::endl;
    hp1.getDetails();
    hp2.getDetails();

    hp1.swap(hp1, hp2);

    std::cout << "After swapping" << std::endl;
    hp1.getDetails();
    hp2.getDetails();

    return 0;
}
