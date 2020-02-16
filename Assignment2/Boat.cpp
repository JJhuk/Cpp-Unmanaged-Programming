#include "Boat.h"
#include "Airplane.h"
#include <cmath>

namespace assignment2
{

	Boat::Boat(unsigned int maxPassengersCount) : Vehicle(maxPassengersCount)
	{
		InitTravel(2, 1);

		//std::cout << "Boat 생성자 호출" << std::endl;
	}

	Boat::Boat() : Vehicle(100)
	{

		//std::cout << "Boat 생성자 호출" << std::endl;
	}

	Boat::~Boat()
	{

		//std::cout << "Boat 소멸자 호출" << std::endl;
	}

	unsigned int Boat::GetSailSpeed() const
	{
		double sailSpeed = (800 - (10.0 * static_cast<double>(GetTotalPassengerWeight())));
		sailSpeed = sailSpeed > 20.0 ? sailSpeed : 20.0;

		return static_cast<unsigned int>(round(sailSpeed));
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		return Boatplane(*this, plane);
	}

}
