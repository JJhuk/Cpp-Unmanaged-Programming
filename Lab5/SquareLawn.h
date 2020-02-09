#pragma once
#include "IFenceable.h"
#include "Lawn.h"
#include "RectangleLawn.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn();
		SquareLawn(const unsigned int side);
		SquareLawn(const SquareLawn& other);
		~SquareLawn();
	};


}