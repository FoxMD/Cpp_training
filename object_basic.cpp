#include "iostream"

class Integer{
    int* m_pInt;
    public:
        Integer();
        Integer(int value);
        Integer(const Integer &obj);    // Good practise for passing objects is const
        ~Integer();
        int GetValue()const;
        void SetValue(int value);
};

int main()
{
    int *p1 = new int(5);
    int *p2 = p1; 
    // thats a shallow copy 

    int *p3 = new int(*p1);
    // deep copy

    // Always try to avoid copy, but if you must use deep copy (implement copy operator)
    Integer myInt(5);
    Integer myInt2(myInt); // copy of constructor ... can be copied also with return Integer etc
    std::cout << myInt.GetValue() << std::endl;
}

Integer::Integer()
{
    m_pInt = new int(0);
}

Integer::Integer(const Integer &obj)    // Use rule of 3
{
    m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(int value)
{
    m_pInt = new int(value);
}

int Integer::GetValue()const
{
    return *m_pInt;
}

void Integer::SetValue(int value)
{
    *m_pInt = value;
}

Integer::~Integer()
{
    delete m_pInt;
}