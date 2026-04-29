//------------------------------------------------------------------
// 2026 1학기 STL				4월 29일					(9주 2일)
//------------------------------------------------------------------
// STL Container - Containers are objects that store other objects.
// array<T, N>	- 유일하게 크기 고정된 자료구조 -> STACK, DATA
// vector<T>	- dynamic array -> random access(임의의 위치에 접근 시간이 O(1))
// list<T>		- 임의의 위치에서 추가/제거 동작이 O(1)
//------------------------------------------------------------------

#include <iostream>
#include <list>
#include <fstream>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	//save("main.cpp");		// "메인.cpp"를 저장하자

	// [문제] 파일에 있는 단어를 list에 저장하라
	// list를 사전 기준으로 오름차순 정렬하라
	// 화면에 출력하라

	std::ifstream in{ "2026 1학기 STL.txt" };

	if ( not in ) {
		std::cout << "파일이 없음" << std::endl;
		return 20260429;
	}

	std::cout << "파일 읽는 중";
	std::list<YString> c{ std::istream_iterator<YString>(in), {} };
	std::cout << std::endl;

	c.sort([](const YString& a, const YString& b) {
		return std::lexicographical_compare(a.data( ) , a.data( ) + a.size( ) , b.data( ) , b.data( ) + b.size( ));
		});

	c.unique([](const YString& a , const YString& b) {
		return std::lexicographical_compare(a.data( ) , a.data( ) + a.size( ) , b.data( ) , b.data( ) + b.size( ));
		});

	observe = true;
	for ( const YString& ys : c ) {
		std::cout << ys << std::endl;
	}
	observe = false;
}

//이게마지막이어야한다