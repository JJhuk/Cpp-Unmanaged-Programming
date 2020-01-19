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
        int new_size = Getcharsize(s);
        char* temp_char = m_char;

        m_char = new char[new_size + m_size];

        for (int i = 0; i < m_size; i++)
        {
            m_char[i] = temp_char[i];
        }
        for (int i = m_size; i < new_size; i++)
        {
            m_char[i] = s[i];
        }

        delete

    }

    MyString MyString::operator+(const MyString& other) const
    {

        return MyString("temporary");
    }

    int MyString::IndexOf(const char* s)
    {

        return 0;
    }

    int MyString::LastIndexOf(const char* s)
    {
        return -1;

    }

    void MyString::Interleave(const char* s)
    {

    }

    bool MyString::RemoveAt(unsigned int index)
    {

        return false;
    }

    void MyString::PadLeft(unsigned int totalLength)
    {

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