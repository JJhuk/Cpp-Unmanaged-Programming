#include <cassert>
#include "SmartStack.h"
#include "SmartStack.cpp"

using namespace assignment3;

int main()
{
	SmartStack<float> ss;

	ss.Push(3.4999f);
	ss.Push(1.2f);
	ss.Push(4.6555f);
	ss.Push(3.3299f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(ss.GetSum() == 15.985301f);
	assert(ss.GetAverage() == 1.599);
	assert(ss.GetVariance() == 40.057);
	assert(ss.GetStandardDeviation() == 6.329);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 1.1f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -5.9f);
	assert(ss.GetSum() == 19.1853008f);
	assert(ss.GetAverage() == 2.398);
	assert(ss.GetVariance() == 17.714);
	assert(ss.GetStandardDeviation() == 4.209);

	

	return 0;
}
