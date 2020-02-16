#pragma once
#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"
namespace assignment2
{
	class Boat;
	class Airplane;
	
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Boatplane& other);
		Boatplane(Boat& lhs, Airplane& rhs);
		Boatplane(Airplane& rhs, Boat& lhs);

		~Boatplane();
		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetFlySpeed() const;

	};
}
