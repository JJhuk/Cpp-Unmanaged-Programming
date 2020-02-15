#pragma once
#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"
#include <string>

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		std::string GetKind() const;
		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetFlySpeed() const;

	private:
		static std::string mKind;
	};
}
