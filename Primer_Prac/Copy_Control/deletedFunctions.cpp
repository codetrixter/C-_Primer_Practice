#include <iostream>

// class deleteKeyword
// {
//     public:
//         deleteKeyword() = default;

//         deleteKeyword (const deleteKeyword&) = delete;              //copy constructor cannot be used anymore.
//         deleteKeyword& operator=(const deleteKeyword&) = delete;    //assignment cannot be done anymore.
//         ~deleteKeyword()
//         {
//         }
// };

class dynamicAlloc
{
    public:
        dynamicAlloc() = default;
        ~dynamicAlloc() = delete;
};

int main(int argc, char const *argv[])
{
    dynamicAlloc *da1 = new dynamicAlloc();     //we can dynamically allocate the member of a type that has a deleted destructor.
    dynamicAlloc da2;                           //error: use of deleted function.
    delete da1;                                 //error: use of deleted function.
    // deleteKeyword dk;
    // deleteKeyword dk2 = dk;         //error: use of deleted function.
    // dk = dk2;                       //error: use of deleted function.
    return 0;
}
