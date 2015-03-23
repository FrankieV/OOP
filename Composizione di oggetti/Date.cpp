#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int mm, int dy, int yr)
{
  // verificare che i dati immessi siano corretti
  month = mm;
  day = dy;
  year = yr;
}

void Date::printDate() const
{
  cout << month << " " << day << " " << year << endl;
}

void Date::setDate(int mm, int dy, int yr)
{
  month = mm;
  day = dy;
  year = yr;
}

void Date::setDate(Date &d)
{
  month = d.month;
  day = d.day;
  year = d.year;
}
