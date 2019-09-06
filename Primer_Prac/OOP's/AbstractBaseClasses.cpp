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

class Disc_Quote : public Quote
{
    public:
        Disc_Quote() = default;

        Disc_Quote(const std::string &book, double price, std::size_t qty, double disc):
                    Quote(book, price),
                    quantity(qty),
                    discount(disc)
                    {}
        
        double net_price(std::size_t) const = 0;

        int value = 0;

    private:
        std::size_t quantity = 0;
        double discount = 0.0;
};

class Bulk_Quote : public Disc_Quote
{
    public:
        Bulk_Quote() = default;

        Bulk_Quote(const std::string &book, double price, std::size_t qty, double disc):
                    Disc_Quote(book, price, qty, disc)
                    {}

        virtual double net_price(std::size_t s) const override;

        void get() const;

        int value;      //hides the members Disc_Quote::value .
};

double Bulk_Quote::net_price(std::size_t s) const
{
    std::cout << "insode the overridden net_price function of Bulk_Quote....";
    return 0.0;
}

int main(int argc, char const *argv[])
{
    //object of Disc_Quote cannot be reated as it has a pure virtual function in it.
    //Disc_Quote *dq = new Disc_Quote();

    Bulk_Quote bq;
    bq.net_price(10);
    bq.value = 100;
    std::cout << bq.value << "****" << std::endl;
    return 0;
}
