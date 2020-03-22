#pragma once
#include <queue>
#include <memory>

using namespace std;

namespace lab9
{
	template <typename T>
	class ObjectPool final
	{
	public:
		ObjectPool() = delete;
		ObjectPool(size_t maxPoolSize);
		ObjectPool& operator=(const ObjectPool& rhs) = delete;
		ObjectPool(const ObjectPool& other) = delete;
		~ObjectPool();

		T* Get();
		void Return(T*& i);
		size_t GetFreeObjectCount() const;
		size_t GetMaxFreeObjectCount() const;


	private:
		queue<unique_ptr<T>> mQueue;
		size_t mMaxPoolSize;
	};

	template <typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize) : mMaxPoolSize(maxPoolSize)
	{

	}

	template <typename T>
	ObjectPool<T>::~ObjectPool()
	{
		while (!mQueue.empty())
		{
			mQueue.pop();
		}
		mMaxPoolSize = 0;
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mQueue.empty())
		{
			unique_ptr<T> mPtr = make_unique<T>();
			return mPtr.release();
		}

		unique_ptr<T> mPtr = move(mQueue.front());
		mQueue.pop();

		return mPtr.release();
	}

	template <typename T>
	void ObjectPool<T>::Return(T*& i)
	{
		if (mQueue.size() == mMaxPoolSize)
		{
			delete i;
			i = nullptr;
			return;
		}
		mQueue.push(unique_ptr<T>(i));
	}

	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mQueue.size();
	}

	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}
