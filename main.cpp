//------------------------------------------------------------------
// 2026 1학기 STL				3월 10일					(2주 1일)
//------------------------------------------------------------------
// 많은 수의 자료를 처리하기
//------------------------------------------------------------------

#include <iostream>
#include <random>
#include <print>

#include "save.h"

std::default_random_engine dre;
std::uniform_int_distribution<int> uid{ 0, 9999 };

int main()
{
	// [문제] 임의의 값을 갖는 int 1000개를 생성하라. 모든 값을 화면에 출력하라.

	int num[1000];

	for (int i = 0; i < 1000; ++i)
	{
		num[i] = uid(dre);
	}

	for (int n : num)
	{
		std::print("{:8}", n);
	}

	save( "main.cpp" );		// "메인.cpp"를 저장하자
}