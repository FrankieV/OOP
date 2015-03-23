#include <iostream>
#include "Time.h"


using namespace std;

int main()
{
  Time t;
  Time t2;
  int &hourRef = t.badSetHour(20); 
  t.printTime();
  
  hourRef = 30; // 30 è un valore inammissibile per l'ora! ma essendo un riferimento ad hour, quest'ultimo viene modificato.
  
  t.printTime();
  
  
  int h,m,s;
  cout << "Inserisci l'ora, i minuti e i secondi" << endl;
  cin >> h >> m >> s;
  
  t.setTime(h,m,s);
  
  t2 = t;
  
  t.printTime();
  t2.printTime();
  return 0;
}
