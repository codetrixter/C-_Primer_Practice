#include <iostream>

class pal;

class base
{
    public:
        int mpub;
    protected:
        int mpro;
    private:
        int mpriv;

    friend class pal;
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

    private:
        int j;
};

class pal
{
    public:
        int fun(base b)
        {
            return b.mpriv;
        }

        int fun2(child c)
        {
            std::cout << c.j;       //error as pal is not friends with child class hence it cannot access its private members.
            return c.j;
        }

        int fun3(child c)
        {
            return c.mpriv;  //surprizing but pal can access private mmbers of base even if accessed from subobject of child.
        }
};

class superfriend : public pal
{
    public:

    int mem(base b)
    {
        b.mpro;     //cannot be accessed as friendship doesn't inherit.
    }
};

int main(int argc, char const *argv[])
{
    pal p;
    child cc;
    p.fun2(cc);
    return 0;
}
