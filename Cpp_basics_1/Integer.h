#pragma once
#include <iostream>
class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer();
	//Parameterized constructor
	Integer(int value);
	//Copy constructor
	Integer(const Integer &obj);
	//Move constructor
	Integer(Integer &&obj);
	int GetValue()const;
	void SetValue(int value);
	~Integer();
	Integer & operator ++();	// preincrement
	Integer operator ++(int);	// post increment
	bool operator ==(const Integer &a)const;

	//Copy assignment
	Integer & operator =(const Integer &a);
	//Move assignment
	Integer & operator =(Integer &&a);
	Integer operator +(const Integer & a)const;

	void operator ()();
	explicit operator int();

	friend std::ostream & operator <<(std::ostream & out, const Integer &a);	// friend so this class has access to private members
	friend std::istream & operator >> (std::istream &input, Integer &a);		// friend so this class has access to private members
};
Integer operator +(int x, const Integer &y);
