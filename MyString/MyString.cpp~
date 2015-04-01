#include "MyString.h"

MyString::MyString(unsigned int l)
{
	str = new char [l+1];
	str[l] = '\0';
}

MyString::MyString(const char* c)
{
	assert(c);
	str = new char[strlen(c)+1];
	strcpy(str,c);
}

MyString::MyString(const MyString& s)
{
	str = new char[s.getLength()+1];
	strcpy(str,s.str);
}

const char* MyString::cstr() const
{
	return str;
}

int MyString::getLength() const
{
	return strlen(str);
}

MyString::~MyString()
{
	delete [] str;
}

const MyString& MyString::operator=(const MyString& m)
{
	if(this == &m)
	return *this;
	if(getLength() != m.getLength())
		{
			delete [] str;
			str = new char[m.getLength()+1];
			assert(str != 0);
		}
	strcpy(str,m.str);
	return *this;
}

bool MyString::operator==(const MyString& m) const
{
	return strcmp(str,m.str) == 0;
}

bool MyString::operator<=(const MyString& m) const
{
	return strcmp(str,m.str) <= 0;
}

bool MyString::operator<(const MyString& m) const
{
	return strcmp(str,m.str) < 0;
}

bool MyString::operator>=(const MyString& m) const
{
	return strcmp(str,m.str) >= 0;
}

bool MyString::operator>(const MyString& m) const
{
	return strcmp(str,m.str) > 0;
}

const char& MyString::operator[](unsigned int i) const
{
	assert(i < getLength());
	return str[i];
}

char& MyString::operator[](unsigned int i)
{
	assert(i < getLength());
	return str[i];
}

const MyString& MyString::operator+=(const MyString& m)
{
	char * tmp = new char[getLength()+m.getLength()+1];
	strcpy(tmp,str);
	strcat(tmp,m.str);
	delete [] str;
	str = tmp;
	return *this;
}

ostream& operator<<(ostream& o, const MyString& m)
{
	o << m.str;
	return o;
}

istream& operator>>(istream& i, MyString& m)
{
	i >> m.str;
	return i;
}
