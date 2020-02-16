#pragma once

#include "Person.h"
#include <string>

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle();
		Vehicle(const Vehicle& other);

		Vehicle& operator=(const Vehicle& other);

		virtual  ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalMoveCount() const;

		void Deinitializer();

		void InitTravel(unsigned int maxMoveCount, unsigned int mustRestCount);

		void TravelVehicle();
		unsigned int GetTotalPassengerWeight() const;

		const Person* MovePassenger(unsigned int idx);

	private:
		const Person* mPassenger[100];
		unsigned int mTotalPassengerWeight;
		unsigned int mSize;
		unsigned int mMaxPassengersCount;

		void setMustRestCount(unsigned int mustRestCount);
		void setMaxMoveCount(unsigned int maxMoveCount);

		//수정
		unsigned int mNowRestCount;	//지금 얼마나 쉬었는지
		unsigned int mMustRestCount; //최대 쉬어야 하는지

		unsigned int mMaxMoveCount;	//최대 얼마나 갈 수 있는지
		unsigned int mNowMoveCount;	//지금 얼마나 갔는지.

		unsigned int mTotalMoveCount;	//총 얼마나 간지.
	};
}
