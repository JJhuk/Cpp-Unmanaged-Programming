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
		const bool Get(const unsigned int& index) const;
		const bool operator[](const unsigned int& index);
		int GetIndex(const bool& t) const; //찾지 못했을때 -1 반환
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		void removeNormal(const unsigned arrIndex, const unsigned index);
		size_t mCapacity;
		size_t mSize;
		uint32_t mFixedVector[N / 32 + 1];
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector() : mCapacity(N), mSize(0), mFixedVector{ 0 }
	{
		for (size_t i = 0; i < N / 32 + 1; i++)
		{
			mFixedVector[i] = 0;
		}
	}

	template <size_t N>
	FixedVector<bool, N>::~FixedVector()
	{

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
			mFixedVector[mSize / 32] |= (1 << (mSize % 32));
			mSize++;
		}
		else
		{
			mFixedVector[mSize / 32] &= ~(1 << (mSize % 32));
			mSize++;
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
		if (index / 33 == N / 33)
		{
			removeNormal(index / 33, index - 32 * (index / 33));
		}
		else //중간에 있는걸 땡겨와야함.
		{

			uint32_t mBeforeVector[N / 32 + 1];
			memset(mBeforeVector, 0, sizeof(mBeforeVector));
			size_t arrayIndex = 0;
			for (size_t nowIndex = 0; nowIndex < mSize; nowIndex++)
			{
				if (nowIndex < index)
				{
					if ((nowIndex % 33 + 1) != 32) //그냥
					{
						if ((arrayIndex + 1) != N / 32)
						{
							if (mFixedVector[arrayIndex] & (1 << nowIndex % 33))
							{
								mBeforeVector[arrayIndex] |= (1 << (nowIndex % 33));
							}
							else
							{
								mBeforeVector[arrayIndex] &= ~(1 << (nowIndex % 33));
							}
						}
					}
					else //땡겨와야함
					{
						if (mFixedVector[arrayIndex + 1] & (1 << 0))
						{
							mBeforeVector[arrayIndex] |= (1 << (nowIndex % 33));
						}
						else
						{
							mBeforeVector[arrayIndex] &= ~(1 << (nowIndex % 33));
						}
						arrayIndex++;
					}
				}
				else if (nowIndex >= index)
				{
					if ((nowIndex % 33) + 1 == 32) //그 앞에 수가 다음 배열에 있다면
					{
						if ((arrayIndex + 1) != (N / 32) + 1) //맨 뒤 배열이 없을때가 아니라면
						{
							if (mFixedVector[arrayIndex + 1] & (1 << 0))
							{
								mBeforeVector[arrayIndex] |= (1 << (nowIndex % 33));
							}
							else
							{
								mBeforeVector[arrayIndex] &= ~(1 << (nowIndex % 33));
							}
							arrayIndex++;
						}
					}
					else //그냥 바로 뒤에꺼 땡겨옴
					{
						if (mFixedVector[arrayIndex] & (1 << ((nowIndex % 33) + 1)))
						{
							mBeforeVector[arrayIndex] |= (1 << (nowIndex % 33));
						}
						else
						{
							mBeforeVector[arrayIndex] &= ~(1 << (nowIndex % 33));
						}
					}
				}
			}
			memcpy(mFixedVector, mBeforeVector, sizeof(mFixedVector));
			mSize--;
		}
		return true;
	}

	template <size_t N>
	const bool FixedVector<bool, N>::Get(const unsigned& index) const
	{
		return mFixedVector[(index / 32)] & (1 << (index));
	}

	template <size_t N>
	const bool FixedVector<bool, N>::operator[](const unsigned& index)
	{
		return mFixedVector[(index / 32)] & (1 << (index));
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& t) const
	{
		for (size_t i = 0; i < (mSize / 32) + 1; i++)
		{
			for (size_t j = 0; j < mSize; j++)
			{
				if ((mFixedVector[i] & (1 << j)) == static_cast<uint32_t>(t))
				{
					return static_cast<int>(j + (64 * i));
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
	void FixedVector<bool, N>::removeNormal(const unsigned arrIndex, const unsigned index)
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

		for (size_t i = index + 1; i < 32; i++)
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
