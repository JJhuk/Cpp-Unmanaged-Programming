#pragma once

#include "Point.h"

namespace lab4
{
	class PolyLine : public Point
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const Point* operator[](unsigned int i) const;
		PolyLine& operator=(const PolyLine& other);
		void GetMaxMinXY();
		void RenewMaxMinXY(float x, float y);
		void InitMaxMinXY();
	private:
		const Point* mPoints[10];
		const int mPointsMaxSize;
		unsigned int mSize;

		float mMaxX;
		float mMaxY;
		float mMinX;
		float mMinY;
	};

}