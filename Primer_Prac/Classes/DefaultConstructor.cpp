#include <iostream>
#include <string>
#include <fstream>

class Office
{
    public:

    Office(): Office("", 0, 0)
    {}

    // Office(std::string str = ""): bookNo(str)
    // {} 

    Office(std::string str, int cnt, double rev): bookNo(str), units_sold(cnt), revenue(rev)
    {}

    Office(std::istream &is)
    {
        //std::read(is, *this);
    }

    public:
    std::string bookNo;
    int units_sold;
    double revenue;
};

//--------------------------

// class No_default
// {
//     public:
//     No_default(std::string &s);
// };

// struct A
// {
//     No_default mem_A;       //
// };
// A a;        //error:: cannot synthesize a constructor for A
// struct B
// {
//     B() {}
//     No_default mem_B;       //error::no initializer for A.
// };

//----------------------------

int main(int argc, char const *argv[])
{
    Office off1;
    //Office off2("abhishek");
    return 0;
}
