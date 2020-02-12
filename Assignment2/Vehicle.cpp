#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) : mSize(0)
	{
		mHowMoveCount = 0;
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
		mHowMoveCount = 0;
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassenger[i] = nullptr;
		}
	}

	Vehicle::Vehicle(const Vehicle& other)
	{
		mHowMoveCount = 0;
		if (&other != nullptr)
		{
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
			mCanMoveCount = other.mCanMoveCount;
			mRestCount = other.mRestCount;
			mHowMoveCount = other.mHowMoveCount;
		}
		else
		{
			mMaxPassengersCount = 100;
			mSize = 0;
			for (int i = 0; i < mMaxPassengersCount; i++)
			{
				mPassenger[i] = nullptr;
			}
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
			mCanMoveCount = other.mCanMoveCount;
			mRestCount = other.mRestCount;
			mHowMoveCount = other.mHowMoveCount;
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

	unsigned int Vehicle::GetRestCount() const
	{
		return mRestCount;
	}

	unsigned int Vehicle::GetCanMoveCount() const
	{
		return mCanMoveCount;
	}

	unsigned int Vehicle::GetHowMoveCount() const
	{
		return mHowMoveCount;
	}

	void Vehicle::SetRestCount(unsigned int restCount)
	{
		mRestCount = restCount;
	}

	void Vehicle::SetCanMoveCount(unsigned int canMoveCount)
	{
		mCanMoveCount = canMoveCount;
	}

	const Person* Vehicle::MovePassenger(unsigned int idx)
	{
		if(idx >= 0 && idx < mSize)
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
		if(i>=0 && i<mSize)
		{
			return mPassenger[i];
		}
		else
		{
			return nullptr;
		}
	}
}
