//------------------------------------------------------------------
// 2026 1학기 STL				3월 24일					(4주 1일)
//------------------------------------------------------------------
// smart pointer - callable type
//------------------------------------------------------------------

#include <iostream>
#include <numeric>
#include <memory>
#include <string>

#include "save.h"


// [문제] 사용자가 원하는 개수 만큼 int를 저장할 메모리를 확보하라.
// 메모리를 1부터 시작하는 int 값으로 채워라.
// 합계를 계산하여 출력하라.
// 발생 가능한 오류 차단 버전

int main( )
{
	std::cout << "원하는 만큼의 int 개수 입력: ";
	std::string input;
	std::getline(std::cin, input);

	int num{ };

	try {
		size_t pos{};
		num = std::stoi(input, &pos);

		if ( pos != input.length( ) ) {
			throw std::invalid_argument("문자가 포함됨");
		}
	}
	catch (...) {
		std::cout << "잘못된 입력 혹은 너무 큰 수 입니다." << std::endl;
		exit(2022184025);
	}

	// int* p;	// 안 써야할 자료형
	// C++11(Modern C++)부터 제대로 된 smart pointer가 있으니까

	try {
		std::unique_ptr<int[]> p{ new int[ num ] };		// RAII

		std::iota(p.get( ) , p.get( ) + num , 1);

		long long sum = std::accumulate(p.get( ) , p.get( ) + num , 0LL);

		std::cout << "1부터 " << num << "까지의 합계는 " << sum << std::endl;
	}
	catch (...) {
		std::cout << "잘못된 개수입니다." << std::endl;
		exit(2022184025);
	}

	save("main.cpp");		// "메인.cpp"를 저장하자
}