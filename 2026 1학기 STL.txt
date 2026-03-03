//------------------------------------------------------------------
// 2026 1학기 STL				3월 3일					(1주 1일)
//------------------------------------------------------------------
// VS 버전		- 17.14.27
// 컴파일 환경	- Release / x64
// 프로젝트 설정 - 일반 - C++ 언어 표준 - /std::c++latest
//				- C/C++ - SDL 설정 - 아니요
//------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

void save( const std::string& );

int main()
{
	std::cout << "2026년 3월 3일" << '\n';

	save( "main.cpp" );		// "메인.cpp"를 저장하자
}

void save( const std::string& fname )
{
	std::cout << '\"' << fname << "\" 저장합니다" << '\n';

	std::ifstream in { fname };		// RAII - Resource Acquisition Is Initialization
	if ( not in )
	{
		std::cout << fname << " - 열 수 없습니다" << '\n';
		exit(20260303);
	}

	std::ofstream out { "2026 1학기 STL.txt", std::ios::app };

	// in의 내용을 읽어서 out에 덧붙이자.
	std::copy(std::istreambuf_iterator<char>{ in }, {},
		std::ostream_iterator<char>{ out });
}
