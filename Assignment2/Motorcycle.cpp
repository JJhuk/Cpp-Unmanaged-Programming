#include "Motorcycle.h"
#include <cmath>
#include <string>

namespace assignment2
{
	Motorcycle::Motorcycle() : Vehicle(2)
	{
		InitTravel(5, 1);
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double driveSpeed = (-(pow(passengerTotalWeight, 3) + (2 * passengerTotalWeight) + 400));
		driveSpeed = driveSpeed > 0.0 ? driveSpeed : 0.0;

		return static_cast<unsigned int>(round(driveSpeed));
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

}
