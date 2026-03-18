//-------------------------------------------------------------------
// 2026 1학기 STL				3월 18일					(3주 2일)
//------------------------------------------------------------------
// 많은 수의 자료를 처리하기 - binary I/O
//------------------------------------------------------------------

#include <iostream>
#include <print>
#include <string>
#include <array>
#include <fstream>

#include "save.h"

class Dog {
public:
	Dog( ) {}
private:
	std::string name = "";		// 10 이상 30 이하 임의의 소문자
	int num = 0;

	friend std::ostream& operator<<(std::ostream& os , const Dog& dog) {
		std::print(os , "[{:4}] - {}" , dog.num , dog.name);
		return os;
	}
};

int main( )
{
	// [문제] 바이너리 모드로 저장한 파일 "Dog백마리"에는 Dog 객체 100개가 저장되어 있다.
	// Dog 객체는 파일의 write 함수를 사용하여 객체 크기 그대로 저장하였다.

	// 파일을 읽어 array에 저장하라.
	// 객체 수 100개는 실행동안 변경되지 않는다.

	std::ifstream in{ "Dog백마리", std::ios::binary };

	if ( not in ) {
		std::cout << "파일을 열 수 없습니다" << std::endl;
		return 2022184025;
	}

	std::array<Dog , 100> dogs;
	in.read(reinterpret_cast< char* >( dogs.data( ) ) , sizeof(Dog) * dogs.size( ));

	for ( const Dog& dog : dogs ) {
		std::cout << dog << std::endl;
	}

	save("main.cpp");		// "메인.cpp"를 저장하자
}