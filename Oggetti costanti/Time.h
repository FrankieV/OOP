#ifndef TIME_H
#define TIME_H

class Time
{
  public:
   Time(int = 0, int = 0, int = 0);
   void setTime(int,int,int);
   const int getHour() const;
   const int getMinute() const;
   const int getSecond() const;
   void printTime() const;
   void printTimeNoConst();
   int &badSetHour(int);
  private:
   int hour;
   int minute;
   int second;
};
#endif

