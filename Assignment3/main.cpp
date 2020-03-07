#include <cassert>

#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

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

	SmartQueue<float> sq;

	sq.Enqueue(3.4999f);
	sq.Enqueue(1.2f);
	sq.Enqueue(4.6555f);
	sq.Enqueue(3.3299f);
	sq.Enqueue(10.2f);
	sq.Enqueue(1.1f);
	sq.Enqueue(-5.9f);
	sq.Enqueue(1.1f);
	sq.Enqueue(-12.4f);
	sq.Enqueue(9.2f);

	assert(sq.GetCount() == 10U);
	assert(sq.Peek() == 3.4999f);
	assert(sq.GetMax() == 10.2f);
	assert(sq.GetMin() == -12.4f);
	assert(sq.GetSum() == 15.9853010f);
	assert(sq.GetAverage() == 1.599);
	assert(sq.GetVariance() == 40.057);
	assert(sq.GetStandardDeviation() == 6.329);
	assert(sq.Peek() == 3.4999f);

	float dequeued1 = sq.Dequeue();
	float dequeued2 = sq.Dequeue();

	assert(dequeued1 == 3.4999f);
	assert(dequeued2 == 1.2f);
	assert(sq.GetCount() == 8U);
	assert(sq.Peek() == 4.6555f);
	assert(sq.GetMax() == 10.2f);
	assert(sq.GetMin() == -12.4f);
	assert(sq.GetSum() == 11.2854013f);
	assert(sq.GetAverage() == 1.411);
	assert(sq.GetVariance() == 49.564);
	assert(sq.GetStandardDeviation() == 7.040);

	QueueStack<float> qs(3);

	qs.Enqueue(3.4f);
	qs.Enqueue(1.2f);
	qs.Enqueue(4.6f);
	qs.Enqueue(3.32f);
	qs.Enqueue(10.2f);
	qs.Enqueue(1.1f);
	qs.Enqueue(-5.9f);
	qs.Enqueue(1.1f);
	qs.Enqueue(-12.4f);
	qs.Enqueue(9.2f);

	assert(qs.GetStackCount() == 4U);
	assert(qs.Peek() == 4.6f);
	assert(qs.GetCount() == 10U);
	assert(qs.GetMax() == 10.2f);
	assert(qs.GetMin() == -12.4f);
	assert(qs.GetSum() == 15.8200026f);
	assert(qs.GetAverage() == 1.582);
	assert(qs.GetStackCount() == 4U);
	assert(qs.Peek() == 4.6f);

	float dequeued3 = qs.Dequeue();
	float dequeued4 = qs.Dequeue();
	float dequeued5 = qs.Dequeue();

	assert(dequeued3 == 4.6f);
	assert(dequeued4 == 1.2f);
	assert(dequeued5 == 3.4f);
	assert(qs.GetCount() == 7U);
	assert(qs.GetStackCount() == 3U);
	assert(qs.GetMax() == 10.2f);
	assert(qs.GetMin() == -12.4f);
	assert(qs.GetSum() == 6.62000322f);
	assert(qs.GetAverage() == 0.946);

	return 0;
}
