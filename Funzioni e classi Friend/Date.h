#ifndef DATE_H
#define DATE_H



class Date
{
  friend class Employee; // dichiaro Employee come classe friend
  friend void setTime(Date &, int ,int ,int); // creo una funzione con lo stesso nome di quella della classe Time
  public:
   Date(int = 1, int = 1, int = 1900);
   void printDate() const;
   void setDate(int,int,int);
   void setDate(Date &);
  private:
   int month, day, year;
};

#endif
