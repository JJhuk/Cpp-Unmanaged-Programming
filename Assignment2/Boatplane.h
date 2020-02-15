#pragma once
#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"
namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Boatplane& other);

		~Boatplane();
		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetFlySpeed() const;

	};
}
