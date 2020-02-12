#include "Boatplane.h"

namespace assignment2
{
	std::string Boatplane::mKind = "Boatplane";
	
	Boatplane::Boatplane(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	std::string Boatplane::GetKind() const
	{
		return mKind;
	}

	unsigned Boatplane::GetMaxSpeed() const
	{
	}

	unsigned Boatplane::GetSailSpeed() const
	{
	}

	unsigned Boatplane::GetFlySpeed() const
	{
	}
}
