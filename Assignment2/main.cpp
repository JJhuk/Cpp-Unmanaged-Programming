#include "Person.h"
#include "Airplane.h"
#include <iostream>

using namespace std;
using namespace assignment2;
int main()
{
	Airplane* air = new Airplane(2);

	cout << air->mKind << endl;
	return 0;
}