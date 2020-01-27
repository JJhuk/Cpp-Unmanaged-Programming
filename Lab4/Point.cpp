#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(0.f, 0.f);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(0.f, 0.f);
	}

	float Point::Dot(const Point& other) const
	{
		return 0.0f;
	}

	Point Point::operator*(float operand) const
	{
		return Point(0.f, 0.f);
	}

	float Point::GetX() const
	{
		return 0.0f;
	}

	float Point::GetY() const
	{
		return 0.0f;
	}
}