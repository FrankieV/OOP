#include "Vector.h"
#include <cassert>

Vector::Vector(unsigned int dim): size(dim),capacity(dim)
{
  if(dim == 0)
   capacity++;
   
   vec = new int[capacity];
   reset();
}

Vector::Vector(const Vector &v)
{
  copy(v);
}

void Vector::reset()
{
  for(unsigned int i = 0; i < size;i++)
  vec[i] = 0;
}

void Vector::copy(const Vector &v)
{
  size = v.size;
  capacity = v.capacity;
  vec = new int[capacity];
  for(unsigned int i = 0; i < size; i++)
  vec[i] = v.vec[i];
}

Vector::~Vector()
{
 delete [] vec;
}

void Vector::push_back(int x)
{
  if(size == capacity)
    resize(capacity*2);
  
  vec[size] = x;
  size++;
}

void Vector::resize(unsigned int dim)
{
  if(dim < size)
   size = dim;  
   
  if(dim < capacity)
  return;
  
  int *tmp = new int[dim];
  capacity = dim;
  for(int i = 0; i < size; i++)
  tmp[i] = vec[i];
   
  delete [] vec;
  vec = tmp;
}

Vector &Vector::operator = (const Vector &v)
{
  if(this != &v)
  {
    delete [] vec;
    copy(v);
  }
  
  return *this;
}

int &Vector::operator[] (unsigned int pos) 
{
  assert(pos < size);
  return vec[pos];
}

int Vector::operator[] (unsigned int pos) const
{
  assert(pos < size);
  return vec[pos];
}

ostream &operator << (ostream &out, const Vector& v)
{
  for(unsigned int i = 0; i < v.size; i++)
    out << v[i];
    
    return out;
}

istream &operator >> (istream &in, Vector &v)
{
  int num;
  in >> num;
  while( num != -1)
  {
    v.push_back(num);
    in >> num;
  }
  
  return in;
}

