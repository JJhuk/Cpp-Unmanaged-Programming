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
		~Sedan();

		unsigned int GetMaxSpeed() const;

		unsigned int GetDriveSpeed() const;


		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		inline bool GetIsConnectedTrailer() const;

	private:
		bool mbIsConnectedTrailer;
		const Trailer* mTrailer;
	};
}
