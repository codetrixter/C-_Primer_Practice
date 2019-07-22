/** constexpr function for product of two numbers. 
  *  By specifying constexpr, we suggest compiler to  
  *  to evaluate value at compiler time 
*/

#include <iostream>

using namespace std;

constexpr int product(int x, int y) 
{ 
    return (x * y); 
} 
  
int main() 
{ 
    const int x = product(10, 20); 
    cout << x; 
    return 0; 
} 