#pragma once
#include <stack>
#include <limits>
#include <cmath>
using namespace  std;
namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();

		~SmartStack();
		SmartStack(const SmartStack& other);

		void Push(const T& number);	//Pop과 push에서 값을 다시 갱신해줌
		T Pop();
		T Peek() const;
		T GetMax() const;	//시간복잡도가 O(1)이어야 함.
		T GetMin() const;
		double GetAverage() const;	//4번째 자리 반올림.
		T GetSum() const;
		double GetVariance() const;	//시간복잡도가 O(1)이어야 함. 
		double GetStandardDeviation() const;	//시간복잡도가 O(1)이어야 함.
		unsigned int GetCount() const;


		SmartStack& operator=(const SmartStack<T>& rhs);

	private:
		stack<T> mStack;
		stack<T> mMax;
		stack<T> mMin;
		T mSum;
		double mMulNumSum;
		double mAvg;
		double mMulNumAvg;	//E(X^2) - E(X)^2 = V(X)
		double mVariance;

	};
	template <typename T>
	SmartStack<T>::SmartStack() :
		mSum(0), mMulNumSum(0), mAvg(0.0), mMulNumAvg(0.0), mVariance(0.0)
	{
		mMax.push(std::numeric_limits<T>::lowest());
		mMin.push(std::numeric_limits<T>::max());
	}

	template <typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& rhs)
	{
		if (this != &rhs)
		{
			mStack = rhs.mStack;
			mMax = rhs.mMax;
			mMin = rhs.mMin;
			mSum = rhs.mSum;
			mMulNumSum = rhs.mMulNumSum;
			mAvg = rhs.mAvg;
			mMulNumAvg = rhs.mMulNumAvg;
			mVariance = rhs.mVariance;
		}
		return *this;
	}

	template <typename T>
	SmartStack<T>::~SmartStack()
	{
		mSum = NULL;
		mMulNumSum = NULL;
		mAvg = NULL;
		mMulNumAvg = NULL;
		mVariance = NULL;
	}

	template <typename T>
	SmartStack<T>::SmartStack(const SmartStack& other) : mStack(other.mStack),
		mMax(other.mMax), mMin(other.mMin), mSum(other.mSum), mMulNumSum(other.mMulNumSum),
		mAvg(other.mAvg), mMulNumAvg(other.mMulNumAvg), mVariance(other.mVariance)
	{
	}

	template <typename T>
	void SmartStack<T>::Push(const T& number)
	{
		mStack.push(number);
		mSum += number;
		mMulNumSum += static_cast<double>(number) * static_cast<double>(number);
		mAvg = static_cast<double>(mSum) / static_cast<double>(mStack.size());
		mMulNumAvg = mMulNumSum / static_cast<double>(mStack.size());

		2 >= number)	//중복 값이 있을 수 있기 때문
		{
			mMin.push(number);
		}
		if (mMax.top() <= number)
		{
			mMax.push(number);
		}
		mVariance = mMulNumAvg - (mAvg * mAvg);
	}

	template <typename T>
	T SmartStack<T>::Pop()
	{
		T tempVal = mStack.top();
		mSum -= tempVal;
		mMulNumSum -= static_cast<double>(tempVal) * static_cast<double>(tempVal);
		mStack.pop();

		if (mMin.top() == tempVal)
		{
			mMin.pop();
		}
		if (mMax.top() == tempVal)
		{
			mMax.pop();
		}

		if (!mStack.empty())
		{
			mAvg = static_cast<double>(mSum) / static_cast<double>(mStack.size());
			mMulNumAvg = mMulNumSum / static_cast<double>(mStack.size());
		}
		else
		{
			mAvg = 0;
			mMulNumAvg = 0;
		}
		mVariance = mMulNumAvg - (mAvg * mAvg);
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
		return mMax.top();
	}

	template <typename T>
	T SmartStack<T>::GetMin() const
	{
		return mMin.top();
	}

	template <typename T>
	double SmartStack<T>::GetAverage() const
	{
		return round(mAvg * 1000.0) / 1000.0;
	}

	template <typename T>
	T SmartStack<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	double SmartStack<T>::GetVariance() const
	{
		return round(mVariance * 1000.0) / 1000.0;
	}

	template <typename T>
	double SmartStack<T>::GetStandardDeviation() const
	{
		return round(sqrt(mVariance) * 1000.0) / 1000.0;
	}

	template <typename T>
	unsigned SmartStack<T>::GetCount() const
	{
		return mStack.size();
	}
}
