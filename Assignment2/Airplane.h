#pragma once
#include "Boatplane.h"
#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		//static const std::string mKind;
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		//Vehicle
		unsigned int GetMaxSpeed() const;

		//IFlyable
		unsigned int GetFlySpeed() const;

		//IDrivable
		unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);

	private:
	};
}



