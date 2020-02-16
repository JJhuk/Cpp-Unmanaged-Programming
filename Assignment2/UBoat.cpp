#include "UBoat.h"
#include <cmath>

namespace assignment2
{

	UBoat::UBoat() : Vehicle(50)
	{

		//std::cout << "UBoat 생성자 호출" << std::endl;
		InitTravel(2, 4);
	}

	UBoat::~UBoat()
	{
		///std::cout << "UBoat 소멸자 호출" << std::endl;
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return GetSailSpeed() > GetDiveSpeed() ? GetSailSpeed() : GetDiveSpeed();
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double sailSpeed = (550.0 - (passengerTotalWeight / 10.0));
		sailSpeed = sailSpeed > 200.0 ? sailSpeed : 200.0;

		return static_cast<unsigned int>(round(sailSpeed));
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double passengerTotalWeight = static_cast<double>(GetTotalPassengerWeight());
		double diveSpeed = 500.0 * log((passengerTotalWeight + 150.0) / 150.0) + 30.0;

		return static_cast<unsigned int>(round(diveSpeed));
	}

}
