//------------------------------------------------------------------
// 2026 1학기 STL				5월 20일					(12주 1일)
//------------------------------------------------------------------
// STL Algorithm
// 1 - 원소를 수정하지 않는 알고리즘
// 2 - 원소를 수정하는 알고리즘
// 3 - 정렬 관련 알고리즘
//------------------------------------------------------------------

#include <iostream>
#include <algorithm>

#include "save.h"
#include "YString.h"

extern bool observe;

template<class It, class Val>
It my_find(It beg, It end, Val val)
{
	while ( beg != end ) {
		if ( *beg == val ) {
			return beg;
		}
		++beg;
	}
	return end;
}

int main( )
{
	save("main.cpp");

	YString ys{ "93147833366635670204172374813204103341032080732604153" };

	// [문제] ys에서 처음 나온 짝수를 찾으시오
	YString::iterator i = std::find_if(ys.begin( ) , ys.end( ) , [](char c) {
		return not ( c & 1 );
		});

	std::cout << *i << std::endl;
}