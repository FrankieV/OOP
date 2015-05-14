#include "CommissionWorker.h"
#include <iostream>

using namespace std;


CommissionWorker::CommissionWorker(const char *first, const char *last, double s, double  c, int q): Employee(first,last)
{
    setSalary(s);
    setCommission(c);
    setQuantity(q);
}

void CommissionWorker::setSalary(double s)
{
    salary = s;
}

void CommissionWorker::setCommission(double c)
{
    commission = c;
}

void CommissionWorker::setQuantity(int q)
{
    quantity = q;
}
