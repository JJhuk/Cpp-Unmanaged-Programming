#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		InitTravel(1, 3);
	}

	Boatplane::Boatplane(Boatplane& other) : Vehicle(other.GetMaxPassengersCount())
	{
		InitTravel(1, 3);
		unsigned int passengersCount = other.GetPassengersCount();
		for (unsigned int i = 0; i < passengersCount; i++)
		{
			AddPassenger(other.GetPassenger(i));
		}
		other.Deinitializer();
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
