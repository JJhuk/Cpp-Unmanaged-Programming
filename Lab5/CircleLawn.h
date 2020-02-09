#pragma once
#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn	//울타리를 놓을 수 없는 구조
	{
	public:
		CircleLawn();
		CircleLawn(unsigned int raidus);
		CircleLawn(CircleLawn& other);

		CircleLawn& operator=(CircleLawn& other);

		~CircleLawn();
		unsigned int GetArea() const;

	private:
		unsigned int mRadius;
	};

}
