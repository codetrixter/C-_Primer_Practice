#include <iostream>

class swapping
{
    public:
        swapping() = default;

        swapping(const swapping &sw) = default;

        swapping& operator=(swapping rhs)
        {
            swap(*this, rhs);

            return *this;
        }

        void swap(swapping &to, swapping &from)
        {
            //swapping *toptr = to, *fromptr = from;
            swapping *tempptr = &fromptr;
            fromptr = toptr;
            toptr = tempptr;
        }
    
    ~swapping()
    {
        std::cout << "Destruction...";
    }
    private:
        int a;
};

int main(int argc, char const *argv[])
{
    swapping sw1;
    swapping sw2 = sw1;
    return 0;
}
