#pragma once

template <typename T>
class ObjectPool
{
public:
	ObjectPool() = delete;
	ObjectPool(size_t maxPoolSize);
	ObjectPool& operator=(const ObjectPool& rhs) = delete;
	ObjectPool(const ObjectPool& other) = delete;
	~ObjectPool();

	T& Get();
	void Return(const T* i);
	size_t GetFreeObjectCount() const;
	size_t GetMaxFreeObjectCount() const;
	

	
};

template <typename T>
ObjectPool<T>::ObjectPool(size_t maxPoolSize)
{
}

