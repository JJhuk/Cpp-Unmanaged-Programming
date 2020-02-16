#include "Boatplane.h"
#include <cmath>
#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		InitTravel(1, 3);
	}

	Boatplane::Boatplane(Boatplane& other) : Vehicle(other)
	{
		InitTravel(1, 3);
	}

	Boatplane::Boatplane(Boat& lhs, Airplane& rhs) : Vehicle(lhs.GetMaxPassengersCount() + rhs.GetMaxPassengersCount())
	{
		for (unsigned int i = 0; i < rhs.GetPassengersCount(); i++)
		{
			this->AddPassenger(rhs.MovePassenger(i));
		}
		rhs.Deinitializer();
		for (unsigned int i = 0; i < lhs.GetPassengersCount(); i++)
		{
			this->AddPassenger(lhs.MovePassenger(i));
		}
		lhs.Deinitializer();
	}

	Boatplane::Boatplane(Airplane& rhs, Boat& lhs) : Vehicle(lhs.GetMaxPassengersCount() + rhs.GetMaxPassengersCount())
	{
		for (unsigned int i = 0; i < rhs.GetPassengersCount(); i++)
		{
			this->AddPassenger(rhs.MovePassenger(i));
		}
		rhs.Deinitializer();
		for (unsigned int i = 0; i < lhs.GetPassengersCount(); i++)
		{
			this->AddPassenger(lhs.MovePassenger(i));
		}
		lhs.Deinitializer();
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
