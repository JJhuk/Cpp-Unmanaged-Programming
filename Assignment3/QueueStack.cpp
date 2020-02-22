#include "QueueStack.h"
#include <limits>

using namespace std;
using namespace assignment3;

template <typename T>
QueueStack<T>::QueueStack() : mMaxStackSize(NULL), mNowQueueIndex(0),
mMax(numeric_limits<T>::min()), mMin(numeric_limits<T>::max()),
mSum(0), mAvg(0), mVariance(0)
{
}

template <typename T>
QueueStack<T>::QueueStack(unsigned maxStackSize) : mMaxStackSize(maxStackSize), mNowQueueIndex(0),
mMax(numeric_limits<T>::min()), mMin(numeric_limits<T>::max()),
mSum(0), mAvg(0), mVariance(0)
{
}

template <typename T>
QueueStack<T>::QueueStack(const QueueStack& other) : mMaxStackSize(other.mMaxStackSize),
mMax(other.mMax), mMin(other.mMin), mNowQueueIndex(other.mNowQueueIndex),
mSum(other.mSum), mAvg(other.mAvg), mVariance(other.mVariance)
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
		mNowQueueIndex = rhs.mNowQueueIndex;
		mMax = rhs.mMax;
		mSum = rhs.mSum;
		mAvg = rhs.mAvg;
		mVariance = rhs.mVariance;
	}
	return *this;
}

template <typename T>
void QueueStack<T>::Enqueue(const T& number)
{

}

template <typename T>
T QueueStack<T>::Peek() const
{
}

template <typename T>
T QueueStack<T>::Dequeue()
{
}

template <typename T>
T QueueStack<T>::GetMax() const
{
}

template <typename T>
T QueueStack<T>::GetMin() const
{
}

template <typename T>
double QueueStack<T>::GetAverage() const
{
}

template <typename T>
T QueueStack<T>::GetSum() const
{
}

template <typename T>
unsigned QueueStack<T>::GetCount() const
{
}

template <typename T>
unsigned QueueStack<T>::GetStackCount() const
{
}

template <typename T>
void QueueStack<T>::RenewSmartQueue()
{
}
