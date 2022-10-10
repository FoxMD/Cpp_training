#include "iostream"

class Car{
    float fuel;
    int passengers;
    float speed;
    
    public:
        Car();
        Car(int value);
        Car(int value, float gas);    
        ~Car();
};

int main()
{

}

// to delegate construcotrs:
Car::Car():Car(0)
{

}

Car::Car(int value):Car(value, 0)
{

}

Car::Car(int value, float gas)
{
    // Init everything here and you dont have to write duplicite code
}
// etc...