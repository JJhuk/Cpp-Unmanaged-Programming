#pragma once
#include <stack>
#include <queue>
using namespace std;
namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack();
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& other);
		~QueueStack();
		QueueStack& operator=(const QueueStack& rhs);

		void Enqueue(const T& number);
		T Peek() const;
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		unsigned int GetCount() const;
		unsigned int GetStackCount() const;
	private:
		queue<stack<T>> mQueueStack;
		const unsigned int mMaxStackSize;
		const unsigned int mNowQueueIndex;
		void RenewSmartQueue();
		T mMax;
		T mMin;
		T mSum;
		T mAvg;
		double mVariance;
	};
}
