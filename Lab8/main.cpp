#include <cassert>
#include <bitset>
#include "FixedBoolVector.h"
#include "FixedVector.h"
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
	for (size_t i = 0; i != 32; ++i)
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

int main()
{
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

	return 0;
}