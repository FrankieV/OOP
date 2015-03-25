#include "Libro.h"
#include <iostream>

using namespace std;

int main()
{
   Libro l;
   l.setLibro(23934,"Il codice da perdi", "Frank");
   
   l.printLibro();
   
   Libro l2(l);
   
   l2.printLibro();
  
  return 0;
}
