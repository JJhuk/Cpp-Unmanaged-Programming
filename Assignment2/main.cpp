#include <cassert>

#include "Vehicle.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "Trailer.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include "Person.h"

using namespace assignment2;

int main()
{
	Person* p = new Person("Bob", 85);

	assert(p->GetName() == std::string("Bob"));
	assert(p->GetWeight() == 85);

	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);

	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	assert(a.GetMaxPassengersCount() == 5);
	assert(a.GetPassengersCount() == 3);
	assert(a.GetPassenger(1) == p2);
	assert(a.GetFlySpeed() == 648);
	assert(a.GetDriveSpeed() == 59);
	assert(a.GetMaxSpeed() == 648);

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = a + b;

	assert(bp.GetPassengersCount() == 6);
	assert(bp.GetMaxPassengersCount() == 10);

	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	bool bSame = deusExMachina1 == deusExMachina2;
	assert(bSame);

	Airplane* airplane = new Airplane(5);
	Boat* boat = new Boat(5);
	Boatplane* boatplane = new Boatplane(5);
	Motorcycle* motorcycle = new Motorcycle();
	Sedan* sedan = new Sedan();
	Sedan* sedan2 = new Sedan();
	UBoat* uboat = new UBoat();

	bool bAdded = sedan2->AddTrailer(new Trailer(50));
	assert(bAdded);

	bAdded = sedan2->AddTrailer(new Trailer(60));
	assert(!bAdded);

	assert(deusExMachina1->GetFurthestTravelled() == nullptr);

	return 0;
}
