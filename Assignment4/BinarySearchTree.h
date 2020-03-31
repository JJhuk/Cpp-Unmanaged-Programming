#pragma once

#include <memory>
#include <vector>
#include "TreeNode.h"

using namespace std;

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		
		bool Search(const T& data);
		bool Search(const T& data, const shared_ptr<TreeNode<T>> &curNode);
		
		bool Delete(const T& data);
		bool Delete(const T& data, shared_ptr<TreeNode<T>> &curNode);
		
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static void TraverseInOrder(std::vector<T>& v, const std::shared_ptr<TreeNode<T>> startNode);
	private:
		shared_ptr<TreeNode<T>> mRootNode = nullptr;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = make_unique<TreeNode<T>>(move(data));
			return;
		}
		
		TreeNode<T>* prevNode = mRootNode.get();
		TreeNode<T>* tempNode = mRootNode.get();
		while(tempNode != nullptr)
		{
			if(tempNode->Data < data)
			{
				tempNode = tempNode->Right.get();
			}
			else
			{
				tempNode = tempNode->Left.get();
			}
		}
		if(prevNode->Data < data)
		{
			prevNode->Right = make_shared<TreeNode<T>>(data);
		}
		else
		{
			prevNode->Left = make_shared<TreeNode<T>>(data);
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return make_shared<TreeNode<T>>(mRootNode);
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		
		return Search(data,mRootNode);
	}

	template <typename T>
	bool BinarySearchTree<T>::Search(const T& data,const shared_ptr<TreeNode<T>> &curNode)
	{
		while(curNode != nullptr)
		{
			if (data == *curNode->Data)
			{
				return true;
			}
			if(data < *curNode->Data)
			{
				return Search(data, curNode->Left);
			}
			if(data > *curNode->Data)
			{
				return Search(data, curNode->Right);
			}
		}
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return Delete(data, mRootNode);
	}

	template <typename T>
	bool BinarySearchTree<T>::Delete(const T& data, shared_ptr<TreeNode<T>>& curNode)
	{
		if(curNode && data < *curNode->Data)
		{
			return Delete(data, curNode->Left);
		}
		if (curNode && data > *curNode->Data)
		{
			return Delete(data, curNode->Right);
		}
		if (curNode && data == *curNode->Data)
		{
			if(!curNode->Left)
			{
				curNode = curNode->Right;
			}
			else if(!curNode->Right)
			{
				curNode = curNode->Left;
			}
			else
			{
				shared_ptr<TreeNode<T>> tempNode = curNode->Left;
				while(tempNode->Right)
				{
					tempNode = tempNode->Right;
				}
				curNode = tempNode;
				Delete(*tempNode->Data, tempNode->Left);
			}
			return true;
		}
		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		TraverseInOrder(v,startNode);
		return v;
	}

	template <typename T>
	void BinarySearchTree<T>::TraverseInOrder(std::vector<T>& v, const std::shared_ptr<TreeNode<T>> startNode)
	{
		if (startNode->Left == nullptr)
		{
			return;
		}
		TraverseInOrder(v, startNode->Left);
		v.push_back(*startNode->Data);
		TraverseInOrder(v, startNode->Right);
	}


}
