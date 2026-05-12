//------------------------------------------------------------------
// 2026 1학기 STL				5월 6일					(10주 2일)
//------------------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// Sequence Container
// array<T, N>	- 유일하게 크기 고정된 자료구조 -> STACK, DATA
// vector<T>	- 캐시 효율성 (Cache Locality)
// list<T>		- 임의의 위치에서 추가/제거 동작이 O(1)
// deque<T>		- vector와 list의 장점을 활용하려는 자료구조
//------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <deque>
#include <list>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	save("main.cpp");		// "메인.cpp"를 저장하자
	// vector, deque, list 어떤 것이 가장 많은 원소를 담을 수 있는가?
	{
		std::vector<int> v;
		while ( true ) {
			try {
				v.push_back(1);
			}
			catch ( ... ) {
				std::cout << "vector<int> 개수 - " << v.size() << std::endl;
				break;
			}
		}
	}
	{
		std::deque<int> v;
		while ( true ) {
			try {
				v.push_back(1);
			}
			catch ( ... ) {
				std::cout << "deque<int> 개수 - " << v.size( ) << std::endl;
				break;
			}
		}
	}
	{
		std::list<int> v;
		while ( true ) {
			try {
				v.push_back(1);
			}
			catch ( ... ) {
				std::cout << "list<int> 개수 - " << v.size( ) << std::endl;
				break;
			}
		}
	}


}