#include <cassert>
#include <iostream>
#include "Point.h"
#include "PolyLine.h"

using namespace lab4;
using namespace std;
int main()
{
	Point p1(2.f, 3.f);
	Point p2(-1.f, 4.f);

	Point p3 = p1 + p2;

	assert(p3.GetX() == 1.f);
	assert(p3.GetY() == 7.f);

	Point p4 = p2 - p1;

	assert(p4.GetX() == -3.f);
	assert(p4.GetY() == 1.f);

	float dotProduct = p1.Dot(p2);

	assert(dotProduct == 10.f);

	Point p5 = p1 * 5.f;

	assert(p5.GetX() == 10.f);
	assert(p5.GetY() == 15.f);

	Point p6 = 2.f * p2;

	assert(p6.GetX() == -2.f);
	assert(p6.GetY() == 8.f);

	/* ----------------------- */

	PolyLine pl1;
	pl1.AddPoint(1.4f, 2.7f);
	pl1.AddPoint(3.5f, 2.1f);
	pl1.AddPoint(5.5f, 5.9f);
	pl1.AddPoint(-2.2f, 4.0f);
	pl1.AddPoint(4.6f, -1.3f); //
	pl1.AddPoint(6.0f, 4.5f);

	bool bRemoved = pl1.RemovePoint(4);

	assert(bRemoved);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl1.TryGetMinBoundingRectangle(&minP, &maxP);

	assert(minP.GetX() == -2.2f);
	assert(minP.GetY() == 2.1f);
	assert(maxP.GetX() == 6.0f);
	assert(maxP.GetY() == 5.9f);

	int a = 0;
	int* b = &a;

	std::cout << reinterpret_cast<int>(b) << endl;

	return 0;
}