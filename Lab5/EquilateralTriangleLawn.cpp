#include "EquilateralTriangleLawn.h"
#include <cmath>

EquilateralTriangleLawn::EquilateralTriangleLawn() : mSide(0)
{

}

EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int side) : mSide(side)
{
}

EquilateralTriangleLawn::EquilateralTriangleLawn(const EquilateralTriangleLawn& other) : mSide(other.mSide)
{

}

EquilateralTriangleLawn& EquilateralTriangleLawn::operator=(const EquilateralTriangleLawn& other)
{
	if (&(*this) != &other)
	{
		mSide = other.mSide;
	}

	return *this;
}

unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
{
	if (mSide != 0)
	{
		unsigned int round = mSide * 3;
		float temp = static_cast<double>(round) / static_cast<double> (WIDTH_FENCE);
		temp += 0.5f;
		unsigned int fenceCount = static_cast<unsigned int>(temp);
		
		return fenceCount;
	}
	else
	{
		return 0;
	}
}

unsigned int EquilateralTriangleLawn::GetFencePrice(lab5::eFenceType fenceType) const
{
	switch (fenceType)
	{
	case lab5::RED_CEDAR:
		return GetMinimumFencesCount() * COST_RED_CENDAR;
	case lab5::SPRUCE:
		return GetMinimumFencesCount() * COST_SPRUCE;
	default:
		return 0;
	}
}

unsigned int EquilateralTriangleLawn::GetArea() const
{
	if (mSide != 0)
	{
		double height = (static_cast<double>(mSide) / 2)* sqrt(3);
		double area = (height * static_cast<double>(mSide)) / 2;
		area += 0.5;
		 
		return static_cast<unsigned int>(area);
	}
	else
	{
		return 0;
	}
}

EquilateralTriangleLawn::~EquilateralTriangleLawn()
{
}
