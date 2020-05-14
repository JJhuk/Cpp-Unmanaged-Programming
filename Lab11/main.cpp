#include <iostream>

int arr[] = { 20,42,55,62,78,92,112,132,140,145,150,170 };

using namespace std;

int foo(int *arr, int s,int e,int x)
{
	if (s == e)
		return arr[s] == x ? s : -1;
	int mid = (s + e) / 2;
	cout << arr[mid] << '\n';

	if (x == arr[mid])
		return mid;
	if (arr[mid] > x)
	{
		return foo(arr, s, mid-1, x);
	}
	return foo(arr, mid + 1, e, x);
}


int main(void)
{
	cout << foo(arr, 0, 12, 132);
	return 0;
}