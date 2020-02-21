#include <iostream>

class parent
{

};

int main(int argc, char const *argv[])
{
    parent p1;                  //given memory on stack.
    parent *p2 = new parent;    //given memory on heap.

    std::cout << &p1 << "\t" << p2 << std::endl;
    
    return 0;
}
