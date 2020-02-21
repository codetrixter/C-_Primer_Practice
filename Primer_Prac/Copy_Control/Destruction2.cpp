#include <iostream>

class box
{
    public:

    box create(box bb)
    {
        box temp = bb;
        return temp;
    }

    ~box()
    {
        std::cout << "detsruct()....." << std::endl;
    }

    int a;
};
int main(int argc, char const *argv[])
{
    box local, paramObj;
    local.create(paramObj);

    std::cout << paramObj.a << std::endl;

    return 0;
}
