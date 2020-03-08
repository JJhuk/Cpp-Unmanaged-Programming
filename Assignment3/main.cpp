#include <cassert>
#include <iostream>
#include <cmath>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;

int main()
{
	SmartStack<unsigned char> ss;
	ss.Push(10);
	ss.Push(21);
	ss.Push(37);

	return 0;
}
