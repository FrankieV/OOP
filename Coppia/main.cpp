#include <iostream>
#include "Coppia.h"

using namespace std;

int main()
{
  Coppia c1;
  Coppia c2(2,3);
  c1.setPrimo(1);
  c1.setSecondo(2);
  c1.stampa();
  cout << " + ";
  c2.stampa();
  c1.sommaAssegna(c2);
  cout << endl;
  c1.stampa();
  
  return 0;  
}
