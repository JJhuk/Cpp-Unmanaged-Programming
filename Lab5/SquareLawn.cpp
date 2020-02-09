#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn() : RectangleLawn()
	{
	}

	SquareLawn::SquareLawn(const unsigned int side) : RectangleLawn(side, side)
	{
	}

	SquareLawn::SquareLawn(const SquareLawn& other) : RectangleLawn(other)
	{
	}

	SquareLawn::~SquareLawn()
	{
	}

}