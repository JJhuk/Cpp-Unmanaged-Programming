#pragma once
#include "IDrivable.h"
#include "Vehicle.h"
#include <string>

namespace assignment2
{
	class Motorcycle : public IDrivable, public Vehicle
	{
	public:
		Motorcycle();
		~Motorcycle();

		unsigned int GetDriveSpeed() const;

		unsigned int GetMaxSpeed() const;

		std::string GetKind() const;

	private:
		static std::string mKind;
	};
}
