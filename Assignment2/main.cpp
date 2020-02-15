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
	Boatplane bp1(10);
	Person* p1 = new Person("Jake", 72);
	Person* p2 = new Person("Yumi", 58);
	bp1.AddPassenger(p1);
	bp1.AddPassenger(p2);
	Boatplane bp2(bp1);
	assert(bp1.GetPassenger(0)->GetName() == bp2.GetPassenger(0)->GetName());
	assert(bp1.GetPassenger(1)->GetName() == bp2.GetPassenger(1)->GetName());
	assert(bp1.GetPassenger(0) != bp2.GetPassenger(0));
	assert(bp1.GetPassenger(1) != bp2.GetPassenger(1));

	return 0;
}
