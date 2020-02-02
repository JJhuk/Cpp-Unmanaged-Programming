#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) : mSize(0), mMaxPassengersCount(maxPassengersCount)
	{
		for(unsigned int i=0; i< mMaxPassengersCount;i++)
		{
			mPassenger[i] = nullptr;
		}
	}

	Vehicle::Vehicle() : mSize(0), mMaxPassengersCount(100)
	{
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassenger[i] = nullptr;
		}
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
			const Person* temp[100];
			for(unsigned int j = 0; j<i;j++)
			{
				
			}
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

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		return mPassenger[i];
	}
}
