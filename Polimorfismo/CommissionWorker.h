#ifndef COMMISSIONWORKER_H
#define COMMISSIONWORKER_H

#include "Employee.h"

class CommissionWorker: public Employee
{
  public:
    CommissionWorker(): Employee("vuoto","vuoto"),salary(0),commission(0),quantity(0){}
    CommissionWorker(const char *, const char *, double = 0.0, double = 0.0, int = 0);
    void setSalary(double);
    void setCommission(double);
    void setQuantity(int);
    
   virtual double earnings() const { cout << endl << "Commission Worker Salary: " << endl; return salary + commission * quantity; }
    virtual void print() const { cout << "Commission Worker: "; Employee::print(); cout << endl;} // se non effettuo l'ovverriding della funzione  print nella classe CommissionWorker, verrà chiamata quella della classe base.
    virtual ~CommissionWorker(){cout << "CommissionWorker destructor" << endl;}
  
  private:
    double salary;
    double commission;
    int quantity;
};

#endif    

