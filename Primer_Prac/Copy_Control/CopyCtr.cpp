#include <iostream>
#include <string>

class copy_Demo
{
    public:
    //default constructor
    copy_Demo() = default;

    //copy constructor
    copy_Demo(const copy_Demo&);

    //default copy-assignment operator implementaion
    copy_Demo& operator =(const copy_Demo &rhs)
    {
        std::cout << "inside copy-assignment" << std::endl;
        s = rhs.s;
        a = rhs.a;
        b = rhs.b;

        return *this;
    }

    void setValue(std::string str, int val1, int val2)
    {
        std::cout << "inside the setValue()..." << std::endl;
        s = str;
        a = val1;
        b = val2;
    }

    private:
    std::string s;
    int a;
    int b;
};

//equivalent to default copy constructor
copy_Demo::copy_Demo(const copy_Demo &cd):
s(cd.s),
a(cd.a),
b(cd.b)
{
    std::cout << "inside copy ctr()..." << std::endl;
}

int main(int argc, char const *argv[])
{
    // std::string a(10, '.');                 //direct initialization
    // std::string b(a);                       //direct initialization

    // std::string c = a;                      //copy Initialization
    // std::string d = "9999-9999-99-9999";    //copy Initialization
    // std::string e = std::string(10, '9');   //copy Initialization

    //------------------
    copy_Demo cd;
    cd.setValue("Abhishek", 1993, 20);

    copy_Demo cd2 = cd;         //copy constructor will be called here.
    cd = cd2;                   //copy assignment operator will be called here.

    //Here is assignment operator is returning direct object then copy constructor will be called agin,to avoid that return reference olf the 
    // object.
    return 0;
}
