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
		for (unsigned int i = 0; i < mPointsMaxSize; i++)
		{
			if (other.mPoints[i] != nullptr)
			{
				mPoints[i] = new Point(*other.mPoints[i]);
			}
			else
			{
				mPoints[i] = nullptr;
			}
		}
		mMaxX = other.mMaxX;
		mMinY = other.mMinY;
		mMinX = other.mMinX;
		mMaxY = other.mMaxY;
	}

	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			delete mPoints[i];
		}
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
			mPoints[mSize++] = point;
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
			delete mPoints[i];
			const Point* tempPoints[10];
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
			memcpy(mPoints, tempPoints, sizeof(tempPoints));
			mSize--;
			InitMaxMinXY();
			GetMaxMinXY();
			return true;
		}
		else
		{
			return false;
		}
	}


	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize >= 2)
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
		for (unsigned int i = 0; i < mPointsMaxSize; i++)
		{
			if (other.mPoints[i] != nullptr)
			{
				mPoints[i] = new Point(*other.mPoints[i]);
			}
			else
			{
				mPoints[i] = nullptr;
			}
		}
		mSize = other.mSize;
		mMaxX = other.mMaxX;
		mMinY = other.mMinY;
		mMinX = other.mMinX;
		mMaxY = other.mMaxY;
		return *this;
	}
	void PolyLine::GetMaxMinXY()
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			mMaxX = mPoints[i]->GetX() > mMaxX ? mPoints[i]->GetX() : mMaxX;
			mMaxY = mPoints[i]->GetY() > mMaxY ? mPoints[i]->GetY() : mMaxY;
			mMinX = mPoints[i]->GetX() < mMinX ? mPoints[i]->GetX() : mMinX;
			mMinY = mPoints[i]->GetY() < mMinY ? mPoints[i]->GetY() : mMinY;
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