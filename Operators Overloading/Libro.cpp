#include "Libro.h"
#include <iostream>
#include <cstring>

using namespace std;

Libro::Libro(): cod_libro(0), num_copie(1)
{
  Titolo = new char[1];
  Titolo[0] = '\0';
  Autore = new char[1];
  Autore[0] = '\0';
}


Libro::Libro(int cod, char* title, char* author, int num_copy)
{
   setCodice(cod);
   setTitolo(title);
   setAutore(author);
   setNumCopie(num_copy);
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

void Libro::setNumCopie(int n)
{
  num_copie = n;
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

void Libro::setLibro(int codice, const char* title, const char * author, int n_copy)
{
  setCodice(codice);
  setTitolo(title);
  setAutore(author);
  setNumCopie(n_copy);
}

void Libro::setLibro(const Libro &l)
{
  setCodice(l.cod_libro);
  setTitolo(l.Titolo);
  setAutore(l.Autore);
  setNumCopie(l.num_copie);
}

void Libro::printLibro() const
{
  cout << "Codice Libro: " << cod_libro << endl;
  cout << "Titolo: " << Titolo << endl;
  cout << "Autore: " << Autore << endl;
  cout << "Numero copie: " << num_copie << endl;
  cout << "----------------------------------" <<endl ;
}

istream &operator>>(istream &in, Libro & l)
{
    cout << endl << "Inserisci il codice del libro: ";
    in >> l.cod_libro;
    
   
    cout << endl << "Inserisci il titolo del libro: ";
    cin.ignore();
    cin.clear();
    in.getline(l.Titolo,50);
    
    cout << endl << "Inserisci l'autore del libro: ";
   // cin.ignore();
    cin.clear();
    in.getline(l.Autore,50);
    
    cout << endl << "Inserisci il numero di copie: ";
    in >> l.num_copie;
    
    
    return in;
}

Libro &Libro::operator++()
{
  num_copie++;
  
  return *this;
}

Libro Libro::operator+=(int n)
{
  num_copie += n;
  
  return *this;
}


