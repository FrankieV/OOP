#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

class SalariedEmployee: public Employee
{
    public:
        SalariedEmployee(const string &, const string &, double = 0.0);
        void setWeeklySalary(double);
        double getWeeklySalary() const;   
        virtual double earnings() const;
        virtual void print() const;
        virtual ~SalariedEmployee(){cout << "SalariedEmployee destructor" << endl;}
   
    private:
        double weeklySalary; 
};

#endif
