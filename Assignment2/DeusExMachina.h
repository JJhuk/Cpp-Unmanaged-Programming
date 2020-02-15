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
		Vehicle* GetVehicle(unsigned int i) const;

	private:
		DeusExMachina();
		static DeusExMachina* mInstance;
		Vehicle* mVehicles[10];
		const unsigned int MAX_IDX = 10;
		unsigned int mSize;
		bool mbIsTravelled;
	};

}
