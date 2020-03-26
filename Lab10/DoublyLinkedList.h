#pragma once
#include "Node.h"
#include <memory>

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

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		unsigned int mSize;
		Node<T>* mHead;
		Node<T>* mTail;
		Node<T>* mCur;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList() :
	mSize(0), mHead(nullptr), mTail(nullptr), mCur(nullptr)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		mCur = data; 
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		Node<T>* tempNode = mHead;
		for(unsigned int i = 0; i < index; i++)
		{
			tempNode = tempNode->Next;
		}
		tempNode->Next->Previous = tempNode;
		tempNode->Next = tempNode;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		Node<T>* tempNode = mHead;
		for(size_t i = 0; i < mSize; i++)
		{
			if(mHead->Data == data)
			{
				return true;
			}
			tempNode = tempNode->Next;
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		auto x = std::make_unique<T>();
		std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(std::move(x));
		return temp;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mSize;
	}
}
