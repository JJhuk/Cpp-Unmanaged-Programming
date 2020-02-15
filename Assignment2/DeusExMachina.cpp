#include "DeusExMachina.h"
#include "Vehicle.h"
#include <string>

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new DeusExMachina();
		}
		return mInstance;
	}


	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			mVehicles[i]->TravelVehicle();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mSize < mMaxIdx)
		{
			mVehicles[mSize] = vehicle;
			mSize++;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= 0 && i < mSize)
		{
			Vehicle* tempVehicle[10];
			for (unsigned int beforeRemove = 0; beforeRemove < i; beforeRemove++)
			{
				tempVehicle[beforeRemove] = mVehicles[beforeRemove];
			}
			delete mVehicles[i];
			for (unsigned int afterRemove = i + 1; afterRemove < mSize; afterRemove++)
			{
				tempVehicle[afterRemove - 1] = mVehicles[afterRemove];
			}
			mSize--;
			memcpy(mVehicles, tempVehicle, sizeof(mVehicles));

			for (unsigned int i = 0; i < mMaxIdx; i++)
			{
				tempVehicle[i] = nullptr;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		const Vehicle* tempVehicle = nullptr;
		unsigned int furthest = 0;
		for (unsigned int i = 0; i < mSize; i++)
		{
			unsigned int checkFurthest = mVehicles[i]->GetMaxSpeed() * mVehicles[i]->GetTotalMoveCount();
			if (furthest < checkFurthest)
			{
				furthest = checkFurthest;
				tempVehicle = mVehicles[i];
			}
		}
		return tempVehicle;
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i) const
	{
		if(i>=0 && i<mSize)
		{
			return mVehicles[i];
		}
		return nullptr;
	}

	DeusExMachina::DeusExMachina() :mMaxIdx(10), mSize(0)
	{
		for (unsigned int i = 0; i < mMaxIdx; i++)
		{
			mVehicles[i] = nullptr;
		}
	}
}
