#include "SmartStack.h"
#include <limits>
#include <cmath>

using namespace assignment3;

template <typename T>
SmartStack<T>::SmartStack() :
	mMax(std::numeric_limits<T>::min()), mMin(std::numeric_limits<T>::max()),
	mVariance(NULL), mAvg(NULL)
{

}

template <typename T>
SmartStack<T>::~SmartStack()
{
}

template <typename T>
SmartStack<T>::SmartStack(const SmartStack& other)
{
	mStack = other.mStack;
	mMax = other.mMax;
	mMin = other.mMin;
	mVariance = other.mVariance;
}

template <typename T>
void SmartStack<T>::Push(const T& val)
{
	mStack.push(val);
	mSum += val;
	mAvg = static_cast<double>(mSum) / static_cast<double>(mStack.size());
	RenewSmartStack();
}

template <typename T>
T SmartStack<T>::Pop()
{
	T tempVal = mStack.top();
	mSum -= tempVal;
	mStack.pop();
	mAvg = static_cast<double>(mSum) / static_cast<double>(mStack.size());
	RenewSmartStack();
	return tempVal;
}

template <typename T>
T SmartStack<T>::Peek() const
{
	return mStack.top();
}

template <typename T>
T SmartStack<T>::GetMax() const
{
	return mMax;
}

template <typename T>
T SmartStack<T>::GetMin() const
{
	return mMin;
}

template <typename T>
double SmartStack<T>::GetAverage() const
{
	return round(static_cast<double>(mAvg) * 1000.0) / 1000.0;
}

template <typename T>
T SmartStack<T>::GetSum() const
{
	return mSum;
}

template <typename T>
double SmartStack<T>::GetVariance() const
{
	return round(static_cast<double>(mVariance) * 1000.0) / 1000.0;
}

template <typename T>
double SmartStack<T>::GetStandardDeviation() const
{
	return round(sqrt(static_cast<double>(mVariance)) * 1000.0) / 1000.0;
}

template <typename T>
unsigned SmartStack<T>::GetCount() const
{
	return mStack.size();
}

template <typename T>
SmartStack<T>& SmartStack<T>::operator=(const SmartStack& rhs)
{
	if (this != &rhs)
	{
		mStack = rhs.mStack;
		mMax = rhs.mMax;
		mMin = rhs.mMin;
		mSum = rhs.mSum;
		mAvg = rhs.mAvg;
		mVariance = rhs.mVariance;
	}
	return *this;
}


template <typename T>
//호출하기 전, 합 평균은 구했다고 가정
bool SmartStack<T>::RenewSmartStack()
{
	if (!mStack.empty())
	{
		stack<T> tempStack = mStack;

		mMax = numeric_limits<T>::min();
		mMin = numeric_limits<T>::max();
		T forVarianceSum = 0;

		while (!tempStack.empty())
		{
			T tempVal = tempStack.top();
			tempStack.pop();

			mMax = mMax > tempVal ? mMax : tempVal;
			mMin = mMin < tempVal ? mMin : tempVal;
			forVarianceSum += pow((tempVal - mAvg), 2);	//편차 제곱의 평균
		}
		mVariance = static_cast<double>(forVarianceSum) / static_cast<double>(mStack.size());
		return true;
	}
	return false;
}
