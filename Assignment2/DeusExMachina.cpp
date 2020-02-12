#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		if(mInstance == nullptr)
		{
			mInstance = new DeusExMachina();
		}

		return mInstance;
	}

	void DeusExMachina::Travel() const
	{
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if(mSize < mMaxIdx)
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
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		return NULL;
	}

	DeusExMachina::~DeusExMachina()
	{
		for(unsigned int i=0; i<mSize; i++)
		{
			delete mVehicles[i];
		}
	}

	DeusExMachina::DeusExMachina() : mMaxIdx(10)
	{
		for(unsigned int i=0; i<mMaxIdx;i++)
		{
			mVehicles[i] = nullptr;
		}
		mSize = 0;
	}

}
