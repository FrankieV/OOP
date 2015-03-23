#ifndef TIME_H
#define TIME_H

class Time
{
  public:
   Time(int = 0, int = 0, int = 0);
   void setTime(int,int,int);
   void printTime();
   int &badSetHour(int);
  private:
   int hour;
   int minute;
   int second;
};
#endif

