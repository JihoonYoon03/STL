//------------------------------------------------------------------
// 2026 1학기 STL				4월 7일					(6주 1일)
//------------------------------------------------------------------
// STL 컨테이너 - std::string을 코딩하여 STL 컨테이너에 필요한 것들을 알아본다
//------------------------------------------------------------------

#include <iostream>
#include <memory>
#include <print>

#include "save.h"

class YString {
public:
	YString( ) = default;

	YString(const char* s) {
		len = std::strlen(s);
		p = std::make_unique<char[]>(len);
		memcpy(p.get( ) , s , len);

		//std::cout << "생성(char*) 글자수: " << len << ", 주소: " << this << ", 글자주소: " << (void*)p.get() << std::endl;
		std::println("생성(char*) 글자수: {}, 주소: {}, 글자주소: {}" , len , ( void* )this , ( void* )p.get( ));
	}

private:
	size_t len{};
	std::unique_ptr<char[]> p{};

	friend std::ostream& operator<<(std::ostream& os , const YString& ys) {
		for ( int i = 0; i < ys.len; ++i ) {
			os << *( ys.p.get( ) + i );
		}
		return os;
	}
};

int main( )
{
	YString s{ "2026년 4월 7일" };

	std::cout << "s - " << s << std::endl;

	//save("main.cpp");		// "메인.cpp"를 저장하자
}
