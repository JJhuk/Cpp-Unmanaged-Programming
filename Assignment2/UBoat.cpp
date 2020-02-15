#include "UBoat.h"
#include <cmath>

namespace assignment2
{

	UBoat::UBoat() : Vehicle(50)
	{
		InitTravel(2, 4);
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return GetSailSpeed() > GetDiveSpeed() ? GetSailSpeed() : GetDiveSpeed();
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double sailSpeed = (500.0 - (passengerTotalWeight / 10.0));
		sailSpeed = sailSpeed > 200.0 ? sailSpeed : 200.0;

		return static_cast<unsigned int>(round(sailSpeed));
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double diveSpeed = 500 * log((passengerTotalWeight + 150.0) / 150.0) + 30.0;

		return static_cast<unsigned int>(round(diveSpeed));
	}

}
