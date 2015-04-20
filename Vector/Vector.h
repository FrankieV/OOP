#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

class Vector
{
  friend ostream &operator << (ostream &, const Vector &);
  friend istream &operator >> (istream &, Vector &);
  public:
  Vector(unsigned int = 0);
  Vector(const Vector &);
  ~Vector();
  unsigned int getSize() const { return size; }
  unsigned int getCapacity() const { return capacity; }
  void push_back(int);
  void resize(unsigned);
  Vector &operator = (const Vector &);
  bool operator == (const Vector &) const;
  bool operator != (const Vector &) const;
  int operator [] (unsigned int) const;
  int &operator[] (unsigned int);
  
  
  private:
  int *vec;
  unsigned size,capacity;
  void reset();
  void copy(const Vector &);
};

#endif
