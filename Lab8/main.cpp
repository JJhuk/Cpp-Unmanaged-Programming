#include <cassert>
#include <bitset>
#include "FixedBoolVector.h"
#include "FixedVector.h"
#include <iostream>
using namespace lab8;

void testFixedBoolVector()
{
	FixedVector<bool, 34> fv;
	assert(!fv.Remove(false));
	assert(!fv.Remove(true));
	assert(fv.GetIndex(false) == -1);
	assert(fv.GetIndex(true) == -1);
	assert(!fv[0]);

	// false 0~31 [0]
	for (size_t i = 0; i != 32; ++i)
	{
		fv.Add(false);
	}

	// false  0~31 [0]
	// true  32~33 [1]
	// GetSize() == 34
	fv.Add(true);
	fv.Add(true);
	assert(!fv.Get(31)); assert(fv.Get(31) == fv[31]);
	assert(fv.Get(32)); assert(fv.Get(32) == fv[32]);
	assert(fv.Get(33)); assert(fv.Get(33) == fv[33]);
	assert(fv.GetSize() == 34);

	// false 0~30, true 31 [0]
	// true  32
	// GetSize() == 33
	fv.Remove(false);
	assert(fv.Get(31));
	assert(fv.Get(32));
	assert(fv.GetSize() == 33);


	FixedVector<bool, 64> fv2;

	// 0~31  [0] 00000000 11111111 00000000 11111111
	// 32~63 [1] 00000000 11111111 00000000 11111111
	for (size_t i = 0; i != 4; ++i)
	{
		assert(fv2.Add(true)); assert(fv2.Add(true));
		assert(fv2.Add(true)); assert(fv2.Add(true));
		assert(fv2.Add(true)); assert(fv2.Add(true));
		assert(fv2.Add(true)); assert(fv2.Add(true));

		assert(fv2.Add(false)); assert(fv2.Add(false));
		assert(fv2.Add(false)); assert(fv2.Add(false));
		assert(fv2.Add(false)); assert(fv2.Add(false));
		assert(fv2.Add(false)); assert(fv2.Add(false));
	}
	assert(!fv2.Add(true));

	//  0~31 [0]   11111111 00000000 11111111 00000000
	// 32~55 [1] [00000000] 00000000 11111111 00000000
	//            ^^^^^^^^^
	//           [삭제된 요소]
	for (size_t i = 0; i != 8; ++i)
	{
		assert(fv2.Remove(true));
	}

	for (size_t i = 0; i != 56; ++i)
	{
		if (i < 8)
		{
			assert(!fv2.Get(i));
		}
		else if (i < 16)
		{
			assert(fv2.Get(i));
		}
		else if (i < 24)
		{
			assert(!fv2.Get(i));
		}
		else if (i < 32)
		{
			assert(fv2.Get(i));
		}
		else if (i < 40)
		{
			assert(!fv2.Get(i));
		}
		else if (i < 48)
		{
			assert(fv2.Get(i));
		}
		else if (i < 56)
		{
			assert(!fv2.Get(i));
		}
	}


	// 0~23 [0] [00000000] 11111111 11111111 11111111 
	for (size_t i = 0; i != 8; ++i)
	{
		assert(fv2.Remove(false));
	}
	for (size_t i = 0; i != 8; ++i)
	{
		assert(fv2.Remove(false));
	}
	for (size_t i = 0; i != 8; ++i)
	{
		assert(fv2.Remove(false));
	}
	for (size_t i = 0; i != 8; ++i)
	{
		assert(fv2.Remove(false));
	}
	assert(fv2.GetCapacity() == 64);
	assert(fv2.GetSize() == 24);
	assert(fv2.GetIndex(true) == 0);
	assert(fv2.GetIndex(false) == -1);

	for (size_t i = 0; i != 24; ++i)
	{
		assert(fv2.Remove(true));
	}
	assert(fv2.GetCapacity() == 64);
	assert(fv2.GetSize() == 0);
	assert(fv2.GetIndex(true) == -1);

	assert(!fv2.Remove(true));
	assert(!fv2.Remove(false));

	assert(fv2.GetIndex(true) == -1);
	assert(fv2.GetIndex(false) == -1);
}
void testFixedVector()
{
	// int
	FixedVector<int, 5> intVector;
	assert(intVector.GetCapacity() == 5);
	assert(intVector.GetSize() == 0);
	assert(intVector.GetIndex(0) == -1);
	assert(!intVector.Remove(0));

	for (auto i = 0; i != 5; ++i)
	{
		assert(intVector.Add(i));
		assert(intVector.GetCapacity() == 5);
		assert(intVector.GetSize() == i + 1);
		assert(intVector.Get(i) == i);
	}

	assert(intVector.Remove(1));
	assert(intVector.Get(4) == NULL);


	// int*
	FixedVector<int*, 5> fv;
	fv.Add(new int(3));

	FixedVector<int*, 5> fv2 = fv;
	assert(*fv2[0] == 3);
	assert(&fv[0] != &fv2[0]);

	fv2.Add(new int(5));
	assert(*fv2[1] == 5);
	assert(fv.GetSize() == 1);

	FixedVector<int*, 5> fv3;
	fv3.Add(new int(1));
	fv3.Add(new int(2));
	fv3.Add(new int(3));

	FixedVector<int*, 5> fv4;
	fv4 = fv3;
	assert(*fv3[0] == *fv4[0]);
	assert(&fv3[0] != &fv4[0]);
}
void testFixed()
{
	int integerArray1[] = { 23, 25, 10, -4, 70 };
	enum { INTEGER_VECTOR1_SIZE = 4 };

	FixedVector<int, 4> integerVector1;

	assert(integerVector1.GetCapacity() == INTEGER_VECTOR1_SIZE);
	assert(integerVector1.GetSize() == 0);
	std::cout << "Test FixedVector constructor: PASS" << std::endl;

	assert(integerVector1.Add(integerArray1[0]) == true);
	assert(integerVector1.Add(integerArray1[1]) == true);
	assert(integerVector1.Add(integerArray1[2]) == true);
	assert(integerVector1.Add(integerArray1[3]) == true);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
	std::cout << "Test FixedVector Add(): PASS" << std::endl;
	assert(integerVector1.Add(integerArray1[4]) == false);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE);
	std::cout << "Test FixedVector Add() - over array range: PASS" << std::endl;

	integerVector1.Add(integerArray1[0]);
	integerVector1.Add(integerArray1[1]);
	integerVector1.Add(integerArray1[2]);
	integerVector1.Add(integerArray1[3]);
	assert(integerVector1.GetIndex(integerArray1[1]) == 1);
	std::cout << "Test FixedVector GetIndex(): PASS" << std::endl;
	assert(integerVector1.Get(1) == integerArray1[1]);
	std::cout << "Test FixedVector Get(): PASS" << std::endl;
	assert(integerVector1[1] == integerArray1[1]);
	std::cout << "Test FixedVector operator[](): PASS" << std::endl;    integerVector1[0] = integerArray1[1];
	assert(integerVector1[0] == integerArray1[1]);
	integerVector1[0] = integerArray1[0];
	assert(integerVector1[0] == integerArray1[0]);
	std::cout << "Test FixedVector operator[]() - return reference: PASS" << std::endl;

	for (size_t i = 0; i < INTEGER_VECTOR1_SIZE; ++i)
	{
		assert(integerVector1.Remove(integerArray1[i]) == true);
		assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - (i + 1));
		for (size_t j = 0; j < integerVector1.GetSize(); ++j)
		{
			assert(integerVector1[j] == integerArray1[i + j + 1]);
		}
	}
	std::cout << "Test FixedVector Remove() - order not changed after remove data: PASS" << std::endl;
	assert(integerVector1.Remove(integerArray1[4]) == false);
	assert(integerVector1.GetSize() == INTEGER_VECTOR1_SIZE - 4);
	std::cout << "Test FixedVector Remove() - empty array: PASS" << std::endl;

	enum { BOOL_VECTOR1_SIZE = 7 };
	bool boolArray1[] = {
		true,    /* 0 */
		true,    /* 1 */
		true,    /* 2 */
		true,    /* 3 */
		false,    /* 4 */
		false,    /* 5 */
		true,    /* 6 */
		true    /* 7 - exceeded data */
	};
	FixedVector<bool, BOOL_VECTOR1_SIZE> boolVector1;
	assert(boolVector1.GetCapacity() == BOOL_VECTOR1_SIZE);
	assert(boolVector1.GetSize() == 0);
	std::cout << "Test FixedBoolVector constructor: PASS" << std::endl;
	std::cout << sizeof(boolVector1) << std::endl;
	assert(sizeof(boolVector1) == (sizeof(int32_t) + sizeof(size_t)));
	std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;

	assert(boolVector1.Add(boolArray1[0]) == true);
	assert(boolVector1.Add(boolArray1[1]) == true);
	assert(boolVector1.Add(boolArray1[2]) == true);
	assert(boolVector1.Add(boolArray1[3]) == true);
	assert(boolVector1.Add(boolArray1[4]) == true);
	assert(boolVector1.Add(boolArray1[5]) == true);
	assert(boolVector1.Add(boolArray1[6]) == true);
	assert(boolVector1.GetSize() == 7);
	assert(boolVector1.Get(0) == boolArray1[0]);
	assert(boolVector1.Get(1) == boolArray1[1]);
	assert(boolVector1.Get(2) == boolArray1[2]);
	assert(boolVector1.Get(3) == boolArray1[3]);
	assert(boolVector1.Get(4) == boolArray1[4]);
	assert(boolVector1.Get(5) == boolArray1[5]);
	assert(boolVector1.Get(6) == boolArray1[6]);
	std::cout << "Test FixedBoolVector Add(): PASS" << std::endl;
	assert(boolVector1.Add(boolArray1[7]) == false);
	assert(boolVector1.GetSize() == 7);
	std::cout << "Test FixedBoolVector Add() - over array range: PASS" << std::endl;

	assert(boolVector1.Remove(false) == true);
	assert(boolVector1.GetSize() == 6);
	assert(boolVector1.Get(4) == boolArray1[5]);
	assert(boolVector1.Get(5) == boolArray1[6]);
	assert(boolVector1.Remove(false) == true);
	assert(boolVector1.GetSize() == 5);
	assert(boolVector1.Get(4) == boolArray1[6]);
	std::cout << "Test FixedBoolVector Remove(): PASS" << std::endl;
	assert(boolVector1.Remove(false) == false);
	assert(boolVector1.GetSize() == 5);
	std::cout << "Test FixedBoolVector Remove() - not found: PASS" << std::endl;

	for (size_t i = 0; i < boolVector1.GetSize(); i++)
	{
		assert(boolVector1[i]);
	}
	boolVector1.Remove(true);
	assert(boolVector1.GetSize() == 4);
	for (size_t i = 0; i < boolVector1.GetSize(); i++)
	{
		assert(boolVector1[i]);
	}
	std::cout << "Test FixedBoolVector operator[]() - read: PASS" << std::endl;

	FixedVector<bool, 65> boolVector2;
	assert(sizeof(boolVector2) == ((sizeof(int32_t) * 3) + sizeof(size_t)));
	std::cout << "Test FixedBoolVector constructor - fit memroy: PASS" << std::endl;
	for (int i = 0; i < 65; i++)
	{
		boolVector2.Add(false);
	}

	assert(boolVector2.Add(true) == false);
	assert(boolVector2.GetSize() == 65);
	assert(boolVector2.GetIndex(true) == -1);
	std::cout << "Test FixedBoolVector GetIndex(): PASS" << std::endl;
}

