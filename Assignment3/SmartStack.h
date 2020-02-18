#pragma once
#include <stack>
using namespace  std;
namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();

		~SmartStack();
		SmartStack(const SmartStack& other);

		void Push(const T& val);	//Pop과 push에서 값을 다시 갱신해줌
		T Pop();
		T Peek() const;
		T GetMax() const;	//시간복잡도가 O(1)이어야 함.
		T GetMin() const;
		double GetAverage() const;	//4번째 자리 반올림.
		T GetSum() const;
		double GetVariance() const;	//시간복잡도가 O(1)이어야 함. 
		double GetStandardDeviation() const;	//시간복잡도가 O(1)이어야 함.
		unsigned int GetCount() const;


		SmartStack& operator=(const SmartStack& rhs);

	private:
		bool RenewSmartStack();
		stack<T> mStack;
		T mMax;
		T mMin;
		T mSum;
		T mAvg;
		double mVariance;

	};


}
