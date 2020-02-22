#pragma once
#include <queue>
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
		SmartQueue& operator=(const SmartQueue& rhs);
		~SmartQueue();
		void Enqueue(const T &number);
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
		void RenewSmartQueue();
		queue<T> mQueue;
		T mMax;
		T mMin;
		T mSum;
		T mAvg;
		double mVariance;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue() :
		mMax(numeric_limits<T>::min()), mMin(numeric_limits<T>::max()),
		mSum(0), mAvg(0), mVariance(0.0)
	{

	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other) :
		mMax(other.mMax), mMin(other.mMin), mSum(other.mSum), mAvg(other.mAvg), mVariance(other.mVariance)
	{
	}

	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue& rhs)
	{
		if (this != &rhs)
		{
			mQueue = rhs.mQueue;
			mMax = rhs.mMax;
			mMin = rhs.mMin;
			mSum = rhs.mSum;
			mAvg = rhs.mAvg;
			mVariance = rhs.mVariance;
		}
		return *this;
	}

	template <typename T>
	SmartQueue<T>::~SmartQueue()
	{
		mMax = NULL;
		mMin = NULL;
		mSum = NULL;
		mAvg = NULL;
		mVariance = NULL;
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(const T& number)
	{
		mQueue.push(number);
		mSum += number;
		mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
		RenewSmartQueue();
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
		mQueue.pop();
		mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
		RenewSmartQueue();
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
		return round(static_cast<double>(mAvg) * 1000.0) / 1000.0;
	}

	template <typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance() const
	{
		return round(static_cast<double>(mVariance) * 1000.0) / 1000.0;
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		return round(sqrt(static_cast<double>(mVariance)) * 1000.0) / 1000.0;
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mQueue.size();
	}

	template <typename T>
	void SmartQueue<T>::RenewSmartQueue()
	{
		if (!mQueue.empty())
		{
			queue<T> tempQueue = mQueue;

			mMax = numeric_limits<T>::min();
			mMin = numeric_limits<T>::max();
			T forVarianceSum = 0;

			while (!tempQueue.empty())
			{
				T tempVal = tempQueue.front();
				tempQueue.pop();

				mMax = mMax > tempVal ? mMax : tempVal;
				mMin = mMin < tempVal ? mMin : tempVal;
				forVarianceSum += pow((tempVal - mAvg), 2);	//편차 제곱의 평균
			}
			mVariance = static_cast<double>(forVarianceSum) / static_cast<double>(mQueue.size());
		}
	}

}

