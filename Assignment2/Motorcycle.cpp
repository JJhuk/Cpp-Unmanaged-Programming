#include "Motorcycle.h"
#include <cmath>
#include <string>

namespace assignment2
{
	std::string Motorcycle::mKind = "Motorcycle";

	Motorcycle::Motorcycle() : Vehicle(2)
	{
		InitTravel(5, 1);
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double passengersCount = static_cast<double>(GetPassengersCount());
		double driveSpeed = (-(pow(passengersCount, 3) + (2 * passengersCount) + 400));
		driveSpeed = driveSpeed > 0.0 ? driveSpeed : 0.0;

		return static_cast<unsigned int>(driveSpeed);
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	std::string Motorcycle::GetKind() const
	{
		return mKind;
	}
}
