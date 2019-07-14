#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    /* string a ;
    cin >> a;       //accepts input only till a space is enetered
    cout << a; */

    //1-> taking multiple word input without spaces
    /* string s;
    while(cin >> s)         //cin reads the input string till the space is encountered. It will keep on taking input untill we pass EOF(Ctrl+z)
    {
        cout << s << endl;      // all the data will be pumped to console at once as the cin has a buffer which is sent for processing as we press "Enter".
    } */

    //2-> taking multiple line input.
    /* string line;
    while(getline(cin, line) )      //takes sapces and prints them
    {
        cout << line << endl;       //we must put newline as the newline pushed while pressing enter is discarded.
    } */

    //3-> size() call of string library.
    /* string line;
    while(getline(cin, line))
    {
        if(line.size() > 20)
        {
            cout << line << endl;
        }
    }
    auto a = line.size(); */

    return 0;
}
