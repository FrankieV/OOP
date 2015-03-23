#ifndef TIME_H
#define TIME_H

class Time
{
  friend void setTime(Time &, int,int,int);
  public:
   Time(int = 0, int = 0, int = 0);
   const int getHour() const;
   const int getMinute() const;
   const int getSecond() const;
   void printTime() const;
  private:
   int hour;
   int minute;
   int second;
};
#endif

