#include "iostream"

class Integer{
    int m_Value{0};
    
    public:
        Integer() = default; // to use initialized m_Value
        Integer(int value) {m_Value = value;} 
        ~Integer();

        void SetValue(int value) {m_Value = value;}
        void SetValue(float) = delete;
};

int main()
{
    Integer i1{}; // Call default constructor
    Integer i2(3);

    i1.SetValue(33);
    //i1.SetValue(3.3f); // Wont Compile because of delete... otherwise you would get only a warning
    return 0;
}