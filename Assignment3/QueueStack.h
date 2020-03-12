#pragma once
#include <stack>
#include <queue>
#include <limits>
#include <cmath>
using namespace std;
namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack();
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& other);
		~QueueStack();
		QueueStack& operator=(const QueueStack<T>& rhs);

		void Enqueue(const T& number);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum() const;
		unsigned int GetCount();
		unsigned int GetStackCount() const;
	private:
		queue<stack<T>> mQueueStack;
		unsigned int mMaxStackSize;
		T mSum;
	};

	template <typename T>
	QueueStack<T>::QueueStack() : mMaxStackSize(NULL), mSum(0)
	{
	}

	template <typename T>
	QueueStack<T>::QueueStack(unsigned maxStackSize) :
		mMaxStackSize(maxStackSize), mSum(0)
	{
	}

	template <typename T>
	QueueStack<T>::QueueStack(const QueueStack& other) : mQueueStack(other.mQueueStack),
		mMaxStackSize(other.mMaxStackSize), mSum(other.mSum)
	{
	}

	template <typename T>
	QueueStack<T>::~QueueStack()
	{

	}

	template <typename T>
	QueueStack<T>& QueueStack<T>::operator=(const QueueStack<T>& rhs)
	{
		if (this != &rhs)
		{
			mQueueStack = rhs.mQueueStack;
			mMaxStackSize = rhs.mMaxStackSize;
			mSum = rhs.mSum;
		}
		return *this;
	}

	template <typename T>
	void QueueStack<T>::Enqueue(const T& number)
	{
		if (mQueueStack.empty())
		{
			stack<T> tempStack;
			tempStack.push(number);
			mQueueStack.push(tempStack);
		}
		else
		{
			if (mQueueStack.back().size() == mMaxStackSize)
			{
				stack<T> tempStack;
				tempStack.push(number);
				mQueueStack.push(tempStack);
			}
			else
			{
				mQueueStack.back().push(number);
			}
		}
		mSum += number;
	}

	template <typename T>
	T QueueStack<T>::Peek() const
	{
		return mQueueStack.front().top();
	}

	template <typename T>
	T QueueStack<T>::Dequeue()
	{
		T tempVal = mQueueStack.front().top();
		mSum -= tempVal;
		mQueueStack.front().pop();
		if (mQueueStack.front().empty())
		{
			mQueueStack.pop();
		}
		return tempVal;
	}

	template <typename T>
	T QueueStack<T>::GetMax()
	{
		T mMax = numeric_limits<T>::lowest();
		size_t qSize = mQueueStack.size();
		while (qSize-- > 0)
		{
			stack<T> tempStack = mQueueStack.front();
			mQueueStack.pop();
			mQueueStack.push(tempStack);
			while (!tempStack.empty())
			{
				T temp = tempStack.top();
				tempStack.pop();
				mMax = mMax > temp ? mMax : temp;
			}
		}
		return mMax;
	}

	template <typename T>
	T QueueStack<T>::GetMin()
	{
		T mMin = numeric_limits<T>::max();
		size_t qSize = mQueueStack.size();
		while (qSize-- > 0)
		{
			stack<T> tempStack = mQueueStack.front();
			mQueueStack.pop();
			mQueueStack.push(tempStack);
			while (!tempStack.empty())
			{
				T temp = tempStack.top();
				tempStack.pop();
				mMin = mMin < temp ? mMin : temp;
			}
		}
		return mMin;
	}

	template <typename T>
	double QueueStack<T>::GetAverage()
	{
		if (mQueueStack.empty())
		{
			return 0;
		}
		const unsigned int size = GetCount();
		return round((static_cast<double>(mSum) / static_cast<double>(size)) * 1000.0) / 1000.0;
	}

	template <typename T>
	T QueueStack<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		unsigned int count = 0;
		size_t queueStackSize = mQueueStack.size();
		while (queueStackSize--)
		{
			count += mQueueStack.front().size();
			mQueueStack.push(mQueueStack.front());
			mQueueStack.pop();
		}
		return count;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mQueueStack.size();
	}
}


