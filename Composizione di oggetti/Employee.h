#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Date.h"

class Employee
{
  public:
   //Employee(char *firstName, char *lastName, int, int,int,int,int,int);
   Employee(char *firstName, char *lastName, const Date&, const Date&);
   void Print() const;
   void setBirthDate(Date&);
   void setHireDate(Date&);
  private:
   char *firstName;
   char *lastName;
   Date birthDate;
   Date hireDate;
};

#endif
