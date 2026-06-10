//------------------------------------------------------------------
// 2026 1학기 STL				6월 10일					(14주 2일)
// 기말시험 6/17
//------------------------------------------------------------------
// range										***
// concept
// universal forwarding							***
// views
// constrained algorithm
// lazy-evaluation <-> eager evaluation			***
// projection
// pointer-to member
//------------------------------------------------------------------

#include <iostream>
#include <ranges>
#include <vector>
#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	//save("main.cpp");

	// 필터링 과정을 cout으로 볼 수 있다
	// lazy-evalutaion
	auto is_odd = [](int num) { 
		std::cout << " 홀수 ";
		return num % 2;
		};
	auto is_prime = [](int n) {
		std::cout << " 소수 ";

		if ( n <= 1 ) return false;         // 1 이하의 수는 소수가 아님
		if ( n == 2 ) return true;          // 2는 유일한 짝수 소수
		if ( n % 2 == 0 ) return false;     // 2를 제외한 짝수는 소수가 아님

		// 3부터 시작하여 제곱근까지만 홀수로 나누어 떨어지는지 확인
		for ( int i = 3; i * i <= n; i += 2 ) {
			if ( n % i == 0 ) return false;
		}
		return true;
		};

	// 1 to 1000
	// 해당 구간의 데이터를 메모리에 잡아서 사용하는 것이 절대 아님.
	// range에게 begin부터 데이터 1개 요청 -> num으로 넘어옴
	// 넘어온 num을 필터에 순차적으로 넘김
	// 필터를 전부 통과한 값만 본문 실행
	// 따라서, const & 등을 넣으면 문제가 생길 수 있음
	// 보편 참조(auto&&)를 사용해서 num 형식을 추론하도록 하라.
	for ( auto&& num :
		std::views::iota(1, 1000)
		| std::views::filter(is_odd)
		| std::views::filter(is_prime) )
	{
		std::cout << num << " ";
	}
}