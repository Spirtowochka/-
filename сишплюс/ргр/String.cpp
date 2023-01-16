#include <cstring>                 
#include "String.h"              

String::String(const char * s)     
{
    len = std::strlen(s);          
    str = new char[len + 1];       
    strcpy_s(str, len + 1, s);     
                    
}

String::String()                   
{
    len = 0;
    str = new char[1];
    str[0] = '\0';                 
    
}

String::String(const String & st)
{            
    len = st.len;                    
    str = new char [len + 1];        
    strcpy_s(str, len + 1, st.str);  
}

String::~String()                     
{                       
    delete [] str;                    
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy_s(str, len + 1, st.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    strcpy_s(str, len + 1, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

String String::operator+(const String& st) const
{
   char *ptr = new char[len + st.len + 1];
   strcpy_s(ptr, len + st.len + 1, str);
   strcat_s(ptr, len + st.len + 1, st.str);
   String sum(ptr);
   delete[] ptr;
   return sum;
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

 
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os; 
}

    
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.getline(temp, String::CINLIM);   
    st = temp;
    
    return is; 
} 

String operator+(const char* st, const String& st2)
{
   char* ptr = new char[std::strlen(st) + st2.len + 1];
   strcpy_s(ptr, std::strlen(st) + st2.len + 1, st);
   strcat_s(ptr, std::strlen(st) + st2.len + 1, st2.str);
   String sum(ptr);
   delete[] ptr;
   return sum;
}

String operator+(const String& st2, const char* st)
{
   return st + st2;
}
