#include "Boat.h"
#include "Airplane.h"
#include <cmath>
#include <string>

namespace assignment2
{
	std::string Boat::mKind = "Boat";
	
	Boat::Boat(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		SetCanMoveCount(2);
		SetRestCount(3);
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
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		unsigned int prevPassengersCount = GetPassengersCount();

		//Boat 사람 이동
		for(unsigned int i=0;i< prevPassengersCount;i++)
		{
			bp.AddPassenger(MovePassenger(i));
		}

		//Plane 사람 이동
		prevPassengersCount = plane.GetPassengersCount();

		for(unsigned int i = 0; i< prevPassengersCount; i++)
		{
			bp.AddPassenger(plane.MovePassenger(i));
		}
		
		return bp;
	}

	std::string Boat::GetKind() const
	{
		return mKind;
	}
}
