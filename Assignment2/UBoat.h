#pragma once
#include "Vehicle.h"
#include "IDivable.h"
#include "ISailable.h"
#include <string>

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		~UBoat();

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetDiveSpeed() const;

		std::string GetKind() const;

	private:
		static std::string mKind;
	};
}
