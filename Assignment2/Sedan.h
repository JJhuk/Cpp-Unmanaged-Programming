#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		virtual  ~Sedan();

		unsigned int GetMaxSpeed() const;

		unsigned int GetDriveSpeed() const;

		Sedan& operator=(const Sedan& rhs);

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

	private:
		const Trailer* mTrailer;
		bool mbIsConnected;
	};
}
