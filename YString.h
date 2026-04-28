//------------------------------------------------------------------
// STL의 내부를 들여다 보려고 만든 YString
// 
// 2026.4.8 시작
// 복사생성자 - 2026.4.8
// 이동생성자 - 2026.4.8
//------------------------------------------------------------------
#pragma once

#include <memory>

class YString {
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

	size_t getLen( ) const;
	void show( );		// 2026. 4. 21 special 한 순간이 아닐 때 관찰

	// 표준 컨테이너라면 다음 멤버를 제공해야
	size_t size( ) const;	// 2026. 4. 21
	char* data( ) const;	// 2026. 4. 21

private:
	size_t id{};
	size_t len{};
	std::unique_ptr<char[]> p{};

	static size_t g_id;		// 생성 시 부여될 고유 번호

	friend std::ostream& operator<<(std::ostream& os , const YString& ys);

	// 클래스의 special 함수를 관찰하려는 목적
	void observation(std::string funcType) const;
};

