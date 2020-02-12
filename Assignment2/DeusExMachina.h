#pragma once

#include "Vehicle.h"

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
		~DeusExMachina();

	private:
		DeusExMachina();
		static DeusExMachina* mInstance;
		const Vehicle* mVehicles[10];
		const unsigned int mMaxIdx;
		unsigned int mSize;
	};
}
