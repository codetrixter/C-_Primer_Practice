/**
 * We need to overload the copy-control members namely :
 * copy constructor and copy-assignment operator because we want to keep the id's unique and dont wnat them to be copied.
 */

#include <iostream>
#include <string>

class employee
{
    public:
        employee(std::string n):
        name(n) 
        {
            uid = ++uniqueId;
        }

        //overloading copy constructor
        employee(const employee &emp):
        name(emp.name), uid(++uniqueId)
        {}

        //overloading cop-assignment operator to prevent the id from being copied.
        employee& operator=(const employee &emp)
        {
            name = emp.name;

            return *this;
        }

        void getDetails()
        {
            std::cout << this->name << "\t" << this->uid << std::endl;
        }

    private:
        std::string name;
        int uid;
        static int uniqueId;
};

int employee::uniqueId = 0;

int main(int argc, char const *argv[])
{
    employee e1("Abhishek"), e2("Ashish");
    e1.getDetails();
    e2.getDetails();

    employee e3(e2);
    e3.getDetails();

    e1 = e2;
    e1.getDetails();
    return 0;
}

