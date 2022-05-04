#include "iostream"
#include "Integer.h"

class Product
{
private:
    Integer m_Id;
public:
    Product(const Integer &id);
    ~Product();
};

Product::Product(const Integer &id) : m_Id(id)
{
    std::cout << "Product()" << std::endl;
}

Product::~Product()
{
    std::cout << "~Product()" << std::endl;
}


int main()
{
    Product p(5);
    return 0;
}

// without constructor list: Integer(Int), Integer(), Product(const Integer &), operator =(const Integer&), ~Integer(), ~Product(), ~Integer()
// with constructor list: Integer(Int), Integer(const Integer&), Product(const Integer &), ~Integer(), ~Product(), ~Integer()