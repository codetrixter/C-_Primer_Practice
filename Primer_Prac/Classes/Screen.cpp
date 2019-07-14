#include <iostream>
#include <string>
#include <vector>

//type aliasing... since c++11.
using pos = std::string::size_type;

class Screen
{
    public:
    //typedef std::string::size_type pos;

    Screen() = default;

    Screen(pos wt, pos ht, char c) : width(wt), height(ht), contents(wt * ht, c)        //fill constructor-->fills n consecutive 
    {                                                                                   //copies of char c
    }

    char get() const
    {
        return contents[cursor];
    }

    inline char get(pos ht, pos wd) const;

    Screen &move(pos r, pos c);

    Screen &set(char c);

    Screen &set(pos r, pos co, char c);

    pos size() const;

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

class WindowManager
{
    public:
    std::vector<int> addScreen();
    
    private:
    std::vector<int> number;
    std::vector<Screen> screens{Screen(24, 56, ' ')};               //in-class initializer
};

std::vector<int>
WindowManager::addScreen()
{
    return {0};
}

inline                                      //specifying inline on the definition
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;                    //compute the row location
    cursor = row + c;                       //move cursor to the column within that row.
    return *this;                           //return this object as an lvalue.
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
    ++access_ctr;                           //possible as this memeber is mutable.
}

Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos co, char c)
{
    contents[r*width + co] = c;
    return *this;                       //returning reference of the object on which ths method was called.
}                                       //because of this we can write like myScreen.move(4, 0).set('#)

pos Screen::size() const
{
    return width * height;
}

int main(int argc, char const *argv[])
{
    Screen myScreen;
    Screen temp = myScreen.move(4,0); // the return value would be copied
    temp.set('#'); // the contents inside myScreen would be unchanged

    return 0;
}


