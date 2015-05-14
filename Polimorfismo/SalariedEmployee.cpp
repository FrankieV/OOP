#include <iostream>
#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee(const string &first, const string &last, double s): Employee(first,last)
{
  setWeeklySalary(s);
}

double SalariedEmployee::earnings() const
{
  cout << "Boss Salary: " << endl;
  return weeklySalary;
}

void SalariedEmployee::setWeeklySalary(double s)
{
  if(s > 0)
    weeklySalary = s;
  else
  weeklySalary = 0;
}

void SalariedEmployee::print() const
{
  cout << endl << "Boss: ";
  Employee::print();
}


