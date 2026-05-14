//------------------------------------------------------------------
// 2026 1학기 STL				5월 12일					(11주 1일)
//------------------------------------------------------------------
// STL Iterator - Iterators are a generalization of pointers that allow a C++ program
//				to work with different data structures in a uniform manner.
//------------------------------------------------------------------
 
#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

#include "save.h"
#include "YString.h"

extern bool observe;

template<class Iter>
void f(Iter i)
{
	// 종류를 판단하고 싶다면 반복자로부터 반복자의 특성을 나타내는
	// 항목 중 다음을 이용하면 돈다

	std::cout << typeid( Iter::iterator_category ).name( ) << std::endl;
	/*Iter::value_type;
	Iter::pointer;
	Iter::reference;
	Iter::difference_type;*/
}

int main( )
{
	// 반복자의 종류를 알아본다.
	f(std::istream_iterator<char>{std::cin}); // 글자 입력해야 넘어감
	f(std::ostream_iterator<char>{std::cout});

	f(std::forward_list<int>::iterator{});
	f(std::list<YString>{}.begin());
	f(std::deque<char>{}.rbegin());
	f(std::vector<int>::const_iterator());

	save("main.cpp");		// "메인.cpp"를 저장하자
}