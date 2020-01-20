#include "MyString.h"

namespace assignment1
{

    MyString::MyString(const char* s)
    {   
        m_size = Getcharsize(s); //사이즈 크기 구하기
  
        m_char = new char[m_size]; 
        
        for (int i = 0; i < m_size; i++) 
        {
            m_char[i] = s[i];
        }
    }

    MyString::MyString(const MyString& other)
    {
        m_char = new MyString(other.GetCString);
        m_size = other.Getcharsize;
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

        m_char = new char[new_size + m_size]; //원래 가리키는건 새로운 크기 저장

        for (int i = 0; i < m_size; i++)
        {
            m_char[i] = temp_char[i]; //복사
        }
        for (int i = m_size; i < new_size; i++)
        {
            m_char[i] = s[i];
        }

        delete[] temp_char; //원래 heap 삭제
        m_size += new_size;
    }

    MyString MyString::operator+(const MyString& other) const
    {

        return MyString("temporary");
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
        char* new_char = new char[new_size];

        int idx = 0;
        int input_idx = 0;
        int m_idx = 0;

        while (s[idx] == '\0' && m_char[idx] == '\0')
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

        delete[] m_char;

        m_char = new_char;
        m_size = GetLength(m_char);
    }

    bool MyString::RemoveAt(unsigned int index)
    {
        if (m_size <= index || index < 0)
        {
            return false;
        }
        else
        {
            char* temp_char = new char[m_size - 1];
            for (int i = 0; i < index; i++)
            {
                temp_char[i] = m_char[i];
            }
            for (int i = index + 1; i < m_size; i++)
            {
                temp_char[i] = m_char[i];
            }

            delete[] m_char;
            m_char = temp_char;
            m_size = Getcharsize(m_char);

            return true;
        }
    }

    void MyString::PadLeft(unsigned int totalLength)
    {
        if (totalLength > m_size)
        {

        }
    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {

    }

    void MyString::PadRight(unsigned int totalLength)
    {

    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {

    }

    void MyString::Reverse()
    {

    }

    bool MyString::operator==(const MyString& rhs) const
    {

        return false;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {

        return *this;
    }

    void MyString::ToLower()
    {

    }

    void MyString::ToUpper()
    {

    }
    int MyString::Getcharsize(const char* s) const
    {
        int size = 0;

        for (size = 0; s[size] != '\0'; size++);

        return size;
    }
}