#include "Person.h"
#include <iostream>

using namespace std;
using namespace assignment2;
int main()
{
	Person p("Bob", 85);
	cout << p.GetName() << p.GetWeight();
	return 0;
}