#pragma once

#include "Vehicle.h"
#include <string>

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina();
		static DeusExMachina* mInstance;
		Vehicle* mVehicles[10];
		const unsigned int mMaxIdx = 10;
		unsigned int mSize;
	};

}
