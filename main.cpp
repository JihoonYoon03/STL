//------------------------------------------------------------------
// 2026 1학기 STL				4월 21일					(8주 1일)
//------------------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T, N>	- 유일하게 크기 고정된 자료구조
// vector<T>	- dynamic array
//------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <array>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	save("main.cpp");		// "메인.cpp"를 저장하자

	// [문제] "main.cpp"의 소문자 개수를 세서 다음과 같이 출력하라
	// a - 10
	// b - 3
	// 중간 생략

	std::ifstream in{ "main.cpp" };

	std::array<int , 26> count{};

	if ( not in ) {
		return 20260421;
	}

	char c;
	while ( in >> c ) {
		if ( islower(c) )
			++count[ c - 'a'];
	}

	for ( int i = 0; i < count.size( ); ++i ) {
		std::cout << static_cast< char >('a' + i) << " - " << count[ i ] << std::endl;
	}
}