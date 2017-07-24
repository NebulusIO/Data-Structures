#include "MyString.h"

//MyString() -- already implemented in header

//MyString(const MyString& copyMe) -- already implemented in header

//virtual ~MyString() -- already implemented in header

int MyString::GetAnagrams(std::vector<MyString>& candidates, std::vector<MyString>& output) const{
  /*
  if vector going forwards is equal to vector going backwards for every value
  */


}
int MyString::IndexOf(const char* str, int startIndex = 0) const{
  /*

  */

  for(int i = 0; i < Length(); i++){
    for(int i2 = 0; i2 < )
  }
}//end IndexOf()

void MyString::bad_char_table(){
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

bool MyString::IsInt() const{
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
}//end IsInt()

int MyString::Length() const{
  ///shortcut
  //return strlen(m_str);
  //
  int len = 0;

  for(int i = 0; m_str[i] != NULL; i++){
    len++;
  }
  return len;
}//end Length()

MyString& MyString::operator=(const MyString& other);

void Reverse();
void Set(const char* str);
void Split(char c, std::vector<MyString>& outputVector) const;
bool StartsWith(const char* str) const;

//MyString Substring(int startIndex) -- already implemented in header

MyString MyString::Substring(int startIndex, int length) const{
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

//void Write(std::ostream& stream) const -- already implemented in header
