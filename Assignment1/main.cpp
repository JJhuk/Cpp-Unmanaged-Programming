#include "MyString.h"
#include <iostream>
#include <string>
using namespace std;
using namespace assignment1;

int main()
{
	MyString s("Hello");
	bool b1 = s.RemoveAt(0); // s는 "ello", b1은 true
	cout << s.GetCString() << endl;
	bool b2 = s.RemoveAt(2); // s는 "elo", b2은 true
	cout << s.GetCString() << endl;
	bool b3 = s.RemoveAt(4); // s는 "elo", b3은 false
	cout << s.GetCString() << endl;

	
	system("pause");
	return 0;
}