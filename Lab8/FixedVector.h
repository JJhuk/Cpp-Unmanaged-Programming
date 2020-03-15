#pragma once

namespace lab8
{
	template <typename  T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		~FixedVector();
		FixedVector(const FixedVector& other);
		FixedVector& operator=(const FixedVector& rhs);
		bool Add(const T& t);
		bool Remove(const T& t); //처음 발견하는 T를 제거한다.
		const T Get(const unsigned int& index) const;
		T& operator[](const unsigned int& index);
		int GetIndex(const T& t) const; //찾지 못했을때 -1 반환
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mCapacity;
		size_t mSize;
		T* mFixedVector;
	};

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector() :
		mFixedVector(new T[N]), mCapacity(N), mSize(0)
	{
	}

	template <typename T, size_t N>
	FixedVector<T, N>::~FixedVector()
	{
		delete[] mFixedVector;
	}

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector& other)
	{
		if (mFixedVector != nullptr)
		{
			delete[] mFixedVector;
		}
		mCapacity = other.mCapacity;
		mSize = other.mSize;
		mFixedVector = new T[mCapacity];
		for (size_t i = 0; i < other.mSize; i++)
		{
			mFixedVector[i] = other.mFixedVector[i];
		}
	}

	template <typename T, size_t N>
	FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector& rhs)
	{
		if (this != &rhs)
		{
			if (mFixedVector != nullptr)
			{
				delete[] mFixedVector;
			}

			mCapacity = rhs.mCapacity;
			mSize = rhs.mSize;

			mFixedVector = new T[mCapacity];
			for (size_t i = 0; i < rhs.mSize; i++)
			{
				mFixedVector[i] = rhs.mFixedVector[i];
			}
		}
		return *this;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= 0 && mSize < mCapacity)
		{
			mFixedVector[mSize++] = t;
			return true;
		}
		return false;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mFixedVector[i] == t)
			{
				for (size_t j = i + 1; j < mSize; j++)
				{
					mFixedVector[j - 1] = mFixedVector[j];
				}
				mFixedVector[mSize - 1] = NULL;
				mSize--;
				return true;
			}
		}
		return false;
	}

	template <typename T, size_t N>
	const T FixedVector<T, N>::Get(const unsigned& index) const
	{
		return mFixedVector[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](const unsigned& index)
	{
		return mFixedVector[index];
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t) const
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mFixedVector[i] == t)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return mCapacity;
	}
}