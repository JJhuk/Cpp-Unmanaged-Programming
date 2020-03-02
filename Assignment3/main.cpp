#include <cassert>
#include "SmartStack.h"
using namespace assignment3;

int main()
{
    SmartStack<double> ss;

    assert(ss.GetCount() == 0U);
    assert(ss.GetMax() == numeric_limits<double>::min());
    assert(ss.GetMin() == numeric_limits<double>::max());
    assert(ss.GetSum() == 0);
    assert(ss.GetAverage() == 0);
    assert(ss.GetVariance() == 0);
    assert(ss.GetStandardDeviation() == 0);

    ss.Push(1.24);

    assert(ss.GetCount() == 1U);
    assert(ss.GetMax() == 1.24);
    assert(ss.GetMin() == 1.24);
    assert(ss.GetSum() == 1.24);
    assert(ss.GetAverage() == 1.24);

    ss.Pop();

    assert(ss.GetCount() == 0U);
    assert(ss.GetMax() == numeric_limits<double>::min());
    assert(ss.GetMin() == numeric_limits<double>::max());
    assert(ss.GetSum() == 0);
    assert(ss.GetAverage() == 0);
    assert(ss.GetVariance() == 0);
    assert(ss.GetStandardDeviation() == 0);

    return 0;
}
