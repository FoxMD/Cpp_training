#include <iostream>
#include <fstream>

template<typename T, int size, typename Comparator>
void Sort(T(&arr)[size], Comparator comp)
{
    for(int i = 0; i < size -1; ++i)
    {
        for(int j = 0; j < size -1; ++j)
        {
            if(comp(arr[j], arr[j + 1]))
            {
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j + 1]);
                arr[j + 1] = std::move(temp);
            }
        }
    }
}

bool Comp(int x, int y)
{
    return x > y;
}

bool Comp1(int x, int y)
{
    return x < y;
}

struct Comp2 
{
    bool operator()(int x, int y) { return x > y; }
};

template<typename T, int size, typename Callback>
void ForEach(T(&arr)[size], Callback operation)
{
    for(int i = 0; i < size -1; ++i )
    {
        operation(arr[i]);
    }
}

class Product
{
    std::string m_Name;
    float m_Price;
    public:
        Product(const std::string n, float p) : m_Name(n), m_Price(p) {}
        void AssignFinalPrice()
        {
            float taxes[]{12, 5, 25};
            float basePrice{m_Price};
            ForEach(taxes, [basePrice, this](float tax) {   // this keyword for class
                float taxedPrice = basePrice * tax / 100; 
                m_Price += taxedPrice;
                });
        }
        float GetPrice() const { return m_Price;}
};

int main()
{
    Comp2 comp;
    comp(3, 5); // comp.operator()(3, 5)

    int arr[]{1,4,9,8,0,3};
    for(auto x: arr)
    {
        std::cout << x << ", ";
    }
    Sort(arr, [](auto x, auto y) { return x > y;});
    for(auto x: arr)
    {
        std::cout << x << ", ";
    }

    ForEach(arr, [](auto x) { std::cout << x << std::endl;});
    
    int offset = 4;
    ForEach(arr, [offset](auto &x) { x += offset;}); // capture list [] contains some local variable, but it cannot be modified
    
    // to access and modify the value in capture list we need to use mutable
    ForEach(arr, [offset](auto &x) mutable { x += offset; ++offset;});
    
    int sum{};
    ForEach(arr, [&sum](auto &x) { sum += x;});      // & captured by reference, = capture by value

    // example:
    ForEach(arr, [=, &sum](auto &x) { sum += x;});   // all but sum will be captured by value
    ForEach(arr, [&, sum](auto &x) { sum += x;});    // all but sum will be captured by reference

    // example for class:
    Product p{"Watch", 499.99f};
    p.AssignFinalPrice();
    std::cout << p.GetPrice() << std::endl;
    
    // if a lambda is not used with a class it can decompose to a function pointer, used with C functions
    atexit([](){std::cout << "My C++ function" << std::endl;}); // capture list needs to be empty !!!

    // C++14 Generalized lambda capture
    ForEach(arr, [&, newSum = sum](auto &x) { sum += x;});

    // example of use, C++14+
    std::ofstream out{"file.txt"};
    auto write = [out = std::move(out)](int x) mutable {
        out << x;
    };

    write(200);

    return 0;
}