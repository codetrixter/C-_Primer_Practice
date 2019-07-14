#include <iostream>

void func1()
{
    std::cout << "func1"; 
}

void func2()
{
    std::cout << "func2"; 
}

int main(int argc, char const *argv[])
{
    (void) func1();
    func2();    
    return 0;
}
