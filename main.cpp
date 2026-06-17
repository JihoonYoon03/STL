//------------------------------------------------------------------
// 기말시험
//------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if ( not in ) {
		std::cout << "파일 오류!" << std::endl;
		return 20260617;
	}

	// 문제 1-1, 1-2
	std::list<YString> Allice{ std::istream_iterator<YString>{in}, {} };

	/*
	observe = true;
	Allice.back( ).show( );
	observe = false;
	*/

	// 문제 1-3, 1-4
	/*
	std::vector<YString> Allice{ std::istream_iterator<YString>{in}, {} };

	observe = true;
	Allice.back( ).show( );
	observe = false;
	*/

	std::ifstream in2{ "단어들.txt" };
	if ( not in2 ) {
		std::cout << "파일 오류!" << std::endl;
		return 20260617;
	}

	std::vector<YString> v{ std::istream_iterator<YString>{in2}, {} };

	// 2-1
	//std::cout << v.size() << std::endl;

	std::vector<YString> result;
	std::ofstream out{ "겹치는단어들.txt" };

	Allice.sort( );
	Allice.unique( );
	
	size_t cnt{};
	for ( const YString& ys : Allice ) {
		auto iter = std::find(v.begin( ) , v.end( ) , ys);
		if ( iter != v.end( ) ) {
			out << *iter << " ";
			cnt++;
		}
	}

	std::cout << cnt << std::endl;
}