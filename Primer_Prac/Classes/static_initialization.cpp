#include <iostream>
#include <vector>

// class Megatron
// {
//     public:

//     // static double rate();
//     // static void rate(double);
//     // static float percentage;

//     static Megatron mm;     //allowed to have incomplete type.
//     void printname(int a = value);          //used as a default argument.

//     private:
//     // static constexpr int period = 20;
//     // double daily_tbl[period];
//     static int value;
// }; 

// //definition of percentage.
// //float Megatron::percentage = 0;         //if not defined then linking error comes.

// //definition of a static member.
// //constexpr int Megatron::period;

// int main(int argc, char const *argv[])
// {
//     //Megatron::percentage = 10;          //Linking error: if definition is absent.
//     return 0;
// }


// example.h
class Example 
{
    public:
    static constexpr double rate = 6.5;
    //static const int vecSize = 20;
    static std::vector<double> vec;
};
// example.C
//double Example::rate;
std::vector<double> Example::vec;

int main(int argc, char const *argv[])
{
    
    return 0;
}
