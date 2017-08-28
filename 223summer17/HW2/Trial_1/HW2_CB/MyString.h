// Francis Troy Kirinhakone, 11429784
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

using std::cout;
using std::endl;

// Implement all functions declared in the MyString class below. You may
// add additional member functions/variables, but just make sure you do
// not delete or alter anything that's already been declared.

class MyString
{
//data member
private:
    char* m_str;

public:
    // Default constructor that initializes to an empty string
    // Note: there is a BIG difference between an empty string and a null string. Make
    // sure you understand this difference.
    MyString() { m_str = new char; }

// Copy constructor (part of the rule of 3)
//shallow copy
    MyString(const MyString& copyMe)
    {
        this->setStr(copyMe.m_str);
    }

// Destructor (part of the rule of 3)
    virtual ~MyString()
    {
       free(m_str);
    }

//still need implementation
    int GetAnagrams(std::vector<MyString>& candidates, std::vector<MyString>& output) const;

//does not function properly
	int IndexOf(const char* str, int startIndex = 0) const {
        MyString m_str_temp; //create temp MyString
        const char* t_str_hold = new char; //create temp const char*

        for(startIndex; startIndex < strlen(m_str); startIndex++) //iterate for length of m_str
        {
           m_str_temp = Substring(startIndex); //get substring from startindex; assign to tempMyString
           t_str_hold = m_str_temp.m_str; //access tempMyString's m_str; assign to temp const char*
           if(strcmp(t_str_hold, str) == 0) //returns startindex if substring found
           {
            cout << startIndex << endl;
            return startIndex;
           }
        }

           // cout << startIndex << endl;//returns -1 if substring not found
            //return startIndex;

      }

//done
	void bad_char_table() {
        //builds a 2d array
        int badTable[256]; //table of 256 int values
        int i = 0;
        //initialize table to -1
        for(i = 0; i < 256; i++) {
            badTable[i] = -1;
        }

        //set last character
        for(i = 0; i < strlen(m_str); i++){
        badTable[(int)m_str[i]]=i; //starting at end of string, convert character at that location to integer.  integer value corresponds to the location in badTable as well so set last location to i
        }

         for(i = 0; i < 256; i++){
            cout << badTable[i] << ",";
        }
        cout<<std::endl;

	}

//done ; //maybe strlen has to be -1 because of null terminator?
    bool IsInt() const {
        if(m_str[0] == '-') {
            for(int i = 1; i < strlen(m_str); i++) {
                if('0' < m_str[i] < '9') {return true;}
                else {return false;}
            }
        }
        else{
            for(int i = 0; i < strlen(m_str); i++){
                if('0' < m_str[i] < '9') {return true;}
                else{return false;}
            }
        }
    }

//done
    int Length() const {return strlen(m_str);}

// Assignment operator (part of the rule of 3)
    MyString& operator=(const MyString& other)
    {
        if (this != &other)
        {
            m_str = other.m_str;
        }
    }

//**needs implementation**
    void Reverse()
    {
        MyString RevString;
        int i = this->Length();
        int j = 0;

        for(i; i > 0; i--)
        {
            RevString.m_str[j] = m_str[i];

        }

    }

//Done
    void Set(const char* str)
    {
        strcpy(m_str, str);
    }

//**needs implementation**
	void Split(char c, std::vector<MyString>& outputVector) const;

//**needs implementation**
    bool StartsWith(const char* str) const
    {
        strcmp(str, this->m_str);
    }

//setters
    void setStr(char * newStr)
    {
        this->m_str = newStr;
    }
//getters
    char* getStr()
    {
        return this->m_str;
    }


    // Returns a substring starting at the specified index and going to the end of the
    // string. Relies on a proper implementation in the other Substring member function.
    MyString Substring(int startIndex) const
    {
        // This function is implemented for you

        int thisLen = Length();
        if (startIndex >= thisLen) { return MyString(); }
        return Substring(startIndex, Length() - startIndex);
    }

//Should be good?
//Done
    MyString Substring(int startIndex, int length) const //length is the length of substring
    {
        MyString temp_m_Str;
        char* temp_char_str = new char;//maybe need to allocate for number of char coming in (length)
        int i = 0;
        while(this->m_str[startIndex] != '\0') {
            temp_char_str[i] = this->m_str[startIndex];
            startIndex++;
            i++;
        }
        temp_char_str[i] = '\0';//add null terminator
        temp_m_Str.setStr(temp_char_str);

        return temp_m_Str;
    }

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
