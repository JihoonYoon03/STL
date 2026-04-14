//------------------------------------------------------------------
// STL의 내부를 들여다 보려고 만든 YString
// 
// 2026.4.8 시작
//------------------------------------------------------------------
#include <iostream>
#include <string>
#include <print>

#include "YString.h"

bool observe{ false };
size_t YString::g_id{};

YString::YString( )
	: id{ ++g_id }
{
	if ( observe ) {
		observation("디폴트");
	}
}

// 이 소멸자는 만들 이유가 전혀 없으나 관찰용으로 만듦.
YString::~YString( )
{
	if ( observe ) {
		observation("소멸");
	}
}

// 이건 스페셜 함수가 아니다
YString::YString(const char* s)
	: id{ ++g_id }
{
	len = std::strlen(s);
	p = std::make_unique<char[]>(len);
	memcpy(p.get( ) , s , len);

	if ( observe ) {
		observation("생성(*)");
	}
}

YString::YString(const YString& other)
	: id{ ++g_id }
{
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get( ) , other.p.get( ) , len);

	if ( observe ) {
		observation("복사생성");
	}
}

YString& YString::operator=(const YString& other)
{
	// 자기 자신을 할당할 이유는 없다
	if ( this == &other )
		return *this;

	// 먼저 나를 정리한다 - p의 동작을 알아봐야 한다
	p.reset( );

	// 나를 other와 같게 만든다
	len = other.len;
	p = std::make_unique<char[]>(len);
	memcpy(p.get( ) , other.p.get( ) , len);

	if ( observe ) {
		observation("복사할당");
	}
}

// 2026.4.8 
// 2026.04.14 트랜잭션 안전성 보장 필요(원본 데이터 안전성 보장)
YString::YString(YString&& other) noexcept
	: id{ ++g_id }
{
	id = other.id;
	len = other.len; 
	p.reset(other.p.release( ));

	other.len = 0;

	if ( observe ) {
		observation("이동생성");
	}
}

YString& YString::operator=(YString&& other) noexcept
{
	if ( this == &other )
		return *this;

	len = other.len;
	p.reset(other.p.release( ));

	other.len = 0;

	if ( observe ) {
		observation("이동할당");
	}
}

// 2026.4.8
size_t YString::getLen( ) const
{
	return len;
}


std::ostream& operator<<(std::ostream& os , const YString& ys)
{
	for ( int i = 0; i < ys.len; ++i )
		os << *( ys.p.get( ) + i );
	return os;
}

void YString::observation(std::string funcType) const
{
	std::string text;
	size_t printNum = 10;
	if ( len < printNum )
		printNum = len;
	for ( int i = 0; i < len; ++i )
		text += p.get( )[ i ];

	std::println("[{:8}] {:8} - 객체:{:#016X} 글자:{:#016X} 개수:{:<4} 내용:{}" ,
		id , funcType , ( unsigned long long )this , ( unsigned long long )p.get( ) , len , text);
}