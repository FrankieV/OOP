#ifndef LIBRO_H
#define LIBRO_H

class Libro
{
  public:
  Libro();
  Libro(const Libro &);
  Libro(int,char *, char *);
  ~Libro();
  
  void setCodice(int);
  void setTitolo(const char *);
  void setAutore(const char *);
  
  int getCodice() const;
  char* getTitolo() const;
  char* getAutore() const;
  
  void setLibro(int codice, const char*, const char *);
  void setLibro(const Libro &);
  
  void printLibro() const;
  
  private:
  int cod_libro;
  char *Titolo;
  char *Autore;
  

};

#endif
