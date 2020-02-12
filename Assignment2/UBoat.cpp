#include "UBoat.h"
#include <cmath>

namespace assignment2
{
	std::string UBoat::mKind = "UBoat";
	
	UBoat::UBoat() : Vehicle(50)
	{
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
		double passengersCount = static_cast<double>(GetPassengersCount());
		double sailSpeed = (500.0 - (passengersCount / 10.0));
		sailSpeed = sailSpeed > 200.0 ? sailSpeed : 200.0;

		return static_cast<unsigned int>(sailSpeed);
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double passengersCount = static_cast<double>(GetPassengersCount());
		double diveSpeed = 500 * log((passengersCount + 150.0) / 150.0) + 30.0;

		return static_cast<unsigned int>(diveSpeed);
	}

	std::string UBoat::GetKind() const
	{
		return mKind;
	}
}
