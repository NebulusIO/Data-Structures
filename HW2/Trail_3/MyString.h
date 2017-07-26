// Francis Troy Kirinhakone
// HW #2
// CptS 223 - Advanced Data Structures

#ifndef MYSTRINGH_223
#define MYSTRINGH_223

// Do not include ANY additional header files. Your must implement the
// MyString class using only these header files.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string.h>

// Implement all functions declared in the MyString class below. You may
// add additional member functions/variables, but just make sure you do
// not delete or alter anything that's already been declared.

class MyString
{
private:
    char* m_str;

public:
    // Default constructor that initializes to an empty string
    // Note: there is a BIG difference between an empty string and a null string. Make
    // sure you understand this difference.
    MyString(){
      m_str = "";//initializes to emptystr
      //m_str = nullptr -- would initializes to null string
    }

    // Copy constructor (part of the rule of 3)
    MyString(const MyString& copyMe){ //copyMe is pass-by-reference, thus is a non-pointer type
      //deep copy
      m_str = new char[strlen(copyMe.m_str)];//allocate memory of copyMe size
      strcpy(m_str, copyMe.m_str);
      //

      //another deep copy?
      //strcpy(this->m_str, copyMe.m_str);
      //

      //shallow copy
      this->m_str = copyMe.m_str;
      //
    }

    // Destructor (part of the rule of 3)
    virtual ~MyString(){
      delete m_str;
      //free m_str;
    }

    int GetAnagrams(std::vector<MyString>& candidates, std::vector<MyString>& output) const;
	int IndexOf(const char* str, int startIndex = 0) const;
    bool IsInt() const;
    int Length() const;

    // Assignment operator (part of the rule of 3)
    MyString& operator=(const MyString& other){
      if(this != other){
        this->m_str = other.m_str;
      }
      return *this;
    }

    void Reverse();
    void Set(const char* str);
	void Split(char c, std::vector<MyString>& outputVector) const;
    bool StartsWith(const char* str) const;

    // Returns a substring starting at the specified index and going to the end of the
    // string. Relies on a proper implementation in the other Substring member function.
    MyString Substring(int startIndex) const
    {
        // This function is implemented for you

        int thisLen = Length();
        if (startIndex >= thisLen) { return MyString(); }
        return Substring(startIndex, Length() - startIndex);
    }

    MyString Substring(int startIndex, int length) const;

    void Write(std::ostream& stream) const
    {
        // This function is implemented for you

        // Your code outside of this class (in main.cpp) will need to display strings,
        // but m_str is private, as it should be to ensure that it's not changed outside
        // of the MyString member functions.
        // To display this string to std::cout, call it with the following syntax:
        //
        // strInstance.write(std::cout);
        //
        // That's the syntax for calling it from main.cpp. Avoid using std::cout in the
        // MyString class code.
        stream << m_str;
    }
};
#endif
