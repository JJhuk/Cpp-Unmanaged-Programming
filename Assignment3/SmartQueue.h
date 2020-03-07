#pragma once
#include <queue>
#include <stack>
#include <limits>

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other);
		SmartQueue& operator=(const SmartQueue<T>& rhs);
		~SmartQueue();
		void Enqueue(const T& number);
		T Peek() const;
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const; //소수 네번째 자리 반환해야 함
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;

	private:
		queue<T> mQueue;
		stack<T> mMax;
		stack<T> mMin;
		T mSum;
		T mMulNumSum;
		double mAvg;
		double mMulNumAvg;
		double mVariance;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue() :
		mSum(0), mMulNumSum(0), mAvg(0.0), mMulNumAvg(0.0), mVariance(0.0)
	{
		mMax.push(numeric_limits<T>::min());
		mMin.push(numeric_limits<T>::max());
	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other) : mQueue(other.mQueue),
		mMax(other.mMax), mMin(other.mMin), mSum(other.mSum), mMulNumSum(other.mMulNumSum),
		mAvg(other.mAvg), mMulNumAvg(other.mMulNumAvg), mVariance(other.mVariance)
	{
	}

	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& rhs)
	{
		if (this != &rhs)
		{
			mQueue = rhs.mQueue;
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
	SmartQueue<T>::~SmartQueue()
	{
		mSum = NULL;
		mMulNumSum = NULL;
		mAvg = NULL;
		mMulNumAvg = NULL;
		mVariance = NULL;
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(const T& number)
	{
		mQueue.push(number);
		mSum += number;
		mMulNumSum += number * number;
		mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
		mMulNumAvg = static_cast<double>(mMulNumSum) / static_cast<double>(mQueue.size());

		if (mMin.top() >= number)	//중복 값이 있을 수 있기 때문
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
	T SmartQueue<T>::Peek() const
	{
		return mQueue.front();
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		T tempVal = mQueue.front();
		mSum -= tempVal;
		mMulNumSum -= tempVal * tempVal;
		mQueue.pop();

		if (mMin.top() == tempVal)
		{
			mMin.pop();
		}
		if (mMax.top() == tempVal)
		{
			mMax.pop();
		}

		if (!mQueue.empty())
		{
			mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
			mMulNumAvg = static_cast<double>(mMulNumSum) / static_cast<double>(mQueue.size());
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
	T SmartQueue<T>::GetMax() const
	{
		return mMax;
	}

	template <typename T>
	T SmartQueue<T>::GetMin() const
	{
		return mMin;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage() const
	{
		return round(mAvg * 1000.0) / 1000.0;
	}

	template <typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance() const
	{
		return round(mVariance * 1000.0) / 1000.0;
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		if (mVariance != 0)
		{
			return round(sqrt(mVariance) * 1000.0) / 1000.0;
		}
		return 0;
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mQueue.size();
	}
}

