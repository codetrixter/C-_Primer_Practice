#include <iostream>
using namespace std;
class buggyclass 
{
private:
   char *aString;
public:
  buggyclass() {aString = NULL;}
  buggyclass(char *s) {
     aString = new char[strlen(s)+1];
     strcpy(aString,s);
  }
  buggyclass(const buggyclass& b)            // copy constructor, identical to
  {                                          // default provided by C++
    cout << " In copy constructor " << endl;
    aString = b.aString;                     // what's wrong with this?
  }
  ~buggyclass() {
    cout << " In buggyclass destructor, deleting memory at address " << 
      (int)aString << endl;
     if (aString != NULL) delete [] aString;
  }

  char *getstring() {            // eventually needs to be a const function
      char *retval = new char[strlen(aString)+1];
      strcpy(retval, aString);
      return retval;
  }
};

void afunction(buggyclass b) 
{
    cout << "  In afunction, b is " << b.getstring() << endl;
}

int main()
{
   buggyclass rpi("Rensselaer");  // create an instance of the class
       cout << "Before first call" << endl;
afunction(rpi);  
cout << "Before second call" << endl;
  afunction(rpi);
   cout << "About to exit" << endl;
   return 0;
}