#include "Data.h"
#include <iostream>

using namespace std;

Data::Data() : day(1), month(1), year(1900)
{}

Data::Data(int dy, int mm, int yr)
{
	setDay(dy);
	setMonth(mm);
	setYear(yr);
}

void Data::setDay(int dy)
{
	if (dy >= 1 && dy <= 31)
		day = dy;
	else
		day = 1;
}

void Data::setMonth(int mm)
{
	if (mm >= 1 && mm <= 12)
		month = mm;
	else
		mm = 1;
}

void Data::setYear(int yr)
{
	year = yr;
}


int Data::getDay() const
{
	return day;
}

int Data::getMonth() const
{
	return month;
}

int Data::getYear() const
{
	return year;
}

void Data::leggiData(int dy, int mm, int yr)
{
	setYear(dy);
	setMonth(mm);
	setYear(yr);
}

void Data::printDate() const
{
	cout << day << " " << month << " " << year << endl;
}