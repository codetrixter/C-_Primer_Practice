#include <iostream>
using std::cout;
using std::endl;

class numbered
{
    public:
        numbered() : mysn(++sn) { cout << "inside ctr()..." << endl;}
        int mysn;


        numbered(const numbered &num):
        mysn(++sn)
        {
            cout << "inside copy constructor()... " << "vlue of mysn sn [" <<  mysn << "]" << endl;
        }

    private:
        static int sn;
};

int numbered::sn = 0;

//if reference of the object is used in the function parameter then the copy constructor will not be invoked.
void f(numbered s)
{
    // `s` is copy initialized from argument, thus `s.mysn` is not the same with
    // the argument we passed in.
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;       //copy cnstructor is called for b and c
    f(a);                           //copy constructor invoked.
    f(b);                           //copy constructor invoked.
    f(c);                           //copy constructor invoked.
    numbered d;
    f(d);                           //copy constructor invoked.

    return 0;
}