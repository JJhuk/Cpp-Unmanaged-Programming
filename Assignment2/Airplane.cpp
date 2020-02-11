#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		return GetFlySpeed() > GetDriveSpeed() ? GetFlySpeed() : GetDriveSpeed();
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		double flySpeed = 200.0 * exp((-static_cast<double>(GetPassengersCount()) + 800.0) / 500.0);
		return static_cast<unsigned int>(flySpeed);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double driveSpeed = 4.0 * exp((-static_cast<double>(GetPassengersCount()) + 400.0) / 70.0);
		return static_cast<unsigned int>(driveSpeed);
	}

	//to do define
	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(this->GetMaxPassengersCount() + boat->GetMaxPassengersCount());
		return bp;
	}
}
