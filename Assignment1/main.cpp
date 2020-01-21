#include "MyString.h"
#include <iostream>
#include <string>
using namespace std;
using namespace assignment1;

int main()
{
	MyString s1("HEllo 123K");
	s1.ToLower(); // s1: "hello 123k"
	cout << s1.GetCString() << endl;

	system("pause");
	return 0;
}