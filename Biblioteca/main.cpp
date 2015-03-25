#include <iostream>
#include "Biblioteca.h"
#include "Libro.h"

using namespace std;

int main()
{
  
 /* Libro l(1223,"Il codice da vinci", "Frank Villella");
  Biblioteca biblioteca(2);
  
  cout << "Spazio Totale Biblioteca: " << biblioteca.getCapacita() << endl;
  cout << "Spazio Rimanente in biblioteca: " << biblioteca.getSpazioRimasto() << endl;
  
  biblioteca.inserisci(l);
  cout << "Spazio Rimanente in biblioteca: " << biblioteca.getSpazioRimasto() << endl;
  
  biblioteca.print();*/
  
  int Cod_Lib;
  char *Titolo;
  char *Autore;
  
  Libro l[3];
  Biblioteca biblioteca(10);
  
  cout << "Spazio Totale Biblioteca: " << biblioteca.getCapacita() << endl;
  cout << "Spazio Rimanente in biblioteca: " << biblioteca.getSpazioRimasto() << endl;
  
  for(int i = 0; i < 3; i++)
  {
    
    cout << endl << "Inserisci il codice del libro: ";
    cin >> Cod_Lib;
    
   
    cout << endl << "Inserisci il titolo del libro: ";
    cin.ignore();
    cin.clear();
    cin.getline(Titolo,50);
    
    cout << endl << "Inserisci l'autore del libro: ";
    //cin.ignore();
    cin.clear();
    cin.getline(Autore,50);
    
    
    l[i].setLibro(Cod_Lib,Titolo,Autore);
    biblioteca.inserisci(l[i]);
    
   
  }
  
  biblioteca.print();
  cout << "Spazio Rimanente in biblioteca: " << biblioteca.getSpazioRimasto() << endl;
  
  
  
  
  return 0;

}
