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
		void removeNormal(const unsigned arrIndex, const unsigned index);
		size_t mCapacity;
		size_t mSize;
		uint32_t mFixedVector[2];
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector() : mCapacity(N), mSize(0), mFixedVector{0,0}
	{
	}

	template <size_t N>
	FixedVector<bool, N>::~FixedVector()
	{
		mCapacity = 0;
		mSize = 0;
		mFixedVector[0] = 0;
		mFixedVector[1] = 0;
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
			if (mSize >= 32)
			{
				mFixedVector[1] |= (1 << (mSize-32));
				mSize++;
			}
			else
			{
				mFixedVector[0] |= (1 << mSize++);
			}
		}
		else
		{
			if (mSize >= 32)
			{
				mFixedVector[1] &= ~(1 << (mSize-32));
				mSize++;
			}
			else
			{
				mFixedVector[0] &= ~(1 << mSize++);
			}

		}
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool& t)
	{
		const size_t index = static_cast<size_t>(GetIndex(t));
		if (index == -1) //없는 경우
		{
			return false;
		}
		if(index >= 32)
		{
			removeNormal(1, index-32);
		}
		else if (mSize<=32 && index<32)
		{
			removeNormal(0, index);
		}
		else if (mSize>32 && index<32)
		{
			removeNormal(0, index);
			if(mFixedVector[1] & (1 << 0))	//뒷 배열첫번째 체크
			{
				mFixedVector[0] |= (1 << 31);
			}
			else
			{
				mFixedVector[0] &= ~(1 << 31);
			}
			removeNormal(1, 0);
			mSize++; //removeNormal 2번호출되면 size가 변경되기 때문.
		}
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(const unsigned& index) const
	{
		if (index >= 0 && index < 32)
		{
			return mFixedVector[0] & (1 << (index));
		}
		return mFixedVector[1] & (1 << (index-32));
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](const unsigned& index)
	{
		if(index>=0 && index < 32)
		{
			return mFixedVector[0] & (1 << (index));
		}
		return mFixedVector[1] & (1 << (index-32));
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& t) const
	{
		for(size_t i =0 ;i<2;i++)
		{
			for (size_t j = 0; j < mSize; j++)
			{
				if ((mFixedVector[i] & (1 << j)) == static_cast<uint32_t>(t))
				{
					return static_cast<int>(j+(64*i));
				}
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

	template <size_t N>
	void FixedVector<bool, N>::removeNormal(const unsigned arrIndex , const unsigned index)
	{
		uint32_t afterVector = 0;
		size_t afterSize = 0;

		for (afterSize = 0; afterSize < index; afterSize++)
		{
			if (mFixedVector[arrIndex] & (1 << afterSize))
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
			if (mFixedVector[arrIndex] & (1 << i))
			{
				afterVector |= (1 << afterSize++);
			}
			else
			{
				afterVector &= ~(1 << afterSize++);
			}
		}

		mSize--;
		mFixedVector[arrIndex] = afterVector;
		return;
	}
}
