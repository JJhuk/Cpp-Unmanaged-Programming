#include "Sedan.h"

namespace assignment2
{

	Sedan::Sedan() : Vehicle(4)
	{
		mbIsConnectedTrailer = false;
		mTrailer = nullptr;
		InitTravel(5, 1);
	}

	Sedan::~Sedan()
	{
		if (mbIsConnectedTrailer)
		{
			delete mTrailer;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int passengerTotalWeight = GetTotalPassengerWeight();

		if (mbIsConnectedTrailer)
		{
			passengerTotalWeight += mTrailer->GetWeight();
		}
		if (passengerTotalWeight <= 80)
		{
			return 480;
		}
		if (80 < passengerTotalWeight && passengerTotalWeight <= 160)
		{
			return 458;
		}
		if (160 < passengerTotalWeight && passengerTotalWeight <= 260)
		{
			return 400;
		}
		if (260 < passengerTotalWeight && passengerTotalWeight <= 350)
		{
			return 380;
		}
		if (passengerTotalWeight > 350)
		{
			return 300;
		}
		return 0;
	}


	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mbIsConnectedTrailer)
		{
			return false;
		}
		InitTravel(5, 2);
		mbIsConnectedTrailer = true;
		mTrailer = trailer;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mbIsConnectedTrailer)
		{
			mbIsConnectedTrailer = false;
			delete mTrailer;
			mTrailer = nullptr;
			return true;
		}
		return false;
	}

	bool Sedan::GetIsConnectedTrailer() const
	{
		return mbIsConnectedTrailer;
	}
}
