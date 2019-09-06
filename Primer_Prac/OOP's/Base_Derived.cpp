#include <iostream>
#include <string>

class Quote
{
    public:
        //Constructors.
        Quote() = default;
        Quote(const std::string &book, double sales_price):
            bookNo(book), price(sales_price)
            {}
        
        std::string isbn() const 
        {
            return bookNo;
        }
        //returns the price for specified numbre of books.
        virtual double net_price(std::size_t n) const
        {
            return price * n;
        }

        //Destructor.
        virtual ~Quote() = default;

    private:
        std::string bookNo;

    protected:
        double price = 0.0;
};

class Bulk_Quote : public Quote
{
    public:
        //Constructors.
        Bulk_Quote() = default;
        Bulk_Quote(const std::string &book, double p, std::size_t qty, double disc):
                    Quote(book, p), min_qty(qty), discount(disc)
                    {
                    }

        //In c++11 the derived class overrides a virtually inherited function by mentioning override
        // keyword at the end of the menthd signature.
        double net_price(std::size_t n) const override;

        double print_total(std::ostream &os, const Quote &item, std::size_t n);
    private:
        std::size_t min_qty = 0;    //min. purhase for the discount to apply.
        double discount = 0.0;
};

double Bulk_Quote::print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() 
       << "# sold: " << n << "total due: " << ret << std::endl;
    return ret; 
}

int main(int argc, char const *argv[])
{
    Quote basic;
    Bulk_Quote bulk;
    Bulk_Quote *bk = &bulk;
    //since which version of net_price is called is decided at runtime, hence it is called dinamic binding.
    bk->print_total(std::cout, basic, 20);   //calls Quote version of net_price
    bk->print_total(std::cout, bulk, 20);    //calls Bulk_Quote version of the net_price.
    return 0;
}
