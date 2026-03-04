//------------------------------------------------------------------
// 2026 1학기 STL				3월 4일					(1주 2일)
//------------------------------------------------------------------
// template
//------------------------------------------------------------------

#include <iostream>

#include "save.h"

class Dog;				// forward declaration

template <class T>
void change(T& a, T& b)
{
	T temp{ a };		// copy constructor
	a = b;				// a.operator= (b);
	b = temp;
}

class Dog {
public:
	Dog() = default;
	Dog(int input) : value{ input } {}

private:
	int value{};

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.value;
	}
};

int main()
{
	{
		int a{ 1 }, b{ 2 };
		change<int>(a, b);
		std::cout << a << ", " << b << std::endl;		//  2, 1
	}

	{
		Dog a{ 1 }, b{ 2 };
		change<Dog>(a, b);
		std::cout << a << ", " << b << std::endl;		//  2, 1
	}

	save( "main.cpp" );		// "메인.cpp"를 저장하자
}