#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		InitTravel(1, 3);
	}

	Boatplane::Boatplane(Boatplane& boat_plane) : Vehicle(boat_plane.GetMaxPassengersCount())
	{
		InitTravel(1, 3);
		unsigned int passengersCount = boat_plane.GetPassengersCount();
		for (unsigned int i = 0; i < passengersCount; i++)
		{
			AddPassenger(boat_plane.MovePassenger(i));
		}
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return GetSailSpeed() > GetFlySpeed() ? GetSailSpeed() : GetFlySpeed();
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double sailSpeed = 150 * exp((-passengerTotalWeight + 500.0) / 300.0);

		return static_cast<unsigned int>(round(sailSpeed));
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double flySpeed = (800.0 - (1.7 * passengerTotalWeight));

		flySpeed = flySpeed > 20.0 ? flySpeed : 20.0;

		return static_cast<unsigned int>(round(flySpeed));
	}
}
