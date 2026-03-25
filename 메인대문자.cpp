//------------------------------------------------------------------
// 2026 1학기 STL				3월 25일					(4주 2일)
//------------------------------------------------------------------
// CALLABLE TYPE - 실습 - STL
//------------------------------------------------------------------

#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>

#INCLUDE "SAVE.H"

// [문제] "MAIN.CPP"에 있는 글자 중에서 소문자는 모두 대문자로 바꿔(다른 건 그대로)
// "메인대문자.CPP"에 저장하시오

INT MAIN( )
{
	STD::IFSTREAM IN{ "MAIN.CPP" };

	IF ( NOT IN ) {
		STD::COUT << "파일 읽기 오류" << STD::ENDL;
		RETURN 2022184025;
	}

	STD::OFSTREAM OUT{ "메인대문자.CPP" };

	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {} , STD::OSTREAMBUF_ITERATOR<CHAR>{OUT},
		 []( CHAR C ) {
			C = ::TOUPPER(C);
			RETURN C;
		});	// CALLABLE TYPE

	SAVE("MAIN.CPP");		// "메인.CPP"를 저장하자
}