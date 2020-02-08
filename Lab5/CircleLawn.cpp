#include "CircleLawn.h"

CircleLawn::CircleLawn() : lab5::Lawn(), mRadius(0)
{
	
}

CircleLawn::CircleLawn(unsigned int radius) : lab5::Lawn() , mRadius(radius)
{

}

CircleLawn::CircleLawn(CircleLawn& other) : lab5::Lawn(), mRadius(other.mRadius)
{

}

CircleLawn& CircleLawn::operator=(CircleLawn& other)
{
	if (&other != &(*this))
	{
		mRadius = other.mRadius;
		//대입 해 주어야 함.
	}
	return *this;
}

CircleLawn::~CircleLawn()
{

}

unsigned int CircleLawn::GetArea() const
{
	const double PI = 3.14;
	double area = PI * static_cast<double>(mRadius) * static_cast<double>(mRadius);

	return static_cast<unsigned int>(area);
}

