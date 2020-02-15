#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"
#include <string>

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

		std::string GetKind() const;


		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		inline bool GetIsConnectedTrailer() const;

	private:
		bool mbIsConnectedTrailer;
		const Trailer* mTrailer;
		static std::string mKind;
	};
}
