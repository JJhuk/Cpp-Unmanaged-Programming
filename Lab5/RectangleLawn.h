#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public IFenceable, public Lawn
	{
	public:
		RectangleLawn();
		RectangleLawn(unsigned int width, unsigned int height);
		RectangleLawn(const RectangleLawn& other);

		RectangleLawn& operator=(const RectangleLawn& other);

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetArea() const;


		~RectangleLawn();

	private:
		unsigned int mWidth;
		unsigned int mHeight;


	};
}

