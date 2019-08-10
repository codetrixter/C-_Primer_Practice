#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    //List initialization (C++11) -- provides type safety.
    //long double ld = 3.14156;
    long long ll = 1000000000;
    int a{ll};  //int a = {ll}; 
    int b(ll);
    //cout << a << b << endl;
    
    // cout << "a really really long string literal that"
    // "spans over the widthof two actual lines of the 24 inch monitor " << endl;
    // cout << "HI \x4dO\115  \n";
    // cout << "Who goes with F\145rgus?\012";
    // return 0;
}
