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

void Time::printTime() const
{
  cout << hour << ":" << minute << ":" << second << endl;
}

void Time::printTimeNoConst()
{
  cout << hour << ":" << minute << ":" << second << endl;
}


const int Time::getHour() const
{
  return hour;
}

const int Time::getMinute() const
{
  return minute;
}

const int Time::getSecond() const
{
  return second;
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
