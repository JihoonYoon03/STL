//------------------------------------------------------------------
// 2026 1학기 STL				3월 24일					(4주 1일)
//------------------------------------------------------------------
// smart pointer - callable type
//------------------------------------------------------------------

#include <iostream>
#include <numeric>
#include <memory>

#include "save.h"


// [문제] 사용자가 원하는 개수 만큼 int를 저장할 메모리를 확보하라.
// 메모리를 1부터 시작하는 int 값으로 채워라.
// 합계를 계산하여 출력하라.
// 정답

int main( )
{
	std::cout << "원하는 만큼의 int 개수 입력: ";
	int num;
	std::cin >> num;

	// 문제없는 수만 입력할거라 희망

	// int* p;	// 안 써야할 자료형
	// C++11(Modern C++)부터 제대로 된 smart pointer가 있으니까

	std::unique_ptr<int[]> p{ new int[ num ] };		// RAII

	std::iota(p.get( ) , p.get( ) + num , 1);

	long long sum = std::accumulate(p.get( ) , p.get( ) + num , 0LL);

	std::cout << "1부터 " << num << "까지의 합계는 " << sum << std::endl;

	save("main.cpp");		// "메인.cpp"를 저장하자
}