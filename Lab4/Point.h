#pragma once

namespace lab4
{
	class Point
	{
		friend Point operator*(float operand, const Point& rhs);
	public:
		Point(float x, float y);
		Point();
		~Point();
		Point& operator=(const Point& other);
		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		Point operator*(float operand) const;
		float Dot(const Point& other) const;


		void SetX(float x);
		void SetY(float y);
		float GetX() const;
		float GetY() const;
	private:
		float mX;
		float mY;
	};
}