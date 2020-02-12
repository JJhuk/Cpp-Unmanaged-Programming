#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"
#include <string>

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		Boat();
		~Boat();

		unsigned int GetSailSpeed() const;

		unsigned int GetMaxSpeed() const;

		Boatplane operator+(Airplane& plane);

		std::string GetKind() const;

	private:
		static std::string mKind;
	};
}
