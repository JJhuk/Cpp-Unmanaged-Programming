#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan() : Vehicle(4)
	{
		mbIsConnectedTrailer = false;
		mTrailer = nullptr;
	}

	Sedan::~Sedan()
	{
		if(mbIsConnectedTrailer)
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
		unsigned int passengersCount = GetPassengersCount();

		if(mbIsConnectedTrailer)
		{
			passengersCount += mTrailer->GetWeight();
		}

		if(passengersCount <= 80)
		{
			return 480;
		}
		else if(passengersCount > 80)
		{
			return 458;
		}
		else if(passengersCount > 160)
		{
			return 400;
		}
		else if(passengersCount > 260)
		{
			return 380;
		}
		else if(passengersCount > 350)
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
	}

	bool Sedan::RemoveTrailer()
	{
		if(mbIsConnectedTrailer)
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
}