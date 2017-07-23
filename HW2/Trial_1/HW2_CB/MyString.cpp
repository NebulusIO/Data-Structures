#include "MyString.h"


    // Copy constructor (part of the rule of 3)
    MyString::MyString(const MyString& copyMe)
    {
        //this = copyMe;
    }


    int MyString::GetAnagrams(std::vector<MyString>& candidates, std::vector<MyString>& output) const
    {
        /*

        */
    }
	int MyString::IndexOf(const char* str, int startIndex = 0) const
	{
        //find a substring(str) within m_str
        //walk though m_str until

        if(this->strlen < str->strlen()) {return -1};
        else if(str->)

	}
    bool IsInt() const;
    int MyString::Length() const
    {
        return strlen(this);
    }


    // Assignment operator (part of the rule of 3)
    MyString& MyString::operator=(const MyString& other)
    {
        for(int i = 0; i < other->Length(); i++)
        {

        }
    }

    void Reverse();
    void MyString::Set(const char* str)
    {
        m_str = str;
    }
	void Split(char c, std::vector<MyString>& outputVector) const;
    bool StartsWith(const char* str) const;

    MyString Substring(int startIndex, int length) const;
