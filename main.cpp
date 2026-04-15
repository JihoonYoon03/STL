//------------------------------------------------------------------
// 2026 1학기 STL				4월 15일					(7주 2일)
//------------------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T, N>	- 유일하게 크기 고정된 자료구조
// vector<T>	- dynamic array
//------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	// [문제] 키보드에서 입력한 정수의 합을 출력하라

	std::cout << "수 입력: " << std::accumulate(std::istream_iterator<int>{std::cin} , {} , 0);

	save("main.cpp");		// "메인.cpp"를 저장하자
}