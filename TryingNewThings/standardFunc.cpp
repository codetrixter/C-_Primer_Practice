#include <iostream>
#include <functional>

class funk
{
    public:
    funk(int num): number(num)
    {}

    void increase(int num)
    {
        std::cout << num++;
    }

    void funking()
    {
        std::function<void(int)> ptr_increase1 = std::bind(&funk::increase, this, std::placeholders::_1);
        ptr_increase1(10);
        std::function<void(int)> ptr_increase2 = std::bind(&funk::increase, this, std::placeholders::_1);
        ptr_increase2(10);
    }

    private:
    int number;
};

int main(int argc, char const *argv[])
{
    funk *ff = new funk(10);
    ff->funking();
    return 0;
}
