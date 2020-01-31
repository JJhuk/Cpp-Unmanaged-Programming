#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine() : mPointsMaxSize(10), mSize(0)
	{
		for (unsigned int i = 0; i < mPointsMaxSize; i++)
		{
			mPoints[i] = nullptr;
		}
	}

	PolyLine::PolyLine(const PolyLine& other) : mPointsMaxSize(other.mPointsMaxSize), mSize(other.mSize)
	{
		if (other.mSize > 0)
		{
			for (unsigned int i = 0; i < other.mSize; i++)
			{
				mPoints[i] = other.mPoints[i];
			}
			mSize = other.mSize;
		}
		else
		{
			for (unsigned int i = 0; i < mPointsMaxSize; i++)
			{
				mPoints[i] = nullptr;
			}
		}
	}

	PolyLine::~PolyLine()
	{
		delete[] mPoints;
		mPointsMaxSize = 0;
		mSize = 0;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= 0 && mSize < 10)
		{
			mPoints[mSize++] = new Point(x, y);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= 0 && mSize < 10)
		{
			mPoints[mSize++] = const_cast<Point*>(point);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= 0 && i < mSize && mSize > 0)
		{
			Point* tempPoints[10];
			for (unsigned int j = 0; j < i; j++)
			{
				tempPoints[j] = mPoints[j];
			}
			for (unsigned int k = i + 1; k < mSize; k++)
			{
				tempPoints[k-1] = mPoints[k];
			}
			tempPoints[10 - 1] = nullptr;

			delete[] mPoints;
			memcpy(mPoints, tempPoints,sizeof(tempPoints));
			delete[] tempPoints;
			mSize--;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= 0 && i < mSize)
		{
			return mPoints[i];
		}
		return nullptr;
	}
}