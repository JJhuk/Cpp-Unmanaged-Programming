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
		T GetMax();
		T GetMin();
		double GetAverage() const; //소수 네번째 자리 반환해야 함
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;

	private:
		queue<T> mQueue;
		T mSum;
		double mMulNumSum;
		double mAvg;
		double mMulNumAvg;
		double mVariance;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue() :
		mSum(0), mMulNumSum(0), mAvg(0.0), mMulNumAvg(0.0), mVariance(0.0)
	{
	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other) : mQueue(other.mQueue),
		mSum(other.mSum), mMulNumSum(other.mMulNumSum),
		mAvg(other.mAvg), mMulNumAvg(other.mMulNumAvg), mVariance(other.mVariance)
	{
	}

	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& rhs)
	{
		if (this != &rhs)
		{
			mQueue = rhs.mQueue;
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
		mMulNumSum += static_cast<double>(number) * static_cast<double>(number);
		mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
		mMulNumAvg = mMulNumSum / static_cast<double>(mQueue.size());
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
		mMulNumSum -= static_cast<double>(tempVal) * static_cast<double>(tempVal);
		mQueue.pop();

		if (!mQueue.empty())
		{
			mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
			mMulNumAvg = mMulNumSum / static_cast<double>(mQueue.size());
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
	T SmartQueue<T>::GetMax()
	{
		T mMax = numeric_limits<T>::max();
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			mMax = mMax < mQueue.front() ? mQueue.front() : mMax;
			mQueue.push(mQueue.front());
			mQueue.pop();
		}
		return mMax;
	}

	template <typename T>
	T SmartQueue<T>::GetMin()
	{
		T mMin = numeric_limits<T>::max();
		for (size_t i = 0; i < mQueue.size(); i++)
		{
			mMin = mMin > mQueue.front() ? mQueue.front() : mMin;
			mQueue.push(mQueue.front());
			mQueue.pop();
		}
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

