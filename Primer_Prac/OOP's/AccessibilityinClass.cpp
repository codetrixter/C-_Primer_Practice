#include <iostream>

class parent
{
    protected:
        int mProtected;
};

class derived : public parent
{
    public:
        friend void clobber(derived&);
        friend void clobber(parent&);       //error: int parent::mProtected is protected within this context.
        int j;
};

void clobber(derived &der)
{
    der.j = der.mProtected = 0;
}

void clobber(parent & par)
{
    par.mProtected = 0;
}

int main(int argc, char const *argv[])
{
    // derived derObj1;
    // derived derObj2;
    // derObj1.clobber(derobj2);

    return 0;
}
