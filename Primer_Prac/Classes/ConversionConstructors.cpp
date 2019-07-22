#include <iostream>
#include <string>

class Avenger
{
    public:
    int i = 0;
    float ff = 10.9;
    std::string s1 = "Abhishek";

    // /Avenger(const std::string &str1 ): s1(str1) {}

    //explicit Avenger(int xx): i(xx) {}
    // Avenger(int abh, float fl): i(abh), ff(fl) {}

};

void functionCall(Avenger assemble)
{
    std::cout << "inside finctionCall()...." << std::endl;
}

int main(int argc, char const *argv[])
{
    // functionCall(std::string("Piece of cake"));     /**
    //                                                  * implicit conversion does entertains more that one conversion to user defined tyes
    //                                                  * hence either we have to conver char* to string or convert temp string to 
    //                                                  * Avenger  type.
    //                                                  */
    // functionCall(Avenger("Abhishek is dumb"));

    // Avenger avenge = 12;         //error: cannot convert int to Avenger
    //functionCall(12);             //error: cannot convert int to Avenger
      function(12);                 //works as it is direct initialization

    //functionCall({12, 12.22});
    return 0;
}
