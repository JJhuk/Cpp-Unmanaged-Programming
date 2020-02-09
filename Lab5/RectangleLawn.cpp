#include "RectangleLawn.h"
#include <cmath>

RectangleLawn::RectangleLawn() : lab5::IFenceable(), lab5::Lawn(),
mWidth(0), mHeight()
{
}

RectangleLawn::RectangleLawn(const unsigned int width, const unsigned int height) :
	lab5::IFenceable(), lab5::Lawn(),
	mWidth(width), mHeight(height)
{
}

RectangleLawn::RectangleLawn(const RectangleLawn& other)
{
	if (&other != &(*this))
	{
		mWidth = other.mWidth;
		mHeight = other.mHeight;
	}
}

RectangleLawn& RectangleLawn::operator=(const RectangleLawn& other)
{
	if (&other != &(*this))
	{
		mWidth = other.mWidth;
		mHeight = other.mHeight;
	}
	return *this;
}

unsigned int RectangleLawn::GetMinimumFencesCount() const
{
	int rectRound = (mWidth * 2) + (mHeight * 2);
	double fencesCount = static_cast<double>(rectRound) / WIDTH_FENCE;
	fencesCount = ceil(fencesCount);

	return static_cast<unsigned int>(fencesCount);
}

unsigned int RectangleLawn::GetFencePrice(lab5::eFenceType fenceType) const
{
	int rectRound = (mWidth * 2) + (mHeight * 2);
	switch (fenceType)
	{
	case lab5::RED_CEDAR:
		return	rectRound * COST_RED_CENDAR;

	case lab5::SPRUCE:
		return	rectRound * COST_SPRUCE;

	default:
		return 0;
	}
}

unsigned int RectangleLawn::GetArea() const
{
	return mWidth * mHeight;
}

RectangleLawn::~RectangleLawn()
{
}
