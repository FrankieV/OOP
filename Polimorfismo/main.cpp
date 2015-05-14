#include <iostream>
using namespace std;
#include "CommissionWorker.h"
#include "SalariedEmployee.h"
#include <vector>

int main()
{
   // Employee e; // Employee è una classe astratta! Non posso istanziare oggetti di tipo Employee
    CommissionWorker c("Adam","Johns");
    SalariedEmployee s("Frank","Villella");
    
    c.print(); // poichè non ho effettuato l'ovverriding della funzione print nella classe CommissionWorker, verrà chiamata quella della classe base
    s.print();
    s.setWeeklySalary(250.0);
    cout<< s.getFirstName() <<  " " << s.getLastName(); // posso richiamare le funzioni della classe base
    cout << " - Salario settimanale: " << s.earnings() << "$" << endl;
    
    SalariedEmployee s2("Jhon","Smith",500.00);
    CommissionWorker c2("Peter","James",900.00,4,75.00); 
    Employee *e_ptr = &s2;
    delete e_ptr;
   e_ptr -> print(); 
    
    vector<Employee *> Impiegati;
    
    Impiegati.push_back(&c2);
   // Impiegati.push_back(&s2);
    
    for(int i = 0; i < Impiegati.size(); i++)
    {
      Impiegati[i] -> print();
      cout << Impiegati[i] -> earnings();
    }
    
    
    
   return 0;
}
