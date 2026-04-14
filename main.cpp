//------------------------------------------------------------------
// 2026 1학기 STL				4월 14일					(7주 1일)
//------------------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T, N> - 유일하게 크기 고정된 자료구조
//------------------------------------------------------------------

#include <iostream>
#include <array>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	std::array<int , 5> a{ 1, 2, 3, 4, 5 };

	// element access
	// at, operator[], front, back, data

	while ( true ) {
		std::cout << "몇 번째 값을 알려줄까요? ";
		int num;
		std::cin >> num;

		std::cout << num << " 번째 값은 - " << a[num] << std::endl;
	}

	//save("main.cpp");		// "메인.cpp"를 저장하자 
}