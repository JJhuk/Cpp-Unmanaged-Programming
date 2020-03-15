#pragma once
#include "FixedVector.h"
namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		~FixedVector();
		FixedVector(const FixedVector& other);
		FixedVector& operator=(const FixedVector& rhs);
		bool Add(const bool& t);
		bool Remove(const bool& t); //처음 발견하는 T를 제거한다.
		bool Get(const unsigned int& index) const;
		bool operator[](const unsigned int& index);
		int GetIndex(const bool& t) const; //찾지 못했을때 -1 반환
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCapacity;
		size_t mSize;
		unsigned int mFixedVector;
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector() : mCapacity(N), mSize(0), mFixedVector(0)
	{
	}

	template <size_t N>
	FixedVector<bool, N>::~FixedVector()
	{
		mCapacity = 0;
		mSize = 0;
		mFixedVector = 0;
	}

	template <size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector& other)
		: mCapacity(other.mCapacity), mSize(other.mSize), mFixedVector(other.mFixedVector)
	{

	}

	template <size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector& rhs)
	{
		if (this != &rhs)
		{
			mCapacity = rhs.mCapacity;
			mSize = rhs.mSize;
			mFixedVector = rhs.mFixedVector;
		}
		return *this;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(const bool& t)
	{
		if (mSize >= mCapacity)
		{
			return false;
		}

		if (t)
		{
			mFixedVector |= (1 << mSize++);
		}
		else
		{
			mFixedVector &= ~(1 << mSize++);
		}
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool& t)
	{
		size_t index = static_cast<size_t>(GetIndex(t));
		if (index == -1) //없는 경우
		{
			return false;
		}
		unsigned int afterVector = 0;
		size_t afterSize = 0;

		for (afterSize = 0; afterSize < index; afterSize++)
		{
			if (mFixedVector & (1 << afterSize))
			{
				afterVector |= (1 << afterSize);
			}
			else
			{
				afterVector &= ~(1 << afterSize);
			}
		}

		for (size_t i = index + 1; i < mSize; i++)
		{
			if (mFixedVector & (1 << i))
			{
				afterVector |= (1 << afterSize++);
			}
			else
			{
				afterVector &= ~(1 << afterSize++);
			}
		}
		mSize--;
		mFixedVector = afterVector;
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(const unsigned& index) const
	{
		return mFixedVector & (1 << index);
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](const unsigned& index)
	{
		return mFixedVector & (1 << index);
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& t) const
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if ((mFixedVector & (1 << i)) == t)
			{
				return i;
			}
		}
		return -1;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return mCapacity;
	}
}
