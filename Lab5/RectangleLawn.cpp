#include "RectangleLawn.h"

RectangleLawn::RectangleLawn() : lab5::IFenceable(), lab5::Lawn(),
mWidth(0), mHeight()
{
}

RectangleLawn::RectangleLawn(unsigned int width, unsigned int height) :
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
	double fencesCount = static_cast<double>(GetArea()) / static_cast<double>(WIDTH_FENCE);
	fencesCount += 0.5;

	return static_cast<unsigned int>(fencesCount);
}

unsigned int RectangleLawn::GetFencePrice(lab5::eFenceType fenceType) const
{
	return 0;
}

unsigned int RectangleLawn::GetArea() const
{
	return mWidth * mHeight;
}

RectangleLawn::~RectangleLawn()
{
}
