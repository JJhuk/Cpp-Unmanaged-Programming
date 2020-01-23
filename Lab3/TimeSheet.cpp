#include "TimeSheet.h"
#include <string>
#include <cmath>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) : mName(name), mMaxSize(maxEntries), mCount(0)
	{
		mHour = new int[maxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& other) : mName(other.mName), mMaxSize(other.mMaxSize), mCount(0)
	{
		mHour = new int[mMaxSize];
		for (unsigned int i = 0; i < mMaxSize; i++)
		{
			mHour[i] = other.mHour[i];
		}
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mHour;
		mMaxSize = 0;
		mCount = 0;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours > 0 && timeInHours <= 10)
		{
			if ((mCount + 1) >= mMaxSize)	//새로 할당을 해야 함.
			{
				int* tempPtr = mHour;
				mHour = nullptr;
				mMaxSize *= 2;
				mHour = new int[mMaxSize];
				for (unsigned int i = 0; i < mCount; i++)
				{
					mHour[i] = tempPtr[i];
				}			
				delete[] tempPtr;
				tempPtr = nullptr;
			}
			mHour[mCount++] = timeInHours;	//추가
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= 0 && index < mCount)
		{
			return mHour[index];
		}
		else
		{
			return -1;
		}
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		for (unsigned int i = 0; i < mCount; i++)
		{
			sum += mHour[i];
		}
		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (mCount > 0)
		{
			return GetTotalTime() / static_cast<float>(mCount);
		}
		else
		{
			return 0.0f;
		}
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float avg = GetAverageTime();
		if (avg != 0.0f)
		{
			float deviation = 0.0f;

			for (unsigned int i = 0; i < mCount; i++)
			{
				deviation += powf((avg - mHour[i]), 2);
			}
			return sqrt(deviation / float(mCount));
		}
		else
		{
			return 0.0f;
		}
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{

		if (rhs.mHour != nullptr)
		{
			if (mHour != nullptr)
			{
				delete[] mHour;
			}
			mMaxSize = rhs.mMaxSize;
			mName = rhs.mName;
			mCount = rhs.mCount;
			mHour = new int[mMaxSize];

			for (unsigned int i = 0; i < mCount; i++)
			{
				mHour[i] = rhs.mHour[i];
			}
		}

		return *this;
	}
}
