// #include <iostream>
// #include <string>
// using namespace std;

// class ClassA
// {
//    int a, b;
//      public:
//    ClassA()
//    {
//      a = 10;
//      b = 20;
//    }
//    ClassA(ClassA &obj)
//    {
//     cout << "copy constructor called" << endl;
//    }
//  };

//  ClassA function (ClassA &str)
//  {
//      std::cout << "inside function()...." << std::endl;
//   return str;
//  }

//  int main ()
//  {
//    ClassA str;
//    function(str);
//    return 0;
//  }


#include <iostream>

class copyCtr
{
    public:
    copyCtr() = default;

    copyCtr(const copyCtr&)
    {
        std::cout << "default copy constructor called" << std::endl;
    }

    copyCtr returning(int variable)
    {
        copyCtr demo3;
        std::cout << variable << std::endl;
        return demo3;
    }

    copyCtr function2(copyCtr &param)
    {
        return param;
    }

    private:
    int a;
    char b;
};

void function(copyCtr param)
{
    std::cout << "inside function() .." << std::endl;
}

int main(int argc, char const *argv[])
{
    copyCtr demo;

    // 1 --> copy constructor is called as we are creating an object with an existing object.
    copyCtr demo2 = demo;

    demo2.returning(100);

    // 2 --> copy constructor is called which copies the content of the argument to the parameter of the function.
    function(demo2);

    // 3 --> copy constructor called when returning the object form the function2().
    demo.function2(demo2);
    return 0;
}
