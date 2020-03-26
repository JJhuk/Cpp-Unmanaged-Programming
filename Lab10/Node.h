#pragma once

#include <memory>
using namespace std;
namespace lab10
{
	template<typename T>
	class Node
	{
	public:
		Node(std::unique_ptr<T> data);
		Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev);
		std::unique_ptr<T> Data;
		std::shared_ptr<Node<T>> Next;
		std::weak_ptr<Node<T>> Previous;

	};

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data)
	{
		Data = move(data);
		Next = nullptr;
		Previous = nullptr;
	}

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev)
	{
		Data = move(data);
		Previous = prev;
	}
}
