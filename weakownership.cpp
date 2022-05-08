#include <iostream>

class Printer 
{
    std::shared_ptr<int> m_pValue{};
    public:
        void SetValue(std::shared_ptr<int> p) {m_pValue = p;}
        void Print() { std::cout << *m_pValue << std::endl;}
};

int main()
{
    Printer prn;
    int num{};
    std::cin >> num;
    std::shared_ptr<int> p{new int{num}};
    prn.SetValue(p);
    if(*p > 10)
    {
        p = nullptr;    // Just decreases ref. count... 
    }

    prn.Print();

    return 0;
}