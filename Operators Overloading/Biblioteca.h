#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H


#include "Libro.h"
#include <iostream>

using namespace std;

class Biblioteca
{
 friend ostream &operator<<(ostream &, const Biblioteca &);
 friend istream &operator>>(istream &, Biblioteca &);
 public:
 Biblioteca(const int);
 ~Biblioteca();
 int getCapacita() const;
 int getSpazioRimasto() const;
 bool inserisci(const Libro &);
 int trova(int) const;
 // void print() const;
 
 private:
 
 const int size_max;
 int num_libri;
 Libro *Collezione;
 
};

#endif
