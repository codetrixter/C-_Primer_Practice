#include <iostream>

class synthesize
{
    public:
        synthesize() = default;
        synthesize(const synthesize&) = default;
        synthesize& operator=(const synthesize&);
        ~synthesize() = default;
};

synthesize& synthesize::operator=(const synthesize&) = default;

int main(int argc, char const *argv[])
{
    synthesize s1;
    return 0;
}