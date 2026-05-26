//------------------------------------------------------------------
// STL의 내부를 들여다 보려고 만든 YString
// 
// 2026. 4. 8 시작
// 복사생성자			 - 2026. 4. 8
// 이동생성자			 - 2026. 4. 8
// 역방향 반복자 클래스	 - 2026. 5. 19
// 반복자 클래스			 - 2026. 5. 20
//------------------------------------------------------------------
#pragma once

#include <memory>

// 2026. 5. 19
class YString_Reverse_Iterator {
public:
	// 표준반복자가 되려면 다음 5가지 타입을 제공해야 한다.
	using iterator_category = std::random_access_iterator_tag;	// 무슨 반복자 타입인가
	using difference_type = std::ptrdiff_t;		// 반복자끼리 빼면, 어떤 자료형인가
	using value_type = char;					// 값의 타입
	using pointer = char*;						// 포인터로 바꿔서 표현하면 어떻게 되는가
	using reference = char&;					// 레퍼런스로 표현하면 어떻게 되는가 

public:
	YString_Reverse_Iterator( ) = default;
	YString_Reverse_Iterator(char* p) : p{ p } { }

	void operator++( ) {
		--p;
	}
	
	char operator*( ) const {
		return *(p - 1);
	}

	// 우주선 연산자를 코딩하면 관계연산자 6개가 자동생성된다.
	auto operator<=>(const YString_Reverse_Iterator& rhs) const = default;

private:
	char* p;
};

// 2026. 5. 20
class YString_Iterator {
public:
	// 표준반복자가 되려면 다음 5가지 타입을 제공해야 한다.
	using iterator_category = std::random_access_iterator_tag;	// 무슨 반복자 타입인가
	using difference_type = std::ptrdiff_t;	// 반복자끼리 빼면, 어떤 자료형인가
	using value_type = char;				// 값의 타입
	using pointer = char*;					// 포인터로 바꿔서 표현하면 어떻게 되는가
	using reference = char&;				// 레퍼런스로 표현하면 어떻게 되는가 

public:
	YString_Iterator( ) = default;
	YString_Iterator(char* p) : p{ p } {}

	auto operator<=>(const YString_Iterator& rhs) const = default;

	// 2026. 5. 20 std::sort가 실행되려면 최소한 이 연산자들이 필요함
	difference_type operator-(const YString_Iterator& rhs) const {
		return p - rhs.p;
	}

	YString_Iterator& operator++( ) {
		++p;
		return *this;
	}

	char& operator*( ) const {
		return *p;
	}

	YString_Iterator& operator--( ) {
		--p;
		return *this;
	}

	YString_Iterator operator+(const difference_type n) const {
		return p + n;
	}

	YString_Iterator operator-(const difference_type n) const {
		return p - n;
	}

private:
	char* p;
};


// ------------------------------------------------------------------------
// STL 컨테이너가 되도록 수정 중
// ------------------------------------------------------------------------
class YString {
public:
	// 표준 컨테이너가 되려면 다음 타입을 제공해야 한다.
	using iterator = YString_Iterator;
	// 2026. 5. 26
	using value_type = char;

public:
	YString( );
	~YString( );
	
	YString(const char* s);

	YString(const YString&);
	YString& operator=(const YString&);

	// C++11 move semantics
	// noexcept - 이동 생성자와 할당자는 예외 없음
	YString(YString&&) noexcept;
	YString& operator=(YString&&) noexcept;

	// 2026. 4. 28
	bool operator==(const YString& rhs) const;
	// 2026. 5. 26
	// set의 원소가 되려면 < 를 정의해야 한다.
	bool operator<(const YString& rhs) const;

	// 클래스의 special 함수를 관찰하려는 목적
	void special(std::string funcType) const;

	size_t getLen( ) const;
	void show( ) const;		// 2026. 4. 21 special 한 순간이 아닐 때 관찰
							// 2026. 4. 29 const 멤버로

	// 표준 컨테이너라면 다음 멤버를 제공해야
	size_t size( ) const;	// 2026. 4. 21
	char* data( ) const;	// 2026. 4. 21

	// 2026. 5. 13
	// 표준 반복자 인터페이스를 제공해야 STL 컨테이너이다
	// 2026. 5. 20
	// 반복자는 클래스로 코딩한다.
	YString_Iterator begin( ) const;
	YString_Iterator end( ) const;

	// 2026. 5. 19 역방향 반복자
	YString_Reverse_Iterator rbegin( ) const;
	YString_Reverse_Iterator rend( ) const;

private:
	size_t id{};
	size_t len{};
	std::unique_ptr<char[]> p{};

	static size_t g_id;		// 생성 시 부여될 고유 번호

	friend std::ostream& operator<<(std::ostream& os , const YString& ys);
	friend std::istream& operator>>(std::istream& is , YString& ys);
};

