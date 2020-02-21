
/**Most std::string implementations (GCC included) use small string optimization. E.g. there's an answer discussing this.
 * Today, I decided to check at what point a string in a code I compile gets moved to the heap. To my surprise, my test code seems to show that no small string optimization occurs at all!
 * Code:
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  std::string s;

  cout << "capacity: " << s.capacity() << endl;

  cout << (void*)s.c_str() << " | " << s << endl;
  for (int i=0; i<33; ++i) {
    s += 'a';
    cout << (void*)s.c_str() << " | " << s << endl;
  }

  cout << "capacity: " << s.capacity() << endl;

}