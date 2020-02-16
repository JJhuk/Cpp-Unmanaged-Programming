#include <cassert>
#include <iostream>
#include <iomanip>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "Trailer.h"
#include "DeusExMachina.h"
#include "Person.h"


#define STR(name) #name

using namespace assignment2;
using namespace std;

int main()
{
	const char* MAX_SPEED_LABLE = "Max Speed: ";
	const char* CUR_P_LABLE = "Current Person: ";
	const unsigned int MAX_CAPACITY = 10;


	Sedan sedanTest;
	Trailer* t1 = new Trailer(10);
	Trailer* t2 = new Trailer(20);

	assert(sedanTest.AddTrailer(t1));
	assert(!sedanTest.AddTrailer(t1));
	assert(!sedanTest.AddTrailer(t2));
	assert(sedanTest.RemoveTrailer());
	assert(sedanTest.AddTrailer(t2));
	assert(sedanTest.RemoveTrailer());

	DeusExMachina* d = DeusExMachina::GetInstance();
	Vehicle* demAirplain = new Airplane(MAX_CAPACITY);
	Vehicle* demBoat = new Airplane(MAX_CAPACITY);
	Vehicle* demBoatplain = new Boatplane(MAX_CAPACITY);
	Vehicle* demMotorcycle = new Motorcycle();
	Vehicle* demSedan1 = new Sedan();
	Vehicle* demSedan2 = new Sedan();
	Trailer* demTrailer = new Trailer(10);
	static_cast<Sedan*>(demSedan2)->AddTrailer(demTrailer);
	Vehicle* demUBoat = new UBoat();

	d->AddVehicle(demAirplain);
	d->AddVehicle(demBoat);
	d->AddVehicle(demBoatplain);
	d->AddVehicle(demMotorcycle);
	d->AddVehicle(demSedan1);
	d->AddVehicle(demSedan2);
	d->AddVehicle(demUBoat);

	for (size_t i = 0; i < 7; i++)
	{
		Vehicle* tempVPointer = d->GetVehicle(i);
		for (size_t j = tempVPointer->GetPassengersCount(); j < tempVPointer->GetMaxPassengersCount(); j++)
		{
			tempVPointer->AddPassenger(new Person(STR((i + j)), 10));
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		d->Travel();
	}

	return 0;
}