void testJuhyuk()
{
	FixedVector<bool, 32> boolVector;
	for(int i=0;i<31;i++)
	{
		boolVector.Add(false);
	}
	boolVector.Add(true);
	assert(boolVector.GetIndex(true) == 31);
	assert(boolVector.GetIndex(false) == 0);
	assert(boolVector[31]);
	for (int i = 0; i < 31; i++)
	{
		assert(!boolVector[i]);
	}
	
}
int main()
{
	for(int i=1;i<=96;i++)
	{
		std::cout << i <<" : "<< (i-1) / 32 + 1 << std::endl;
	}
	int i1 = 23;
	int i2 = 25;
	int i3 = 10;
	int i4 = -4;
	int i5 = 70;

	FixedVector<int, 33> iv;

	assert(iv.GetCapacity() == 33);

	iv.Add(i1);
	iv.Add(i2);
	iv.Add(i3);
	iv.Add(i4);

	assert(iv.GetSize() == 4);
	assert(iv.GetIndex(i2) == 1);
	assert(iv.Get(1) == i2);
	assert(iv[1] == i2);

	bool bRemoved = iv.Remove(i5);
	assert(!bRemoved);
	assert(iv.GetSize() == 4);

	bRemoved = iv.Remove(i2);
	assert(bRemoved);
	assert(iv.GetSize() == 3);
	assert(iv.GetIndex(i2) == -1);
	FixedVector<bool, 10> v;


	assert(v.GetCapacity() == 10);

	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(true);
	v.Add(false);
	v.Add(false);
	v.Add(true);

	assert(v.GetSize() == 7);
	assert(v.Get(0));
	assert(v.Get(1));
	assert(v.Get(2));
	assert(v.Get(3));
	assert(!v.Get(4));
	assert(!v.Get(5));
	assert(v.Get(6));

	v.Remove(false);

	assert(v.GetSize() == 6);
	assert(!v.Get(4));
	assert(v.Get(5));

	v.Remove(false);

	assert(v.GetSize() == 5);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	v.Remove(true);

	assert(v.GetSize() == 4);

	for (size_t i = 0; i < v.GetSize(); i++)
	{
		assert(v[i]);
	}

	FixedVector<bool, 65> v1;

	for (int i = 0; i < 65; i++)
	{
		v1.Add(false);
	}

	assert(v1.Add(true) == false);
	assert(v1.GetSize() == 65);
	assert(v1.GetIndex(true) == -1);
	testFixedVector();
	testFixedBoolVector();
	testFixed();
	testJuhyuk();
	return 0;
}