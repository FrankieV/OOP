#include <iostream>
#include "Orario.h"

using namespace std;

Orario::Orario(int h, int m, int s)
{
  setOrario(h,m,s);
}

void Orario::setOrario(int h, int m, int s)
{
  if(h >= 0 && h <= 24)
    hour = h;
  else
    hour = 0;
  
  if(m >= 0 && m <= 59)
    minute = m;
  else
    minute = 0;
   
  if(s >= 0 && s <=59)
    second = s;
  else
    second = 0;
    
}

void Orario::incrOra()
{
   if(hour < 24)
    hour += 1;
   else
    hour = 0;
}

void Orario::incrMin()
{
   if(minute < 59)
    minute += 1;
   else
    minute = 0;
}

void Orario::incrSec()
{
   if(second < 59)
    second += 1;
   else
    second = 0;
}

void Orario::printOrario() const
{
  cout << hour << ":" << minute << ":" << second << endl;
}

bool Orario::confrontaOrario(const Orario & o) const
{
   if(hour == o.hour && minute == o.minute && second == o.second)
         return true;
         
    return false;
}
