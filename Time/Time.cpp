#include <iostream>
#include "Time.h"

using namespace std;

int &Time::badSetHour(int h)
{
  if(h >= 0 && h <=24)
  hour = h;
  
  return hour;
}

void Time::setTime(int h, int m, int s)
{
  if(h >= 0 && h <= 24)
  hour = h;
  if(m >= 0 && m< 60)
  minute = m;
  if(s >= 0 && s < 60)
  second = s;
}

void Time::printTime()
{
  cout << hour << ":" << minute << ":" << second << endl;
}

Time::Time(int h, int m, int s)
{
  if(h >= 0 && h <= 24)
  hour = h;
  if(m >= 0 && m< 60)
  minute = m;
  if(s >= 0 && s < 60)
  second = s;
}
