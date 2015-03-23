#include <iostream>
#include "Employee.h"
#include "Date.h"

using namespace std;


/*Employee::Employee(char *fName, char *lName, int bmonth, int bday, int byear, int hmonth, int hday, int hyear)
                  :birthDate(bmonth,bday,byear), hireDate(hmonth,hday,hyear), firstName(fName), lastName(lName)
                  { }*/
                  
Employee::Employee(char *fName, char *lName, const Date& birthd, const Date& hired)
                  :birthDate(birthd), hireDate(hired), firstName(fName), lastName(lName)
                  { }

void Employee::Print() const
{
  cout << lastName << " " << firstName << endl;
  birthDate.printDate();
  hireDate.printDate();
  cout << endl;
}

void Employee::setBirthDate(Date &bday) 
{
  birthDate.setDate(bday);
  
  /* poichè ho dichiarato la classe Employee come friend, posso accedere ai membri privati di Date */
  
  /* birthDate.month = bday.month;
     birthDate.day = bday.day;
     birthDate.year = bday.year   */
  
}

void Employee::setHireDate(Date &hday) 
{
  /*hireDate.setDate(hday); */
  hireDate.month = hday.month;  /* poichè ho dichiarato la classe Employee come friend, posso accedere ai membri privati di Date */
  hireDate.day = hday.day;
  hireDate.year = hday.year;
}
