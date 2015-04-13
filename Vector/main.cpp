#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{
  Vector v;
  v.push_back(2);
  v.push_back(5);
  v.push_back(4);
  v.push_back(4);
  v.push_back(6);
  
  v.resize(2);
  cout << v;
  
  cout << " " << v.getCapacity() <<  " " << v.getSize() << endl;
  
  Vector v2;
  cout << "Inserisci i numeri nel vettore, digita -1 per terminare " << endl;
  cin >> v2;
  
  cout << v2;
  
  
}
