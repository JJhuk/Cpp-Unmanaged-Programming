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

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
	{
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
	{
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		std::unique_ptr<T[]> temp = std::make_unique<T[]>(1);
		return std::move(temp);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return 0;
	}
}
