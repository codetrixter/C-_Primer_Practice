#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //1- basic pointer dereferencing.
    /* int a  = 10;
    int *ptr = &a;
    cout << ptr << "\n" << *ptr << endl; */

    //2- null pointer declarations.
    /* int *ptr1 = nullptr;
    int *ptr2 = 0;
    int *ptr3 = NULL;
    cout << ptr1 << "\t" << ptr2 << "\t" << ptr3 << endl; */

    //3- pointers cannot be integers.
    /* int temp = 0;
    int *pp = temp; */      //error: invalid coversion from int to *int.

    //4- does not works
    /* int a = 10;
    short int *lp = &a; */

    //5- valid or not.
    /* int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1;
    cout << i << endl; */

    //6- pointer to a pointer.
    /* char c = 'C';
    char *ptr = &c;
    char **pptr = &ptr;
    cout << c << "\n" << *ptr << "\n" << **pptr << endl; */

    //7- giving a reference to a pointer
    /* double dd = 10.99;
    double *ptr = &dd;
    double *&refPtr = ptr;      //read it from right to left for ease i.e refPtr is a reference to pointer to double.
    cout << dd << "\t" << *ptr << "\t" << *refPtr << endl; */

    //8- const pointer-- a const pointer means the value of a pointer cannot be changed but the value pointed to by pointer can be changed.
    /* int a = 10;
    int *const ptr = &a;

    *ptr = 20;
    cout << *ptr << endl; */

    //int i, *const cp;     cp needs an initialaizer.

    /* const int v2 = 0; int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2,  &r2 = v2;
    r1 = v2;
    p1 = p2;        //does not works as if it would be legal then we could change const v2 valy which should not be possible.
    p2 = p1; */

    return 0;
}
