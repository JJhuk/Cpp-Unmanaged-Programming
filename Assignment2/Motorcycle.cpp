#include "Motorcycle.h"
#include <cmath>

namespace assignment2
{
	Motorcycle::Motorcycle() : Vehicle(2)
	{
		//std::cout << "오토바이 생성자" << std::endl;
		InitTravel(5, 1);
	}

	Motorcycle::~Motorcycle()
	{
		//std::cout << "오토바이 소멸자" << std::endl;
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double driveSpeed = ((-pow(passengerTotalWeight / 15.0, 3.0) + (2.0 * passengerTotalWeight) + 400.0));
		driveSpeed = driveSpeed > 0.0 ? driveSpeed : 0.0;

		return static_cast<unsigned int>(round(driveSpeed));
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

}
