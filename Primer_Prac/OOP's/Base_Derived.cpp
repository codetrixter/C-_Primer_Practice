#include <iostream>
#include <string>

class Quote
{
    public:
        std::string isbn() const;
        //returns the price for specified numbre of books.
        virtual double net_price(std::size_t n) const;
};

class Bulk_Quote : public Qoute
{
    double net_price(std::size_t n) const override;
};