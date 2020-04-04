#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(Storage&& other);
		Storage(const Storage& other);

		Storage& operator=(const Storage& rhs);
		Storage& operator=(Storage&& rhs);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArr;
		unsigned mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length) : mLength(length)
	{
		mArr = std::make_unique<T[]>(mLength);

		for (unsigned i = 0; i < mLength; i++)
		{
			mArr[i] = static_cast<T>(0);
		}
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue) : mLength(length)
	{
		mArr = std::make_unique<T[]>(mLength);

		for (unsigned i = 0; i < mLength; i++)
		{
			mArr[i] = initialValue;
		}
	}

	template <typename T>
	Storage<T>::Storage(Storage&& other)
	{
		if (this != &other)
		{
			mArr.reset();
			mArr = std::move(other.mArr);
			mLength = other.mLength;
			other.mLength = 0;
		}
	}

	template <typename T>
	Storage<T>::Storage(const Storage& other)
	{
		mLength = other.mLength;
		mArr = std::make_unique<T[]>(mLength);
		for (unsigned i = 0; i < mLength; i++)
		{
			mArr[i] = other.mArr[i];
		}
	}

	template <typename T>
	Storage<T>& Storage<T>::operator=(const Storage& rhs)
	{
		if (this != &rhs)
		{
			mArr.reset();
			mLength = rhs.mLength;
			mArr = std::make_unique<T[]>(mLength);
			for (unsigned i = 0; i < mLength; i++)
			{
				mArr[i] = rhs.mArr[i];
			}
		}
		return *this;
	}

	template <typename T>
	Storage<T>& Storage<T>::operator=(Storage&& rhs)
	{
		if (this != &rhs)
		{
			mArr.reset();
			mArr = std::move(rhs.mArr);
			mLength = rhs.mLength;
			rhs.mLength = 0;
		}
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= 0 && index < mLength)
		{
			mArr[index] = data;
			return true;
		}
		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArr);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}
