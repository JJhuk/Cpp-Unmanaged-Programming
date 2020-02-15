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
		else if (passengerTotalWeight > 80)
		{
			return 458;
		}
		else if (passengerTotalWeight > 160)
		{
			return 400;
		}
		else if (passengerTotalWeight > 260)
		{
			return 380;
		}
		else if (passengerTotalWeight > 350)
		{
			return 300;
		}
	}


	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mbIsConnectedTrailer)
		{
			return false;
		}
		else
		{
			mbIsConnectedTrailer = true;
			mTrailer = trailer;

		}
		InitTravel(5, 2);
	}

	bool Sedan::RemoveTrailer()
	{
		if (mbIsConnectedTrailer)
		{
			mbIsConnectedTrailer = false;
			delete mTrailer;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Sedan::GetIsConnectedTrailer() const
	{
		return mbIsConnectedTrailer;
	}
}
