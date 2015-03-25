#include "Libro.h"
#include <iostream>
#include <cstring>

using namespace std;

Libro::Libro(): cod_libro(0)
{
  Titolo = new char[1];
  Titolo[0] = '\0';
  Autore = new char[1];
  Autore[0] = '\0';
}


Libro::Libro(int cod, char* title, char* author)
{
   setCodice(cod);
   setTitolo(title);
   setAutore(author);
}

Libro::~Libro()
{
  delete [] Titolo;
  delete [] Autore;

}

Libro::Libro(const Libro &l)
{
  setLibro(l);
}


void Libro::setCodice(int cod)
{
  cod_libro = cod;
} 

void Libro::setTitolo(const char* titolo)
{
  
  Titolo = new char [strlen(titolo)+1];
  strcpy(Titolo,titolo);
  
}

void Libro::setAutore(const char *author)
{
  Autore = new char [strlen(author)+1];
  strcpy(Autore,author);
}

int Libro::getCodice() const
{
  return cod_libro;
}

char* Libro::getTitolo() const
{
  return Titolo;
}

char* Libro::getAutore() const
{
  return Autore;
}

void Libro::setLibro(int codice, const char* title, const char * author)
{
  setCodice(codice);
  setTitolo(title);
  setAutore(author);
}

void Libro::setLibro(const Libro &l)
{
  setCodice(l.cod_libro);
  setTitolo(l.Titolo);
  setAutore(l.Autore);
}

void Libro::printLibro() const
{
  cout << "Codice Libro: " << cod_libro << endl;
  cout << "Titolo: " << Titolo << endl;
  cout << "Autore: " << Autore << endl;
}





