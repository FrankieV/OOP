#include <iostream>
#include "Orario.h"

using namespace std;

int main()
{
  Orario c1(3,59,68); // Inizializzo il campo second in modo errato
  c1.printOrario(); // Stampa 3:25:07
  
  Orario c2;
  cout << "c2 before inizialization " << endl;
  c2.printOrario();
  c2.setOrario(3,59,76);
  cout << "c2 after inizialization " << endl;
  c2.printOrario();
  
  if(c1.confrontaOrario(c2))
    cout << "Gli orari sono uguali" << endl;
  else
    cout << "Gli orari non coincidono" << endl;
    
  c2.incrMin();
  
  c2.printOrario();
  
  
  
  
  return 0;
}
