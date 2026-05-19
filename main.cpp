//------------------------------------------------------------------
// 2026 1학기 STL				5월 12일					(11주 1일)
//------------------------------------------------------------------
// STL Iterator - Iterators are a generalization of pointers that allow a C++ program
//				to work with different data structures in a uniform manner.
// 
// pointer의 up_casting = iterator, generalization
// iterator의 down_casting = output / input<-forward<-bidirectional<-random_access iterator, specialization
// iterator는 category 존재 (input, output, contiguous(C++17)). 효율성을 위해 나누었다.
// contiguous는 캐시 효율성이 뛰어나다. memcpy같은 데이터 카피도 매우 효율적이다. SIMD 최적화.
//------------------------------------------------------------------
 
#include <iostream>

#include "save.h"
#include "YString.h"

extern bool observe;

int main( )
{
	save("main.cpp");

	YString ys{ "jackdaws love my big sphinx of quartz" };

	// 거꾸로 출력 - uniform manner
	for ( auto i = ys.rbegin( ); i != ys.rend( ); ++i ) {
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
}