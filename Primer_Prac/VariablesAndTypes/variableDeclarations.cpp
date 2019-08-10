/**
 * program showing various nuances of how to use variables in Static typed c++ language.
 */


#include <iostream>

using namespace std;

std::string global_str;     //global variables get default values.
int global_int = 1999;             //declaration and definition of the variable.

extern int b = 1222;    //not an error but a warning.

int main()
{
// int local_int;              //local variables should be initialized while declaration.
// std::string local_str;      //declaration and definition of the variable
// //extern int bb = 1231;     //error .

// extern int a;   //declaration of the variable. 

// cout << "GLOBAL VARIABLES :"<< global_str << global_int << endl;
// cout << "LOCAL VARIABLES :"<< local_str << local_int << endl;

//small  programm
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
sum += i;
std::cout << i << " " << sum << std::endl;

}