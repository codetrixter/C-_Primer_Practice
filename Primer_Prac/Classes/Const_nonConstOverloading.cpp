#include <iostream>
#include <string>

class Screen
{
    public:

    Screen(int a)
    {

    }

    Screen &set(char c)
    {
        contents[cursor] = c;
        return *this;
    }

    //type aliasing... since c++11.
    using pos = std::string::size_type;

    //overloading display method to return const obect and non-const oblect.
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this; 
    }

    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

    private:
    void do_display(std::ostream &os) const
    {
        os << contents;
    }

    pos width = 0;
    pos height = 0;
    pos cursor = 0;
    std::string contents;
    mutable size_t access_ctr;                                                          //this member can be changed even by
};                                                                                      //const memeber function or object.

int main(int argc, char const *argv[])
{
    //calling display which in turn calls do_display.
    Screen myScreen(10);
    const Screen blank(10);
    auto x = myScreen.set('#').display(std::cout);            //calls the non const 
    auto x1 = blank.display(std::cout);                        //calls the const version of the display 
    return 0;
}
