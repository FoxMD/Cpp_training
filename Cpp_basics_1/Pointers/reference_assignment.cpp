#include "iostream"

void Add(int a, int b, int &result) ;    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void Swap(int &a, int &b) ;            //Swap two numbers through reference arguments

int main()
{
    int a{1}, b{6}, x{0};

    Add(a, b, x);
    std::cout << x << std::endl;

    x = 0;
    Factorial(a, x);
    std::cout << x << std::endl;

    Swap(a, b);
    std::cout << a << " " << b << std::endl;
}

void Add(int a, int b, int &result)
{
    result = a + b;
}

void Factorial(int a, int &result)
{
    result = 1;
	for (int i = a; i > 0; --i) {
		result *= i;		
	}
}

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}