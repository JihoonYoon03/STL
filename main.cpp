//-------------------------------------------------------------------
// 2026 1학기 STL				3월 17일					(3주 1일)
//------------------------------------------------------------------
// 많은 수의 자료를 처리하기 - binary I/O
//------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <array>
#include <print>

#include "save.h"

int main()
{
	// [문제] 파일 "int 천개.bin"에는 1000개의 int값이 저장되어있다.
	// 파일은 binary mode
	// 메모리에 int 1000개 값을 읽어 오세요.

	std::ifstream in{ "int 천개.bin", std::ios::binary };

	if (not in) {
		std::cout << "잘못된 파일입니다" << std::endl;
	}

	std::array<int, 1000> a;

	in.read(reinterpret_cast<char*>(a.data()), a.size() * sizeof(int));
	
	for (int num : a) {
		std::print("{:8}", num);
	}

	save( "main.cpp" );		// "메인.cpp"를 저장하자
}