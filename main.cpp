//------------------------------------------------------------------
// 2026 1학기 STL				5월 26일					(12주 2일)
// 기말시험 6/17
//------------------------------------------------------------------
// STL Associative Container
// Key, Value - Key값을 정렬 기준으로 O(log N) 복잡도로 access
// - set, multiset		K == V
// - map, multimap
//------------------------------------------------------------------

#include <iostream>
#include <set>
#include <fstream>

#include "save.h"
#include "YString.h"

extern bool observe;

template<>
struct std::less<YString> {
	bool operator()(const YString& a , const YString& b) const {
		return std::lexicographical_compare(a.begin( ) , a.end( ) , b.begin( ) , b.end( ));
	}
};

int main( )
{
	// "main.cpp"에 있는 단어를 set<YString>에 저장하라.
	// 기준은 사전식 오름차순으로.

	std::fstream in{ "main.cpp" };
	if ( not in ) {
		std::cout << "파일을 살펴보시오" << std::endl;
		return 20260526;
	}

	std::set<YString, std::less<YString>> s{ std::istream_iterator<YString>{in}, {} };

	for ( const YString& ys : s ) {
		std::cout << ys << std::endl;
	}

	save("main.cpp");

	// [문제] 찾을 단어가 set에 있는지 알려줘라.

	while ( true ) {
		std::cout << "찾을 단어는 - " << std::endl;
		YString ys;
		std::cin >> ys;

		// 있다면 몇 번째인가
		// 없다면 없는 단어다.

		auto p = std::find(s.begin( ) , s.end( ) , ys);

	}
}