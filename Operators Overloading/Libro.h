#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>

using namespace std;

class Libro
{
  friend istream &operator>>(istream &, Libro &); // Overloading cin operator
  public:
  Libro();
  Libro(const Libro &);
  Libro(int,char *, char *,int);
  ~Libro();
  
  // Overloading degli operatori
  Libro &operator++(); // operatore di pre-incremento
  Libro operator+=(int);
  
  
  void setCodice(int);
  void setTitolo(const char *);
  void setAutore(const char *);
  void setNumCopie(int);
  
  int getCodice() const;
  char* getTitolo() const;
  char* getAutore() const;
  
  void setLibro(int codice, const char*, const char *, int);
  void setLibro(const Libro &);
  
  void printLibro() const;
  
  private:
  int cod_libro;
  char *Titolo;
  char *Autore;
  int num_copie;
  

};

#endif
