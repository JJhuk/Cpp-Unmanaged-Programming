#pragma once

#include "Person.h"

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

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

	private:
		const Person* mPassenger[100];
		unsigned int mSize;
		unsigned int mMaxPassengersCount;
	};
}
