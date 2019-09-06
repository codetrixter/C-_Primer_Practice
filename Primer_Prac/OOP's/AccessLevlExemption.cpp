#include <iostream>

class base
{
    public:
        int n;
};

class derived : private base
{
    public:
        using base::n;
};

class subDerived : public derived
{
    int function(subDerived sd)
    {
        return sd.n;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
