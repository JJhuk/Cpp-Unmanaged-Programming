#include <cstring>
#include <cmath>
#include <cfloat>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine() : mPointsMaxSize(10), mSize(0)
	{
		for (unsigned int i = 0; i < mPointsMaxSize; i++)
		{
			mPoints[i] = nullptr;
		}
		InitMaxMinXY();
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

			mMaxX = other.mMaxX;
			mMinY = other.mMinY;
			mMinX = other.mMinX;
			mMaxY = other.mMaxY;
		}
		else
		{
			for (unsigned int i = 0; i < mPointsMaxSize; i++)
			{
				mPoints[i] = nullptr;
			}
			InitMaxMinXY();
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
			RenewMaxMinXY(x, y);
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
			RenewMaxMinXY(point->GetX(), point->GetY());
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
			for (unsigned int j = 0; j < mPointsMaxSize; j++)
			{
				tempPoints[j] = nullptr;
			}
			for (unsigned int j = 0; j < i; j++)
			{
				tempPoints[j] = mPoints[j];
			}
			for (unsigned int k = i + 1; k < mSize; k++)
			{
				tempPoints[k - 1] = mPoints[k];
			}
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
		if (mSize >= 3)	//무조껀 3개이상이어야 함.
		{
			outMin->SetX(mMinX);
			outMin->SetY(mMinY);
			outMax->SetX(mMaxX);
			outMax->SetY(mMaxY);
			return true;
		}
		else
		{
			return false;
		}
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= 0 && i < mSize)
		{
			return mPoints[i];
		}
		return nullptr;
	}
	PolyLine& PolyLine::operator=(const PolyLine& other)
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

		return *this;
	}
	void PolyLine::GetMaxMinXY()
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			mMaxX = mPoints[i]->GetX() > mMaxX ? mPoints[i]->GetX() : mMaxX;
			mMaxY = mPoints[i]->GetY() > mMaxY ? mPoints[i]->GetY() : mMaxY;
			mMinX = mPoints[i]->GetX() < mMinX ? mPoints[i]->GetX() : mMinX;
			mMinY = mPoints[i]->GetX() < mMinY ? mPoints[i]->GetY() : mMinY;
		}
	}
	void PolyLine::RenewMaxMinXY(float x, float y)
	{
		mMaxX = x > mMaxX ? x : mMaxX;
		mMaxY = y > mMaxY ? y : mMaxY;
		mMinX = x < mMinX ? x : mMinX;
		mMinY = y < mMinY ? y : mMinY;
	}
	void PolyLine::InitMaxMinXY()
	{
		mMaxX = -FLT_MAX;
		mMaxY = -FLT_MAX;
		mMinX = FLT_MAX;
		mMinY = FLT_MAX;
	}
}