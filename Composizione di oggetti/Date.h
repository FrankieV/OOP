#ifndef DATE_H
#define DATE_H



class Date
{
  friend class Employee; // dichiaro Employee come classe friend
  public:
   Date(int = 1, int = 1, int = 1900);
   void printDate() const;
   void setDate(int,int,int);
   void setDate(Date &);
  private:
   int month, day, year;
};

#endif
