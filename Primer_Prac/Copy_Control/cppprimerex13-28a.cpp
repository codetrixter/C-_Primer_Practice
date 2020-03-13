/**
 * Implement the default constructor and necessary copy control members for the below class.
 */

//---------------------VALUE LIKE---------------------------

#include <iostream>
#include <string>

class TreeNode
{
    public:
        //Default constructor.
        TreeNode():
        name(""),
        count(0),
        left(null),
        right(null)
        {}

    private:
        std::string name;
        int count;
        TreeNode *left;
        TreeNode *right;
};

//----------------------

int main(int argc, char const *argv[])
{
    
    return 0;
}


