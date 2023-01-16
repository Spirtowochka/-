#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char * str;             
    int len;                
    
public:
    static const int CINLIM = 80;

    String(const char * s); 
    String();               
    String(const String &); 
    ~String();              
    int length () const { return len; }
    
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    String operator+(const  String&) const;

    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    friend String operator+(const char* st, const String& st2);
    friend String operator+(const String& st2, const char* st);

};

