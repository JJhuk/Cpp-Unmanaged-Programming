#include <cassert>
#include <iostream>
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
using namespace std;
int main()
{
    Sedan s1;
    Sedan s2;
    s2.AddTrailer(new Trailer(100));
    assert(s1.GetMaxSpeed() == 480);
    assert(s2.GetMaxSpeed() == 458);
    s1.AddPassenger(new Person("a", 100));
    s2.AddPassenger(new Person("a", 100));
    assert(s1.GetMaxSpeed() == 458);
    assert(s2.GetMaxSpeed() == 400);
    s1.AddPassenger(new Person("a", 100));
    s2.AddPassenger(new Person("a", 100));

    assert(s1.GetMaxSpeed() == 400);
    assert(s2.GetMaxSpeed() == 380);
    s1.AddPassenger(new Person("a", 100));
    s2.AddPassenger(new Person("a", 100));

    assert(s1.GetMaxSpeed() == 380);
    assert(s2.GetMaxSpeed() == 300);
    s1.AddPassenger(new Person("a", 100));
    s2.AddPassenger(new Person("a", 100));

    assert(s1.GetMaxSpeed() == 300);
    assert(s2.GetMaxSpeed() == 300);
    return 0;
}