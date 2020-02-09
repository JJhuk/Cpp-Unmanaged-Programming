#pragma once
#include "IFenceable.h"
#include "Lawn.h"
namespace lab5
{
	class EquilateralTriangleLawn : public IFenceable, public Lawn
	{
	public:
		EquilateralTriangleLawn();
		EquilateralTriangleLawn(unsigned int side);
		EquilateralTriangleLawn(const EquilateralTriangleLawn& other);

		EquilateralTriangleLawn& operator=(const EquilateralTriangleLawn& other);

		~EquilateralTriangleLawn();

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(lab5::eFenceType fenceType) const;
		unsigned int GetArea() const;

	private:
		unsigned int mSide;
	};
}

