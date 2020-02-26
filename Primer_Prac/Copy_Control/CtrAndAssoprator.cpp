#include <iostream>
#include <cstring>

using namespace std;

class buggyclass {
public:
   char *aString;
public:

  buggyclass() {aString = NULL;}

  buggyclass(char *s) {
     aString = new char[strlen(s)+1];
     cout << "Memory address of aString is " << &aString << endl;  
     strcpy(aString,s);
  }

  // buggyclass(const buggyclass& b)            // copy constructor, identical to
  // {                                          // default provided by C++
  //   cout << " In copy constructor " << endl;
  //   cout <<  "Address of current obj : [" << this->aString << "] Memory address of temp obj is " << &b << endl;         //pointing to the original object i.e rpi.

  //   aString = b.aString;                     // what's wrong with this?
  // }

  //This copy constructor does a deep copy of the object hence avoid the same object from being deleted twice.
  buggyclass(const buggyclass &b)
  {
    cout << "inside copy constructor..." << endl;
    if(b.aString != NULL)
    {
      aString = new char[strlen(b.getstring())+1];
      cout << "Memory address of local aString is " << &aString << endl;

      strcpy(this->aString, b.getstring());
    }
    else
    {
      aString = NULL;
    }
  }

  ~buggyclass() {
    cout << " In buggyclass destructor, deleting memory at address " <<
      &aString << endl;
     if (aString != NULL) delete [] aString;
  }

  char *getstring() const  {            // eventually needs to be a const function
      char *retval = new char[strlen(aString)+1];
      strcpy(retval, aString);
      return retval;
  }
};

//2- We can also pass reference of the class object which will prevent from the double deetion of the object.
void afunction(buggyclass b)
{
  cout << "Memory address of temp object b is " << &b << endl;            //temp object address
  cout << "value of aString of temp object is " << b.aString << endl;

  cout << "In afunction, b is " << b.getstring() << endl;
} //destructor for temp object is called here. Here when the temp member variable is deleted then, since the pointers
  //are same for both class object and temp object hence next time when we try to access the aString it is empty.

int main()
{
   buggyclass rpi("Rensselaer");  // create an instance of the class
   cout << "address of rpi object is " << &rpi << endl;

   cout << "*******************Before first call********************" << endl;
   afunction(rpi);  

   cout << "*******************Before second call*******************" << endl;
   afunction(rpi);

   cout << "xxxxxxxxxxxxxxxxxxxAbout to exitxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
   return 0;
}