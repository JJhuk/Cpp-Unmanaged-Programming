
#include <iostream>
#include <cassert>
#include "MyString.h"

using namespace assignment1;
using namespace std;

int main()
{
	MyString me("Hello1");
	MyString me2("halo");
	MyString me3 = me + me2;

	system("pause");
	return 0;
}
