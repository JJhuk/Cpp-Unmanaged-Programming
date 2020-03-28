#pragma once
#include "Node.h"
#include <memory>
#include <iostream>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;
		void PrintDoublyLinkedList() const;
		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:

		unsigned int mSize;
		shared_ptr<Node<T>> mHead;
		shared_ptr<Node<T>> mTail;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList() :
		mSize(0), mHead(nullptr), mTail(nullptr)
	{

	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mHead == nullptr && mTail == nullptr)
		{
			mTail = make_shared<Node<T>>(std::move(data), mHead);
			mHead = mTail;
		}
		else
		{
			mTail->Next = make_shared<Node<T>>(std::move(data), mTail);
			mTail = mTail->Next;
		}
		mSize++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index >= mSize - 1)
		{
			mTail->Next = make_shared<Node<T>>(std::move(data), mTail);
			mTail = mTail->Next;
		}
		else if (index == 0)
		{
			auto mInsert = make_shared<Node<T>>(std::move(data));
			mInsert->Next = mHead;
			mHead->Previous = mInsert;
			mHead = mInsert;
		}
		else
		{
			shared_ptr<Node<T>> nowIndex = mHead;
			for (unsigned int i = 0; i < index; i++)
			{
				nowIndex = nowIndex->Next;
			}
			auto mInsert = make_shared<Node<T>>(std::move(data), nowIndex->Previous.lock());
			nowIndex->Previous.lock()->Next = mInsert;

			nowIndex->Previous = mInsert;
			mInsert->Next = nowIndex;
		}
		mSize++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		shared_ptr<Node<T>> nowIndex = mHead;
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (*(nowIndex->Data) == data)
			{
				if (nowIndex != mHead && nowIndex != mTail)
				{
					nowIndex->Previous.lock()->Next = nowIndex->Next;
					nowIndex->Next->Previous = nowIndex->Previous;
				}
				else if (nowIndex == mHead)
				{
					if (mSize == 1)
					{
						mHead.reset();
						mTail.reset();
					}
					else
					{
						mHead = mHead->Next;
						mHead->Previous.reset();
					}
				}
				else
				{
					mTail->Previous.lock()->Next = nullptr;
					mTail = mTail->Previous.lock();
					mTail->Next = nullptr;
				}
				mSize--;
				return true;
			}
			nowIndex = nowIndex->Next;
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		shared_ptr<Node<T>> nowIndex = mHead;
		for (unsigned int i = 0; i < mSize; i++)
		{
			if (*(nowIndex->Data) == data)
			{
				return true;
			}
			nowIndex = nowIndex->Next;
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mSize)
		{
			return nullptr;
		}
		shared_ptr<Node<T>> nowIndex = mHead;
		for (unsigned int i = 0; i < index; i++)
		{
			nowIndex = nowIndex->Next;
		}
		return nowIndex;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mSize;
	}

	template <typename T>
	void DoublyLinkedList<T>::PrintDoublyLinkedList() const
	{
		shared_ptr<Node<T>> nowIndex = mHead;
		for (unsigned int i = 0; i < mSize; i++)
		{
			std::cout << *(nowIndex->Data) << " ";
			nowIndex = nowIndex->Next;
		}
		std::cout << "\n";
	}
}
