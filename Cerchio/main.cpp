#include <iostream>
#include "Cerchio.h"

using namespace std;

int main()
{
  
  Cerchio c1;
  Cerchio c2(0,0,3); // HO IMPOSTATO X,Y = 0 E IL RAGGIO = 3
  c1.setX(4);
  cout << c1.getX() << endl;
  cout << "L'area del cerchio c1 e' " << endl;
  cout << c1.getArea() << endl;
  cout << "L'area del cerchio c2 e' " << endl;
  cout << c2.getArea() << endl; 
  
  c1 = c2;
  
  cout << "L'area del cerchio c1 e' " << endl;
  cout << c1.getArea();
  
  return 0;

}
