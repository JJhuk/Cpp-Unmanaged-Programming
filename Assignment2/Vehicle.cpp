#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) : mSize(0)
	{
		mNowMoveCount = 0;
		mNowRestCount = 0;
		mTotalMoveCount = 0;
		if (maxPassengersCount >= 0 && maxPassengersCount <= 100)
		{
			mMaxPassengersCount = maxPassengersCount;
		}
		else
		{
			mMaxPassengersCount = 100;
		}
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassenger[i] = nullptr;
		}
	}

	Vehicle::Vehicle() : mSize(0), mMaxPassengersCount(100)
	{
		mNowMoveCount = 0;
		mNowRestCount = 0;
		mTotalMoveCount = 0;
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassenger[i] = nullptr;
		}
	}

	Vehicle::Vehicle(const Vehicle& other)
	{
		if (&other != nullptr)
		{
			mNowMoveCount = 0;
			mNowRestCount = 0;
			mTotalMoveCount = 0;
			mMaxPassengersCount = other.mMaxPassengersCount;

			for (unsigned int i = 0; i < mMaxPassengersCount; i++)
			{
				mPassenger[i] = nullptr;
			}
			mSize = other.mSize;

			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassenger[i] = new Person(*other.mPassenger[i]);
			}
		}
		else
		{
			mMaxPassengersCount = 100;
			mSize = 0;
			for (int i = 0; i < mMaxPassengersCount; i++)
			{
				mPassenger[i] = nullptr;
			}

			mNowMoveCount = other.mNowMoveCount;
			mNowRestCount = other.mNowRestCount;
			mMaxMoveCount = other.mMaxMoveCount;
			mTotalMoveCount = other.mTotalMoveCount;
			mMustRestCount = other.mMustRestCount;
		}

	}

	Vehicle& Vehicle::operator=(const Vehicle& other) {
		if (&other != &(*this))
		{
			mMaxPassengersCount = other.mMaxPassengersCount;

			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassenger[i] = nullptr;
			}
			mSize = other.mSize;

			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassenger[i] = new Person(*other.mPassenger[i]);
			}

			mNowMoveCount = other.mNowMoveCount;
			mNowRestCount = other.mNowRestCount;
			mMaxMoveCount = other.mMaxMoveCount;
			mTotalMoveCount = other.mTotalMoveCount;
			mMustRestCount = other.mMustRestCount;
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			delete mPassenger[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mSize < mMaxPassengersCount)
		{
			mPassenger[mSize] = person;
			mSize++;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= 0 && i < mSize)
		{
			const Person* temp[100] = { nullptr };
			for (unsigned int beforeRemoveIndex = 0; beforeRemoveIndex < i; beforeRemoveIndex++)
			{
				temp[beforeRemoveIndex] = mPassenger[beforeRemoveIndex];
			}
			delete mPassenger[i];
			for (unsigned int afterRemoveIndex = i + 1; afterRemoveIndex < mSize; afterRemoveIndex++)
			{
				temp[afterRemoveIndex - 1] = mPassenger[afterRemoveIndex];
			}
			mSize -= 1;
			for (unsigned int fillNullptr = 0; i < mMaxPassengersCount; fillNullptr++)
			{
				mPassenger[fillNullptr] = nullptr;
			}
			memcpy(mPassenger, temp, sizeof(mPassenger));
			return true;
		}
		else
		{
			return false;
		}
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mSize;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned Vehicle::GetTotalMoveCount() const
	{
		return mTotalMoveCount;
	}

	void Vehicle::InitTravel(unsigned maxMoveCount, unsigned mustRestCount)
	{
		setMaxMoveCount(maxMoveCount);
		setMustRestCount(mustRestCount);
	}

	void Vehicle::setMustRestCount(unsigned int mustRestCount)
	{
		mMustRestCount = mustRestCount;
	}

	void Vehicle::setMaxMoveCount(unsigned int maxMoveCount)
	{
		mMaxMoveCount = maxMoveCount;
	}

	void Vehicle::TravelVehicle()
	{
		if (mNowMoveCount < mMaxMoveCount)	//그냥 이동할 수 있을때
		{
			mTotalMoveCount++;	//얼마나 이동 한지 올리고
			mNowMoveCount++;	//현재 몇번 이동한지 체크
		}
		else if (mNowMoveCount == mMustRestCount)	//최대 이동했을 때 (쉬어야 함)
		{
			if (mNowRestCount < mMustRestCount) //아직 덜 쉬었을 때
			{
				mNowRestCount++;	//카운트 올림
			}
			else if (mNowRestCount == mMustRestCount) //다 쉬었을때
			{
				mNowRestCount = 0;
				mNowMoveCount = 0;
			}
		}

	}


	const Person* Vehicle::MovePassenger(unsigned int idx)
	{
		if (idx >= 0 && idx < mSize)
		{
			mSize--;

			const Person* temp = mPassenger[idx];
			mPassenger[idx] = nullptr;
			return temp;
		}
		else
		{
			return nullptr;
		}
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= 0 && i < mSize)
		{
			return mPassenger[i];
		}
		else
		{
			return nullptr;
		}
	}
}
