#include "MyString.h"

namespace assignment1
{
	MyString::MyString() :mSize(0), mChar(nullptr)
	{

	}

	MyString::MyString(const char* s)
	{
		if (s != nullptr)
		{
			mSize = Getcharsize(s); //사이즈 크기 구하기

			mChar = new char[mSize + 1];

			for (int i = 0; i < mSize; i++)
			{
				mChar[i] = s[i];
			}
			mChar[mSize] = '\0';
		}
		else
		{
			mSize = 0;
			mChar = nullptr;
		}
	}

	MyString::MyString(const MyString& other) : mSize(other.mSize)
	{
		mChar = new char[mSize + 1];
		for (int i = 0; i < mSize; i++)
		{
			mChar[i] = other.mChar[i];
		}
		mChar[mSize] = '\0';
	}

	MyString::~MyString()
	{
		delete[] mChar;
		mSize = 0;
	}

	unsigned int MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		return mChar;
	}

	void MyString::Append(const char* s)
	{
		if (s != nullptr && s != "")
		{
			const int NEW_SIZE = Getcharsize(s);
			char* tempChar = mChar;

			mChar = nullptr;
			mChar = new char[NEW_SIZE + mSize + 1];

			for (int i = 0; i < mSize; i++)
			{
				mChar[i] = tempChar[i];
			}
			for (int i = 0; i < NEW_SIZE; i++)
			{
				mChar[i + mSize] = s[i];
			}
			mChar[mSize + NEW_SIZE] = '\0';


			delete[] tempChar;
			tempChar = nullptr;
			mSize += NEW_SIZE;
		}
	}

	void MyString::AppendFront(const char* s)
	{
		if (s != nullptr)
		{
			const int NEW_SIZE = Getcharsize(s);
			char* tempChar = mChar;

			mChar = nullptr;
			mChar = new char[NEW_SIZE + mSize + 1];

			for (int i = 0; i < NEW_SIZE; i++)
			{
				mChar[i] = s[i]; //복사
			}
			for (int i = 0; i < mSize; i++)
			{
				mChar[i + NEW_SIZE] = tempChar[i];
			}
			mChar[NEW_SIZE + mSize] = '\0';
			delete[] tempChar;
			mSize += NEW_SIZE;
		}
	}

	MyString MyString::operator+(const MyString& other) const
	{
		const int NEW_SIZE = mSize + other.mSize;
		char* newChar = new char[NEW_SIZE + 1];
		for (int i = 0; i < mSize; i++)
		{
			newChar[i] = mChar[i]; //복사
		}
		for (int i = 0; i < other.mSize; i++)
		{
			newChar[i + mSize] = other.mChar[i];
		}
		newChar[NEW_SIZE] = '\0';
		return MyString(newChar);
	}

	int MyString::IndexOf(const char* s)
	{
		if (s != nullptr)
		{
			if (s == "")
			{
				return 0;
			}
			else
			{
				int idx = -1;
				for (int i = 0; i < mSize; i++)
				{
					if (mChar[i] == s[0])
					{
						bool bFind = true;
						for (int j = 0; j < Getcharsize(s); j++)
						{
							if (mChar[i + j] != s[j])
							{
								bFind = false;
								break;
							}
						}
						if (bFind)
						{
							idx = i;
							break;
						}
					}
				}
				return idx;
			}
		}
		else
		{
			return -1;
		}
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s != nullptr)
		{
			if (s == "")
			{
				return mSize;
			}
			else
			{
				int idx = -1;
				for (int i = 0; i < mSize; i++)
				{
					if (mChar[i] == s[0])
					{
						bool bFind = true;
						for (int j = 0; j < Getcharsize(s); j++)
						{
							if (mChar[i + j] != s[j])
							{
								bFind = false;
								break;
							}
						}
						if (bFind)
						{
							idx = i;
						}
					}
				}
				return idx;
			}
		}
		else
		{
			return -1;
		}
	}

	void MyString::Interleave(const char* s)
	{
		if (s != nullptr && s != "")
		{
			const int NEW_SIZE = Getcharsize(s) + mSize;
			char* newChar = new char[NEW_SIZE + 1];

			int idx = 0;
			int input_idx = 0;
			int m_idx = 0;

			while (s[input_idx] != '\0' || mChar[m_idx] != '\0')
			{
				if (mChar[m_idx] != '\0')
				{
					newChar[idx++] = mChar[m_idx++];
				}
				if (s[input_idx] != '\0')
				{
					newChar[idx++] = s[input_idx++];
				}
			}
			newChar[idx] = '\0';

			delete[] mChar;
			mChar = newChar;

			newChar = nullptr;

			mSize = NEW_SIZE;
		}
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (mSize <= index || index < 0)
		{
			return false;
		}
		else
		{
			int temp_idx = 0;
			char* tempChar = new char[mSize];
			for (int i = 0; i < index; i++)
			{
				tempChar[temp_idx++] = mChar[i];
			}
			for (int i = index + 1; i < mSize; i++)
			{
				tempChar[temp_idx++] = mChar[i];
			}
			tempChar[mSize - 1] = '\0';
			delete[] mChar;
			mChar = tempChar;
			tempChar = nullptr;
			mSize--;

			return true;
		}
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		GetPadLeftString(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		GetPadLeftString(totalLength, c);
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		GetPadRightString(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		GetPadRightString(totalLength, c);
	}

	void MyString::GetPadRightString(unsigned int totalLength, const char c)
	{
		if (totalLength > mSize)
		{
			int addLength = totalLength - mSize;
			char* addString = new char[addLength + 1];
			for (int i = 0; i < addLength; i++)
			{
				addString[i] = c;
			}
			addString[addLength] = '\0';
			Append(addString);
			delete[] addString;
		}
	}

	void MyString::GetPadLeftString(unsigned int totalLength, const char c)
	{
		if (totalLength > mSize)
		{
			int addLength = totalLength - mSize;
			char* addString = new char[addLength + 1];
			for (int i = 0; i < addLength; i++)
			{
				addString[i] = c;
			}
			addString[addLength] = '\0';
			AppendFront(addString);
			delete[] addString;
		}
	}

	void MyString::Reverse()
	{
		int leftIdx = 0;
		int rightIdx = mSize - 1;
		while (leftIdx < rightIdx)
		{
			char temp = mChar[leftIdx];
			mChar[leftIdx] = mChar[rightIdx];
			mChar[rightIdx] = temp;

			leftIdx++;
			rightIdx--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (mSize == rhs.mSize)
		{
			for (int i = 0; i < mSize; i++)
			{
				if (mChar[i] != rhs.mChar[i])
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		delete[] mChar;
		mChar = new char[rhs.mSize + 1];
		for (int i = 0; i < rhs.mSize; i++)
		{
			mChar[i] = rhs.mChar[i];
		}
		mChar[rhs.mSize] = '\0';
		mSize = rhs.mSize;

		return *this;
	}

	void MyString::ToLower()
	{
		for (int i = 0; i < mSize; i++)
		{
			if (mChar[i] >= 'A' && mChar[i] <= 'Z') //소문자이면
			{
				mChar[i] = (mChar[i] - 'A') + 'a';
			}
		}
	}

	void MyString::ToUpper()
	{
		for (int i = 0; i < mSize; i++)
		{
			if (mChar[i] >= 'a' && mChar[i] <= 'z') //소문자이면
			{
				mChar[i] = (mChar[i] - 'a') + 'A';
			}
		}
	}
	int MyString::Getcharsize(const char* s) const
	{
		int size = 0;
		if (s != nullptr)
		{
			for (size = 0; s[size] != '\0'; size++);
		}
		return size;
	}
}