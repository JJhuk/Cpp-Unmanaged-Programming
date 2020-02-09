#pragma once
#include "Lawn.h"
#include "IFenceable.h"
class RectangleLawn : public lab5::IFenceable, public lab5::Lawn
{
public:
	RectangleLawn();
	RectangleLawn(unsigned int width, unsigned int height);
	RectangleLawn(const RectangleLawn& other);

	RectangleLawn& operator=(const RectangleLawn& other);

	unsigned int GetMinimumFencesCount() const;
	unsigned int GetFencePrice(lab5::eFenceType fenceType) const;
	unsigned int GetArea() const;


	~RectangleLawn();

private:
	unsigned int mWidth;
	unsigned int mHeight;


};

