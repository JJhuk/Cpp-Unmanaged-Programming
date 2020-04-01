#pragma once
#include <iostream>
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
		shared_ptr<TreeNode<T>>  Search(const T& data, const shared_ptr<TreeNode<T>>& curNode);

		bool Delete(const T& data);
		shared_ptr<TreeNode<T>> FindSubMin(shared_ptr<TreeNode<T>> curNode);


		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static void TraverseInOrder(std::vector<T>& v, const std::shared_ptr<TreeNode<T>> startNode);

		void PrintInOrder() const;
	private:
		shared_ptr<TreeNode<T>> mRootNode;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (!mRootNode)
		{
			mRootNode = make_shared<TreeNode<T>>(std::move(data));
			return;
		}

		shared_ptr<TreeNode<T>> tempNode = mRootNode;
		shared_ptr<TreeNode<T>> prevNode = mRootNode;

		while (tempNode)
		{
			prevNode = tempNode;
			if (*(tempNode->Data) < *data)
			{
				tempNode = tempNode->Right;
			}
			else
			{
				tempNode = tempNode->Left;
			}
		}
		if (*(prevNode->Data) < *data)
		{
			prevNode->Right = make_shared<TreeNode<T>>(std::move(data));
			prevNode->Right->Parent = prevNode;
		}
		else
		{
			prevNode->Left = make_shared<TreeNode<T>>(std::move(data));
			prevNode->Left->Parent = prevNode;
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		weak_ptr<TreeNode<T>> weak_ptr = mRootNode;
		return weak_ptr;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		return Search(data, mRootNode) ? true : false;
	}

	template <typename T>
	shared_ptr<TreeNode<T>>  BinarySearchTree<T>::Search(const T& data, const shared_ptr<TreeNode<T>>& curNode)
	{
		while (curNode != nullptr)
		{
			if (data == *curNode->Data)
			{
				return curNode;
			}
			if (data < *curNode->Data)
			{
				return Search(data, curNode->Left);
			}
			if (data > * curNode->Data)
			{
				return Search(data, curNode->Right);
			}
		}
		return nullptr;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		shared_ptr<TreeNode<T>> tempNode = Search(data, mRootNode);
		//Not Found
		if (!tempNode)
		{
			return false;
		}
		//No Child
		if (!tempNode->Right && !tempNode->Left)
		{
			//부모가 자식 노드를 끊어버리기
			if (!tempNode->Parent.expired())
			{
				if (tempNode->Parent.lock()->Right == tempNode)
				{
					tempNode->Parent.lock()->Right = nullptr;
				}
				else
				{
					tempNode->Parent.lock()->Left = nullptr;
				}
				//자식도 부모 노드를 끊어버리기
				tempNode->Parent.reset();
			}
			else
			{
				mRootNode.reset();
			}
		}
		//Two Child
		else if (tempNode->Right && tempNode->Left)
		{
			shared_ptr<TreeNode<T>> minNode = FindSubMin(tempNode->Right);

			//기존의 부모노드를 끊어버림.
			if (minNode->Parent.lock()->Right == minNode)
			{
				minNode->Parent.lock()->Right = minNode->Left;
			}
			else
			{
				minNode->Parent.lock()->Left = minNode->Right;
				if (minNode->Right)
				{
					minNode->Right->Parent = minNode->Parent;
				}
			}
			minNode->Parent = tempNode->Parent;

			//새로 바뀐 부모노드의 자식을 변경함.
			if (!tempNode->Parent.expired())
			{
				if (tempNode->Parent.lock()->Right == tempNode)
				{
					tempNode->Parent.lock()->Right = minNode;
				}
				else
				{
					tempNode->Parent.lock()->Left = minNode;
				}
			}
			else //부모가 없으면 그친구가 root
			{
				mRootNode = minNode;
			}

			if (tempNode->Left)
			{
				tempNode->Left->Parent = minNode;
				minNode->Left = tempNode->Left;
			}
			if (tempNode->Right)
			{
				tempNode->Right->Parent = minNode;
				minNode->Right = tempNode->Right;
			}


			tempNode->Parent.reset();
		}
		else //one child
		{
			if (tempNode->Right)
			{
				if (!tempNode->Parent.expired())
				{
					if (tempNode->Parent.lock()->Right == tempNode)
					{
						tempNode->Parent.lock()->Right = tempNode->Right;
					}
					else
					{
						tempNode->Parent.lock()->Left = tempNode->Right;
					}
					tempNode->Right->Parent = tempNode->Parent;
				}
				else
				{
					tempNode->Right->Parent.reset();
					mRootNode = tempNode->Right;
				}
			}
			else //왼쪽
			{
				if (!tempNode->Parent.expired()) //root 노트가 아니라면
				{
					if (tempNode->Parent.lock()->Right == tempNode)
					{
						tempNode->Parent.lock()->Right = tempNode->Left;
					}
					else
					{
						tempNode->Parent.lock()->Left = tempNode->Left;
					}
					tempNode->Left->Parent = tempNode->Parent;
				}
				else//root node
				{
					tempNode->Left->Parent.reset();
					mRootNode = tempNode->Left;
				}
			}
		}
		return  true;
	}


	template <typename T>
	shared_ptr<TreeNode<T>> BinarySearchTree<T>::FindSubMin(shared_ptr<TreeNode<T>> curNode)
	{
		while (curNode->Left)
		{
			curNode = curNode->Left;
		}
		return curNode;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		TraverseInOrder(v, startNode);
		return v;
	}

	template <typename T>
	void BinarySearchTree<T>::TraverseInOrder(std::vector<T>& v, const std::shared_ptr<TreeNode<T>> startNode)
	{
		if (!startNode)
		{
			return;
		}
		TraverseInOrder(v, startNode->Left);
		v.push_back(*startNode->Data);
		TraverseInOrder(v, startNode->Right);
	}

	template <typename T>
	void BinarySearchTree<T>::PrintInOrder() const
	{
		for (int a : TraverseInOrder(mRootNode))
		{
			std::cout << a << " ";
		}
		cout << std::endl;
	}
}
