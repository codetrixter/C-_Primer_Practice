#include<iostream>
#include<vector>
#include<string>

//Problem 

enum ESIZE {SMALL=0, LARGE};
enum ECOLOR {RED=0, GREEN, YELLOW};

struct CProduct
{ 
	ESIZE size; ECOLOR color; std::string name;

	CProduct(ESIZE size, ECOLOR color, std::string name): size(size), color(color), name(name) {}
};

struct CProductFilter
{
	std::vector<CProduct*> filterByColor(const std::vector<CProduct*> products, const ECOLOR color)
	{
		std::vector<CProduct*> result;
		for (CProduct* item : products)
			if (item->color == color) result.push_back(item);

		return result;
	}

	//If we want to extend for filter by size, again we have modify this class, Just thinks which alredy production code
};


//Specification design pattern
template <typename T>
struct ISpecification
{
	virtual bool isSatisfied(T* item) = 0;
    virtual ~ISpecification(){}
};

template <typename T>
struct IFilter
{
	virtual std::vector<T*> filter(const std::vector<T*>& items, ISpecification<T>& spec) = 0;
    virtual ~IFilter(){}
};

struct CBetterFilter: IFilter<CProduct>
{
    std::vector<CProduct*> filter(const std::vector<CProduct*>& items, ISpecification<CProduct>& spec);
};
std::vector<CProduct *> CBetterFilter::filter(const std::vector<CProduct *> &items, ISpecification<CProduct> &spec)
{
    std::vector<CProduct*> result;

    for(auto item : items)
        if(spec.isSatisfied(item)) result.push_back(item);

    return result;
}

// Any specication we can extend and delivery in other files
struct CColorSpec : ISpecification<CProduct>
{
	ECOLOR color;
    CColorSpec(ECOLOR color);
    bool isSatisfied(CProduct* item);
};
CColorSpec::CColorSpec(ECOLOR color):color(color){}

bool CColorSpec::isSatisfied(CProduct *item)
{
    return (item->color == color);
}

struct CSizeSpec: ISpecification<CProduct>
{
	ESIZE size;

    CSizeSpec(ESIZE size);

    bool isSatisfied(CProduct* item);
};

CSizeSpec::CSizeSpec(ESIZE size):size(size){}

bool CSizeSpec::isSatisfied(CProduct *item)
{
    return (item->size == size);
}

struct CColorAndSizeSpec : ISpecification<CProduct>
{
	ECOLOR color;
	ESIZE size;
    CColorAndSizeSpec(ECOLOR color, ESIZE size);

    bool isSatisfied(CProduct* item);
};

CColorAndSizeSpec::CColorAndSizeSpec(ECOLOR color, ESIZE size): color(color), size(size){}

bool CColorAndSizeSpec::isSatisfied(CProduct *item)
{
    return ((item->size == size) && (item->color == color));
}


int TEST_01_Open_Close_Principle()
{
	CProduct apple(ESIZE::SMALL, ECOLOR::RED, "apple"), 
		 tree(ESIZE::LARGE, ECOLOR::GREEN, "tree"),
		 house(ESIZE::LARGE, ECOLOR::GREEN, "house");


	std::vector<CProduct*> products = { &apple, &tree, &house };

#if 0
	CProductFilter colorFilter;
	auto filterProducts = colorFilter.filterByColor(products, ECOLOR::GREEN);
	for (auto item : filterProducts)
		std::cout << item->name << "\t";
	std::cout << "\n";
#endif
	CBetterFilter betterFilter;
	CColorSpec green(ECOLOR::GREEN);
	auto filterProducts = betterFilter.filter(products, green);
	for (auto item : filterProducts)
		std::cout << item->name << "\t";
	std::cout << "\n";

	CSizeSpec large(ESIZE::LARGE);
	filterProducts = betterFilter.filter(products, large);
	for (auto item : filterProducts)
		std::cout << item->name << "\t";
	std::cout << "\n";

	CColorAndSizeSpec greenAndLarge(ECOLOR::GREEN, ESIZE::LARGE);
	filterProducts = betterFilter.filter(products, large);
	for (auto item : filterProducts)
		std::cout << item->name << "\t";
	std::cout << "\n";

	return 0;
}
