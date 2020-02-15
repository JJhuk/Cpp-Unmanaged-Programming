#include "Boat.h"
#include "Airplane.h"
#include <cmath>

namespace assignment2
{

	Boat::Boat(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		InitTravel(2, 1);
	}

	Boat::Boat() : Vehicle(100)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed() const
	{
		double sailSpeed = 800.0 - (1.7 * static_cast<double>(GetTotalPassengerWeight()));
		sailSpeed = sailSpeed > 20.0 ? sailSpeed : 20.0;

		return static_cast<unsigned int>(round(sailSpeed));
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		for (unsigned int i = 0; i < plane.GetPassengersCount(); i++)
		{
			bp.AddPassenger(plane.GetPassenger(i));
		}
		plane.Deinitializer();
		for (unsigned int i = 0; i < GetPassengersCount(); i++)
		{
			bp.AddPassenger(GetPassenger(i));
		}
		Deinitializer();
		return(bp);
	}

}
