#include <iostream>

class base
{
    public:
        int mpub;
    protected:
        int mpro;
    private:
        int mpriv;
};

class child : public base
{
    public:
        int func()
        {
            return mpub;
        }

        int func2()
        {
            return mpro;
        }

        int func3()
        {
            return mpriv;       //error: int base::mpriv is private within this context.
        }
};

class child2 : protected base
{
    public:
        int func()
        {
            return mpub;
        }

        int func2()
        {
            return mpro;
        }

        int func3()
        {
            return mpriv;       //error: int base::mpriv is private within this context.
        }
};

class child3 : private base
{
    public:
        int func()
        {
            return mpub;
        }

        int func2()
        {
            return mpro;
        }

        int func3()
        {
            return mpriv;       //error: int base::mpriv is private within this context.
        }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
