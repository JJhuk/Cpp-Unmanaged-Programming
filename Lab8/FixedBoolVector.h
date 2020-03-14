#pragma once
#include <iostream>
#include "FixedVector.h"
namespace lab8
{
	template < >
	class FixedVector<bool, size_t>
	{
	public:
		FixedVector();
		~FixedVector();
		FixedVector(const FixedVector& other);
		FixedVector& operator=(const FixedVector& rhs);
		bool Add(const T& t);
		bool Remove(const T& t); //처음 발견하는 T를 제거한다.
		bool Get(const unsigned int& index) const;
		bool& operator[](const unsigned int& index);
		int GetIndex(const T& t) const; //찾지 못했을때 -1 반환
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCapacity;
		size_t mSize;
		bool* mFixedVector;
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector() : mCapacity(N),mSize(0),mFixedVector(new bool[N])
	{
		std::cout << "템플릿 특수화";
	}
}
