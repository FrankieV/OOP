#include <iostream>
#include "Employee.h"

using namespace std;

int main()
{
 
 /*Employee e1("Frank", "Villella", 12, 2, 1994, 9, 12, 2017);*/
  
  Date birthDate(12,2,1994);
  Date hireDate(9,12,2017);
 
 Employee e1("Frank", "Villella", birthDate, hireDate);
 e1.Print();
 
 hireDate.setDate(10,1,2016);
 e1.setHireDate(hireDate);
 
 e1.Print();

 return 0;

}
