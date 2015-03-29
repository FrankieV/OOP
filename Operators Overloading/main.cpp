#include <iostream>
#include "Biblioteca.h"
#include "Libro.h"

using namespace std;

int main()
{
  Libro l[3];
  Biblioteca biblioteca(10);
  
  cout << "Spazio Totale Biblioteca: " << biblioteca.getCapacita() << endl;
  cout << "Spazio Rimanente in biblioteca: " << biblioteca.getSpazioRimasto() << endl;
  
  for(int i = 0; i < 3; i++)
  { 
    cin >> l[i];
   // ++l[i]; // incremento il numero di copie del libro i-esimo prima dell'inserimento
    l[i] += 1;
    biblioteca.inserisci(l[i]);  
  }
  
  // biblioteca.print();
  cout << biblioteca;
  
  cout << "Spazio Rimanente in biblioteca: " << biblioteca.getSpazioRimasto() << endl;
  
  return 0;

}
