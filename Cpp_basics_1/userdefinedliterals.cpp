#include <cstdlib>
#include <iostream>

class Distance
{
    private:
        long double m_Kilometers;
    public:
        Distance(long double km) : m_Kilometers{km}{}
        long double GetKm() const{return m_Kilometers;}
        void SetKm(long double km) {m_Kilometers = km;}
};

Distance operator"" _mi(long double val) 
{
    return Distance{val * 1.6};
}

int main()
{
    Distance dist{12.0_mi};
    // now we wan miles, define user defined values
    dist.SetKm(34.0);
    return 0;
}