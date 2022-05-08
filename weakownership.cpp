#include <iostream>
// muliple weak pointers can count to one shared pointer
// expired checks reference count
// helps to access resource that may or may not be availiable, if resource is availiable we lock to it and create a sp
class Printer 
{
    std::weak_ptr<int> m_pValue{};
    public:
        void SetValue(std::weak_ptr<int> p) {m_pValue = p;}
        void Print() 
        {
            if(m_pValue.expired()) {std::cout << "Already expired" << std::endl; return;}
            auto sp = m_pValue.lock(); 
            std::cout << *sp << std::endl;
        }
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