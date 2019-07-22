#include <iostream>

class Thanos
{
    public:
    int a;
    float j;
    const int x;
    double &rr;

    Thanos(int value): j(value), a(j)       /* a is initialized with zero because in initializer list the sequence of initialization
                                            depends on the sequence of declaration of the member variables in the class wrather 
                                            than the sequence of the initializer list.*/
    {}                

    Thanos(int value)
    {
        a = value;
        j = value;
        //x = value;                  //error, need to be initialized not assigned.
        //rr = value;                 //error
    }                      
};

int main(int argc, char const *argv[])
{
    Thanos tt(10);
    std::cout << tt.j <<"\t" << tt.a << std::endl;
    return 0;
}
