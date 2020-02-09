#pragma once
#include "IFenceable.h"
#include "Lawn.h"
#include "RectangleLawn.h"
class SquareLawn : public RectangleLawn
{
public:
	SquareLawn();
	SquareLawn(const unsigned int side);
	SquareLawn(const SquareLawn& other);
	~SquareLawn();
};

