#include "Boat.h"
#include <cmath>

namespace assignment2
{
	std::string Boat::mKind = "Boat";
	
	Boat::Boat(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		
	}

	Boat::Boat() : Vehicle(100)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed() const
	{
		double sailSpeed = 800.0 - (1.7 * static_cast<double>(GetPassengersCount()));
		sailSpeed = sailSpeed > 20.0 ? sailSpeed : 20.0;
		
		return static_cast<unsigned int>(sailSpeed);
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(5);
		return bp;
	}

	std::string Boat::GetKind() const
	{
		return mKind;
	}
}
