//------------------------------------------------------------------
// 2026 1학기 STL				6월 2일					(13주 2일)
// 기말시험 6/17
//------------------------------------------------------------------
// STL Unordered Associative Container
// Key, Value - O(1) 복잡도로 key값에 access
// - unordered_set, unordered_multiset		K == V
// - unordered_map, unordered_multimap
//------------------------------------------------------------------

#include <iostream>
#include <unordered_set>
#include <print>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	//save("main.cpp");

	// [문제] unordered_multiset의 메모리 구조를 출력해본다.
	// hash는 다음 시간에
	std::unordered_multiset<int> ums;

	while ( true ) {
		std::cout << "추가할 int값 - ";
		int num;
		std::cin >> num;
		std::cout << std::endl;

		ums.insert(num);
		std::cout << std::hash<int>( )( num ) << std::endl;

		for ( int i = 0; i < ums.bucket_count( ); ++i ) {
			std::print("[{:>4}]" , i);
			// i번째 버킷 내부 순회
			for ( auto p = ums.begin(i); p != ums.end(i); ++p ) {
				std::cout << " <-> " << *p;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

}