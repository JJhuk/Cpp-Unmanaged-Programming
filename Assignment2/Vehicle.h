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

		~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		virtual std::string GetKind() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		inline unsigned int GetRestCount() const;
		inline unsigned int GetCanMoveCount() const;
		inline unsigned int GetHowMoveCount() const;

		inline void SetRestCount(unsigned int restCount);
		inline void SetCanMoveCount(unsigned int canMoveCount);
		
		const Person* MovePassenger(unsigned int idx);

	private:
		const Person* mPassenger[100];
		unsigned int mSize;
		unsigned int mMaxPassengersCount;

		//¼öÁ¤
		unsigned int mRestCount;
		unsigned int mCanMoveCount;
		unsigned int mHowMoveCount;
	};
}
