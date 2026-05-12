//------------------------------------------------------------------
// 2026 1학기 STL				5월 12일					(11주 1일)
//------------------------------------------------------------------
// span<T> - light weight object
// contiguous 메모리를 대표(포장)함 (like std::function)
// string의 경우 중요한 자료구조 - string_view라는 특별한 타입 존재
// syntactic sugar 이다.
// 
//------------------------------------------------------------------
 
#include <iostream>
#include <algorithm>
#include <span>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	YString ys{ "The quick brown fox jumps over the lazy dog" };

	std::sort(ys.data( ) , ys.data( ) + ys.size( ));

	// [문제] 거꾸로 출력하시오
	std::span<char> s{ ys.data( ), ys.size( ) };
	
	for ( auto i = s.rbegin( ); i != s.rend( ); ++i ) {
		std::cout << *i << " - ";
	}
	std::cout << std::endl;

	save("main.cpp");		// "메인.cpp"를 저장하자
}