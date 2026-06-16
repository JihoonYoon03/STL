//------------------------------------------------------------------
// 2026 1학기 STL				6월 16일					(15주 1일)
// 기말시험 6/17
//------------------------------------------------------------------
// C++20 Constrained Algorithm
// - Ranges와 Concept을 사용하여 새로 작성한 알고리즘을 말한다.
// range를 인자로 사용 / 리턴값이 다르다.
// 
// std::find; - 그냥 algorithm
// std::ranges::find - constrained algorithm
// 
// ranges::find
// 
// 책 추천
// 
// 템플릿 이해한 뒤:
// Effective modern C++
// A Tour of C++
// 
// C++ 20에 대해:
// C++ 20
// 
// 모던 C++
//------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	//save("main.cpp");

	std::vector<std::string> v{"2026년" , "6월" , "16일" , "15주 1일"};

	// {}는 정렬 로직, 마지막 인자는 어떤 기준으로 데이터를 처리하는가를 의미함.
	std::ranges::sort(v , {} , &std::string::size);

	for ( const std::string& ys : v ) {
		std::cout << ys << std::endl;
	}
}