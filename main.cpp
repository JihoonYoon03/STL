//------------------------------------------------------------------
// 2026 1학기 STL				4월 28일					(9주 1일)
//------------------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T, N>	- 유일하게 크기 고정된 자료구조
// vector<T>	- dynamic array
// 
// 어떤 자료구조던지, Iterator는 ++ptr 한 뒤 *ptr 할 수 있다.
// Design pattern
//------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	save("main.cpp");		// "메인.cpp"를 저장하자

	std::vector<YString> v{ "1", "22", "333" };

	// [문제] v에서 "22"를 제거하라

	std::erase(v , "22");

	std::cout << "size: " << v.size( ) << std::endl;
	std::cout << "capacity: " << v.capacity( ) << std::endl;
	std::cout << "data: " << v.data( ) << std::endl;
	
	observe = true;
	for (YString& str : v)
		str.show();
	observe = false;
}