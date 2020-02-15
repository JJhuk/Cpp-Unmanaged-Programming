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
    Airplane a1(5);
    a1.AddPassenger(p);
    a1.AddPassenger(p2);
    a1.AddPassenger(p3);
    Boat b1(5);
    b1.AddPassenger(p4);
    b1.AddPassenger(p5);
    b1.AddPassenger(p6);
    Airplane a2(a1);
    Boat b2(b1);
    Boatplane bp1 = a1 + b1;
    Boatplane bp2 = b2 + a2;
    assert(bp1.GetMaxPassengersCount() == bp2.GetMaxPassengersCount());
    assert(bp1.GetMaxSpeed() == bp2.GetMaxSpeed());
    for (int i = 0; i < bp1.GetPassengersCount(); i++)
    {
        assert(bp1.GetPassenger(i)->GetName() == bp2.GetPassenger(i)->GetName());
        assert(bp1.GetPassenger(i)->GetWeight() == bp2.GetPassenger(i)->GetWeight());
    }
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