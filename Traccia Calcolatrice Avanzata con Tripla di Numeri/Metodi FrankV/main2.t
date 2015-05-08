#include "CalcolatriceAvanzata.h"
#include <iostream>

using namespace std;

int main()
{
  CalcolatriceAvanzata CA;
  TriplaNumeri Tripla;
  int num;
  for(int i = 0; i < 1; i++)
  {
    cin >> num;
    Tripla.setNum1(num);
    cin >> num;
    Tripla.setNum2(num);
    cin >> num;
    Tripla.setNum3(num);
    CA.aggiungi(Tripla);
  }
  
  cout << CA.metodo4();
 
 return 0;
}
