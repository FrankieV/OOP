#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;
#include <cstring>
#include <cassert>

class MyString
{
	public:
		MyString(unsigned int l=0);
		MyString(const char*);
		MyString(const MyString&);
		const char* cstr() const;
		int getLength() const;
		~MyString();
		const MyString& operator=(const MyString&);
		bool operator==(const MyString&) const;
		bool operator<=(const MyString&) const;
		bool operator<(const MyString&) const;
		bool operator>=(const MyString&) const;
		bool operator>(const MyString&) const;
		const char& operator[](unsigned int) const;
		char& operator[](unsigned int);
		const MyString& operator+=(const MyString&);
		friend ostream&
		operator<<(ostream&, const MyString&);
		friend istream& operator>>(istream&, MyString&);
	private:
		char* str;
};

#endif

