#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Vehicle.h"
#include <cmath>

namespace assignment2
{

	Airplane::Airplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		InitTravel(1, 3);
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
		double flySpeed = 200.0 * exp((-static_cast<double>(GetTotalPassengerWeight()) + 800.0) / 500.0);
		return static_cast<unsigned int>(round(flySpeed));
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double driveSpeed = 4.0 * exp((-static_cast<double>(GetTotalPassengerWeight()) + 400.0) / 70.0);
		return static_cast<unsigned int>(round(driveSpeed));
	}

	//to do define
	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());
		for (unsigned int i = 0; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		Deinitializer();
		for (unsigned int i = 0; i < boat.GetPassengersCount(); i++)
		{
			bp.AddPassenger(boat.GetPassenger(i));
		}
		boat.Deinitializer();
		return(bp);
	}

}
