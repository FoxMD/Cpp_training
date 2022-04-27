#include "iostream"

class Integer{
    int* m_pInt;
    public:
        Integer();
        Integer(int value);
        Integer(const Integer &obj);    // Good practise for passing objects is const
        ~Integer();
        Integer(Integer &&obj);
        int GetValue()const;
        void SetValue(int value);
        Integer Add(const Integer &a, const Integer &b);
};

int main()
{
    Integer a(1), b(3);
    a.SetValue(Add(a, b).GetValue()); // faster with implemented Integer::Integer(Integer &&obj) because of shallow copy
    //std::cout << myInt.GetValue() << std::endl;
    return 0;
}

Integer::Integer()
{
    m_pInt = new int(0);
}

Integer::Integer(Integer &&obj)
{
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;   // so that it doesnt crash -> destructor is called on nullptr
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

Integer Add(const Integer &a, const Integer &b)
{
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}