#include "MyString.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const char *ptr = "hello";
	cout << sizeof(&ptr) <<" " <<sizeof(ptr)<<"\n";
	for (int i = 0; ptr[i]!='\0'; i++) 
	{
		cout << ptr[i];
	}
	cout << "\n";
	system("pause");
	return 0;
}