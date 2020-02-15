#include "Boatplane.h"
#include <cmath>
#include <string>

namespace assignment2
{
	std::string Boatplane::mKind = "Boatplane";

	Boatplane::Boatplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		InitTravel(1, 3);
	}

	Boatplane::~Boatplane()
	{
	}

	std::string Boatplane::GetKind() const
	{
		return mKind;
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return GetSailSpeed() > GetFlySpeed() ? GetSailSpeed() : GetFlySpeed();
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double passengerCount = static_cast<double>(GetPassengersCount());
		double sailSpeed = 150 * exp((-passengerCount + 500.0) / 300.0);

		return static_cast<unsigned int>(sailSpeed);
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double passengerCount = static_cast<double>(GetPassengersCount());
		double flySpeed = (800.0 - (1.7 * passengerCount));

		flySpeed = flySpeed > 20.0 ? flySpeed : 20.0;

		return static_cast<unsigned int>(flySpeed);
	}
}
