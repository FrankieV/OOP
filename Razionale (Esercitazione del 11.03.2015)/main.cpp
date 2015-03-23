#include <iostream>
#include "Razionale.h"
 
using namespace std;
 
int main()
{
  Razionale r(5,0);
  Razionale r2(2,2);
  r.Print();
  cout << endl;
  r.Inverti();
  cout << "Dopo l'inversione: " << endl;
  r.Print();
  cout << endl << "Invoco la funzione prodotto_assegna tra ";
  r.Print();
  cout << " e ";
  r2.Print();
  r.prodottoAssegna(r2);
  cout << endl;
  r.Print();
  cout << endl;
  cout << r.Converti();
  
  /* sommaAssegna */
  
  r.setNumeratore(2);
  r.setDenominatore(2);
  r2.setNumeratore(4);
  r2.setDenominatore(2);
  
   cout << endl << "Somma tra "; 
   r.Print();
   cout << " e ";
   r2.Print();
   cout << endl;
  
  r.sommaAssegna(r2);
  
  r.setNumeratore(52);
  r.setDenominatore(8);
  r.Riduci();
  
  r.Print();
  
  r.setNumeratore(0);
  r.setDenominatore(1);
  
  r.Inverti();
  
  r.
  
  return 0;

}
 
 
