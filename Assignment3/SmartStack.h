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
		void renewSmartStack();
		stack<T> mStack;
		T mMax;
		T mMin;
		T mSum;
		double mAvg;
		double mVariance;

	};
	template <typename T>
	SmartStack<T>::SmartStack() :
		mMax(std::numeric_limits<T>::min()), mMin(std::numeric_limits<T>::max()),
		mSum(0), mAvg(0.0), mVariance(0.0)
	{

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
			mAvg = rhs.mAvg;
			mVariance = rhs.mVariance;
		}
		return *this;
	}

	template <typename T>
	SmartStack<T>::~SmartStack()
	{
		mMax = NULL;
		mMin = NULL;
		mSum = NULL;
		mAvg = NULL;
		mVariance = NULL;
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
	void SmartStack<T>::Push(const T& number)
	{
		mStack.push(number);
		mSum += number;
		mAvg = static_cast<double>(mSum) / static_cast<double>(mStack.size());
		renewSmartStack();
	}

	template <typename T>
	T SmartStack<T>::Pop()
	{
		T tempVal = mStack.top();
		mSum -= tempVal;
		mStack.pop();
		if (!mStack.empty())
		{
			mAvg = static_cast<double>(mSum) / static_cast<double>(mStack.size());
		}
		else
		{
			mAvg = 0;
		}
		renewSmartStack();
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
		if (mVariance != 0)
		{
			return round(sqrt(static_cast<double>(mVariance)) * 1000.0) / 1000.0;
		}
		return 0;
	}

	template <typename T>
	unsigned SmartStack<T>::GetCount() const
	{
		return mStack.size();
	}

	template <typename T>
	//호출하기 전, 합 평균은 구했다고 가정
	void SmartStack<T>::renewSmartStack()
	{
		mMax = numeric_limits<T>::min();
		mMin = numeric_limits<T>::max();
		if (!mStack.empty())
		{
			stack<T> tempStack = mStack;

			T forVarianceSum = 0;

			while (!tempStack.empty())
			{
				T tempVal = tempStack.top();
				tempStack.pop();

				mMax = mMax > tempVal ? mMax : tempVal;
				mMin = mMin < tempVal ? mMin : tempVal;
				forVarianceSum += (tempVal - static_cast<T>(mAvg)) * (tempVal - static_cast<T>(mAvg));
			}
			mVariance = static_cast<double>(forVarianceSum) / static_cast<double>(mStack.size());
		}
		else
		{
			mVariance = 0.0;
		}
	}


}
