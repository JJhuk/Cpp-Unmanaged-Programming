#include "MyString.h"

namespace assignment1
{

	MyString::MyString(const char* s)
	{
		m_size = Getcharsize(s); //사이즈 크기 구하기

		m_char = new char[m_size + 1];

		for (int i = 0; i < m_size; i++)
		{
			m_char[i] = s[i];
		}
		m_char[m_size] = '\0';
	}

	MyString::MyString(const MyString& other) : m_size(other.m_size)
	{
		m_char = new char[m_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			m_char[i] = other.m_char[i];
		}
		m_char[m_size] = '\0';
	}

	MyString::~MyString()
	{
		delete[] m_char;
		m_size = 0;
	}

	unsigned int MyString::GetLength() const
	{
		return m_size;
	}

	const char* MyString::GetCString() const
	{
		return m_char;
	}

	void MyString::Append(const char* s)
	{
		//순서가 명확하지 않은 것 같음.
		//새로 크기 잡아주고, 복사->덧붙히고 원래 delete

		const int new_size = Getcharsize(s); //새로 크기 잡아주기 위해 크기 구함
		const char* temp_char = m_char; //원래 가리키는거 다른애가 지정

		m_char = nullptr;
		m_char = new char[new_size + m_size + 1]; //원래 가리키는건 새로운 크기 저장

		for (int i = 0; i < m_size; i++)
		{
			m_char[i] = temp_char[i]; //복사
		}
		for (int i = 0; i < new_size; i++)
		{
			m_char[i + m_size] = s[i];
		}
		m_char[m_size + new_size] = '\0';


		delete[] temp_char; //원래 heap 삭제
		m_size += new_size;
	}

	void MyString::Append_Front(const char* s)
	{
		//순서가 명확하지 않은 것 같음.
		//새로 크기 잡아주고, 복사->덧붙히고 원래 delete

		const int new_size = Getcharsize(s); //새로 크기 잡아주기 위해 크기 구함
		const char* temp_char = m_char; //원래 가리키는거 다른애가 지정

		m_char = nullptr;
		m_char = new char[new_size + m_size + 1]; //원래 가리키는건 새로운 크기 저장

		for (int i = 0; i < new_size; i++)
		{
			m_char[i] = s[i]; //복사
		}
		for (int i = 0; i < m_size; i++)
		{
			m_char[i + new_size] = temp_char[i];
		}
		m_char[new_size + m_size] = '\0';
		delete[] temp_char; //원래 heap 삭제
		m_size += new_size;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		int new_size = m_size + other.m_size;
		char* new_char = new char[new_size + 1];
		for (int i = 0; i < m_size; i++)
		{
			new_char[i] = m_char[i]; //복사
		}
		for (int i = 0; i < other.m_size; i++)
		{
			new_char[i + m_size] = other.m_char[i];
		}
		new_char[new_size] = '\0';
		return MyString(new_char);
	}

	int MyString::IndexOf(const char* s)
	{
		int idx = -1;
		for (int i = 0; i < m_size; i++)
		{
			if (m_char[i] == s[0])
			{
				bool bFind = true;
				for (int j = 0; j < Getcharsize(s); j++)
				{
					if (m_char[i + j] != s[j])
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

	int MyString::LastIndexOf(const char* s)
	{
		int idx = -1;
		for (int i = 0; i < m_size; i++)
		{
			if (m_char[i] == s[0])
			{
				bool bFind = true;
				for (int j = 0; j < Getcharsize(s); j++)
				{
					if (m_char[i + j] != s[j])
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

	void MyString::Interleave(const char* s)
	{
		const int new_size = Getcharsize(s) + m_size;
		char* new_char = new char[new_size + 1];

		int idx = 0;
		int input_idx = 0;
		int m_idx = 0;

		while (s[input_idx] != '\0' || m_char[m_idx] != '\0')
		{
			if (m_char[m_idx] != '\0')
			{
				new_char[idx++] = m_char[m_idx++];
			}
			if (s[input_idx] != '\0')
			{
				new_char[idx++] = s[input_idx++];
			}
		}
		new_char[idx] = '\0';

		delete[] m_char;
		m_char = new_char;

		new_char = nullptr;

		m_size = new_size;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (m_size <= index || index < 0)
		{
			return false;
		}
		else
		{
			int temp_idx = 0;
			char* temp_char = new char[m_size];
			for (int i = 0; i < index; i++)
			{
				temp_char[temp_idx++] = m_char[i];
			}
			for (int i = index + 1; i < m_size; i++)
			{
				temp_char[temp_idx++] = m_char[i];
			}
			temp_char[m_size - 1] = '\0';
			delete[] m_char;
			m_char = temp_char;
			temp_char = nullptr;
			m_size--;

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
		if (totalLength > m_size)
		{
			int AddLength = totalLength - m_size;
			char* AddString = new char[AddLength + 1];
			for (int i = 0; i < AddLength; i++)
			{
				AddString[i] = c;
			}
			AddString[AddLength] = '\0';
			Append(AddString);
			delete[] AddString;
		}
	}

	void MyString::GetPadLeftString(unsigned int totalLength, const char c)
	{
		if (totalLength > m_size)
		{
			int AddLength = totalLength - m_size;
			char* AddString = new char[AddLength + 1];
			for (int i = 0; i < AddLength; i++)
			{
				AddString[i] = c;
			}
			AddString[AddLength] = '\0';
			Append_Front(AddString);
			delete[] AddString;
		}
	}

	void MyString::Reverse()
	{
		int left_idx = 0;
		int right_idx = m_size - 1;
		while (left_idx < right_idx)
		{
			char temp = m_char[left_idx];
			m_char[left_idx] = m_char[right_idx];
			m_char[right_idx] = temp;

			left_idx++;
			right_idx--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (m_size == rhs.m_size)
		{
			for (int i = 0; i < m_size; i++)
			{
				if (m_char[i] != rhs.m_char[i])
				{
					return false;
				}
			}
		}
		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		delete[] m_char;
		m_char = new char[rhs.m_size + 1];
		for (int i = 0; i < rhs.m_size; i++)
		{
			m_char[i] = rhs.m_char[i];
		}
		m_char[rhs.m_size] = '\0';
		m_size = rhs.m_size;

		return *this;
	}

	void MyString::ToLower()
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_char[i] >= 'A' && m_char[i] <= 'Z') //소문자이면
			{
				m_char[i] = (m_char[i] - 'A') + 'a';
			}
		}
	}

	void MyString::ToUpper()
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_char[i] >= 'a' && m_char[i] <= 'z') //소문자이면
			{
				m_char[i] = (m_char[i] - 'a') + 'A';
			}
		}
	}
	int MyString::Getcharsize(const char* s) const
	{
		int size = 0;

		for (size = 0; s[size] != '\0'; size++);

		return size;
	}
}