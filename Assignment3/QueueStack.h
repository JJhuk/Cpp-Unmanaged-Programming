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
		QueueStack& operator=(const QueueStack& rhs);

		void Enqueue(const T& number);
		T Peek() const;
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		unsigned int GetCount() const;
		unsigned int GetStackCount() const;
	private:
		queue<stack<T>> mQueueStack;
		unsigned int mMaxStackSize;
		unsigned int mSize;
		void RenewSmartQueue();
		T mMax;
		T mMin;
		T mSum;
		T mAvg;
	};

	template <typename T>
	QueueStack<T>::QueueStack() : mMaxStackSize(NULL), mSize(0),
		mMax(numeric_limits<T>::min()), mMin(numeric_limits<T>::max()),
		mSum(0), mAvg(0)
	{
	}

	template <typename T>
	QueueStack<T>::QueueStack(unsigned maxStackSize) : mMaxStackSize(maxStackSize), mSize(0),
		mMax(numeric_limits<T>::min()), mMin(numeric_limits<T>::max()),
		mSum(0), mAvg(0)
	{
	}

	template <typename T>
	QueueStack<T>::QueueStack(const QueueStack& other) : mMaxStackSize(other.mMaxStackSize),
		mMax(other.mMax), mMin(other.mMin), mSize(other.mSize),
		mSum(other.mSum), mAvg(other.mAvg)
	{
		mQueueStack = other.mQueueStack;
	}

	template <typename T>
	QueueStack<T>::~QueueStack()
	{

	}

	template <typename T>
	QueueStack<T>& QueueStack<T>::operator=(const QueueStack& rhs)
	{
		if (this != &rhs)
		{
			mQueueStack = rhs.mQueueStack;
			mMaxStackSize = rhs.mMaxStackSize;
			mSize = rhs.mSize;
			mMax = rhs.mMax;
			mSum = rhs.mSum;
			mAvg = rhs.mAvg;
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
		mSize++;
		mSum += number;
		mAvg = static_cast<double>(mSum) / static_cast<double>(mSize);
		RenewSmartQueue();
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
		mSize--;
		mQueueStack.front().pop();
		if (mQueueStack.front().empty())
		{
			mQueueStack.pop();
		}
		mAvg = static_cast<double>(mSum) / static_cast<double>(mSize);
		RenewSmartQueue();
		return tempVal;
	}

	template <typename T>
	T QueueStack<T>::GetMax() const
	{
		return mMax;
	}

	template <typename T>
	T QueueStack<T>::GetMin() const
	{
		return mMin;
	}

	template <typename T>
	double QueueStack<T>::GetAverage() const
	{
		return round(static_cast<double>(mAvg) * 1000.0) / 1000.0;
	}

	template <typename T>
	T QueueStack<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		return mSize;
	}

	template <typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mQueueStack.size();
	}

	template <typename T>
	void QueueStack<T>::RenewSmartQueue()
	{
		if (!mQueueStack.empty())
		{
			mMax = numeric_limits<T>::min();
			mMin = numeric_limits<T>::max();
			queue<stack<T> > tempQueueStack = mQueueStack;
			for (unsigned int i = 0; i < mQueueStack.size(); i++)
			{
				stack<T> tempStack = tempQueueStack.front();
				tempQueueStack.pop();
				for (unsigned int j = 0; j < tempStack.size(); j++)
				{
					T tempVal = tempStack.top();
					tempStack.pop();

					mMax = mMax > tempVal ? mMax : tempVal;
					mMin = mMin < tempVal ? mMin : tempVal;
				}
			}
		}
	}

}


