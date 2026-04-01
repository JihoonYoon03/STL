//------------------------------------------------------------------
// 2026 1학기 STL				4월 1일					(5주 2일)
//------------------------------------------------------------------
// 연습
//------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <array>
#include <ranges>
#include <print>

#include "save.h"

class Dog {
	friend std::ostream& operator<<(std::ostream& os , const Dog& dog) {
		std::print("{:7}, {}" , dog.id , dog.name);
		return os;
	}

	Dog& operator=(Dog& other) {
		*this = other;
	}

private:
	std::string name;	// [1, 16]
	size_t		id;		// [1, 999'9999]
};

// [문제] 바이너리 파일 "Dog천만마리"에는 write로 Dog 천만 객체를 기록하였다.
// array에 모든 객체를 읽어와라.
// 앞에서 100개를 화면에 출력하라

std::array<Dog , 1000'0000> dogs;

int main( )
{
	std::ifstream in{ "Dog천만마리", std::ios::binary };

	if ( not in ) {
		std::cout << "파일 읽기 문제 발생" << std::endl;
		return 2022184025;
	}

	std::copy(std::istreambuf_iterator(in), std::istreambuf_iterator(in), dogs.begin());

	for ( const Dog& dog : dogs | std::views::take(100) ) {
		std::cout << dog << std::endl;
	}

	//save("main.cpp");		// "메인.cpp"를 저장하자
}