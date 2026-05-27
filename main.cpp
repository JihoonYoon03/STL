//------------------------------------------------------------------
// 2026 1학기 STL				5월 26일					(13주 1일)
// 기말시험 6/17
//------------------------------------------------------------------
// STL Associative Container
// Key, Value - Key값을 정렬 기준으로 O(log N) 복잡도로 access
// - set, multiset		K == V
// - map, multimap
//------------------------------------------------------------------

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	//save("main.cpp");

	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if ( not in ) {
		std::cout << "파일 오류";
		return 20260527;
	}

	// [문제] 파일에 있는 단어 개수를 다음과 같이 출력하라
	// a		- 
	// aa		-
	// ...
	// zigzag	-

	std::map<YString , size_t> ss;
	YString ys;

	while ( in >> ys ) {
		++ss[ ys ];
	}

	for ( const auto& [word , cnt] : ss ) {
		std::cout << word << " - " << cnt << std::endl;
	}

	std::cout << "단어 개수 - " << ss.size( ) << std::endl << std::endl;

	// 많이 나온 단어 순서대로 출력하라
	std::map<size_t , YString , std::greater<size_t>> sys;

	for ( const auto& [word , cnt] : ss ) {
		sys.insert(std::make_pair(cnt , word));
	}

	for ( const auto& [cnt , word] : sys ) {
		std::cout << cnt << " - " << word << std::endl;
	}
}