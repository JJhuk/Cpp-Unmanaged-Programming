#include "MyString.h"

namespace assignment1
{

    MyString::MyString(const char* s)
    {   
       for (m_size = 0; s[m_size] != '\0'; m_size++);
  
        m_char = new char[m_size];
        
        for (int i = 0; i < m_size; i++) 
        {
            m_char[i] = s[i];
        }
    }

    MyString::MyString(const MyString& other)
    {
        m_char = new char[other.GetLength()];
        for (int i = 0; i < other.GetLength(); i++) {
            m_char[i] = other[i];
        }
    }
   
    MyString::~MyString()
    {
        delete[] m_char;
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
}