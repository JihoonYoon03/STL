//------------------------------------------------------------------
// 2026 1학기 STL				3월 25일					(4주 2일)
//------------------------------------------------------------------
// callable type
//------------------------------------------------------------------

#include <iostream>
#include <random>
#include <array>
#include <print>
#include <ranges>

#include "save.h"

// 랜덤값을 갖는 int 1000만개를 메모리에 저장하라.
// 오름차순 정렬 후 출력하라

std::default_random_engine		dre{};
std::uniform_int_distribution	uid{ 0, 999'9999 };

// a와 a{1} 했을 때 파일 크기 차이나는 이유
std::array<int, 1000'0000> a;

int ascending(const void* a , const void* b) {
	// void* - 사용자가 마음대로 바꿀 수 있는 형식
	// 정렬 함수는 정렬할 타입을 알지만, qsort는 void*로 넘겨주므로 인자가 이렇게 됨
	return *( int* )a - *( int* )b;
}

int main( )
{
	for ( int& num : a ) {
		num = uid(dre);
	}

	std::cout << "정렬 전 - 앞에서부터 1000개만 출력" << std::endl;

	for ( const int& num : a | std::views::take(1000) ) {	// | : 필터. 주어진 데이터를 원하는 방식으로 필터링. 중첩 가능함
		std::print("{:8}" , num);
	}

	// 여기서 qsort를 사용하여 오름차순으로 정렬하라.
	// 전달되는 인자 중 앞의 3개는 물리량, 마지막은 코드이다.
	std::qsort(a.data( ) , a.size( ) , sizeof(std::array<int, 1000'0000>::value_type) , ascending);

	std::cout << "정렬 후 - 앞에서부터 1000개만 출력" << std::endl;

	for ( const int& num : a | std::views::reverse | std::views::take(1000) ) {	// | : 필터. 주어진 데이터를 원하는 방식으로 필터링. 중첩 가능함
		std::print("{:8}" , num);
	}

	//save("main.cpp");		// "메인.cpp"를 저장하자
}