//--------------------------------- ---------------------------------
// 2026 1학기 STL				3월 11일					(2주 2일)
//------------------------------------------------------------------
// 많은 수의 자료를 처리하기
//------------------------------------------------------------------

#include <iostream>
#include <random>
#include <fstream>
#include <array>

#include "save.h"

std::default_random_engine dre{ };
std::uniform_int_distribution<int> uid{ 0, 999'9999 };

int main()
{
	// [문제] "int값1000만개.txt"에 저장한 int값을 읽어 화면에 저장하라.
	/*std::ofstream out { "int값1000만개.txt" };

	for (int i = 0; i < 1000'0000; ++i) {
		out << uid(dre) << ' ';
	}*/

	std::ifstream in{ "int값1000만개.txt" };

	if (not in) {
		std::cout << "파일 읽기 실패" << std::endl;
		return 2022184025;
	}

	int num = 0;
	while (in >> num) {
		std::cout << num << std::endl;
	}

	//save( "main.cpp" );		// "메인.cpp"를 저장하자
}