#include <iostream>
#include "Biblioteca.h"
#include "Libro.h"

using namespace std;

Biblioteca::Biblioteca(int size): size_max(size), num_libri(0)
{
  if(size > 0)
  Collezione = new Libro[size];
}

Biblioteca::~Biblioteca()
{
  delete [] Collezione;
}

int Biblioteca::getCapacita() const
{
  return size_max;
}

int Biblioteca::getSpazioRimasto() const
{
  return size_max - num_libri;
}

bool Biblioteca::inserisci(const Libro &l)
{
  if(num_libri < size_max)
  {
    Collezione[num_libri].setLibro(l);
    num_libri++;
    return true;
  }
  
  return false;
}

int Biblioteca::trova(int cod) const
{
  for(int i = 0; i < num_libri; i++)
  {
    if(Collezione[i].getCodice() == cod)
     return i;
  }
  
  return -1;
}

void Biblioteca::print() const
{
  cout << "Libri presenti in biblioteca: " << endl;
  for(int i = 0; i < num_libri; i++)
    Collezione[i].printLibro();
}



