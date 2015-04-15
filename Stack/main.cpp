#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
  Stack<int> v;
  for(int i = 0; i < 10; i++)
  {
    v.push(i); // inserisco gli elementi nell'ordine 9,8...0
  }
  
  cout << v.top(); // stampo il primo elemento del vettore (ovvero l'ultimo inserito)
   
   v.pop(); // elimino il primo elemento dello Stack
  
  cout << v.top() << endl;
  
  cout << "Lo Stack contiene " << v.size() << " elementi" << endl;
  
  while(!v.empty())
  {
    cout << v.top();
    v.pop();
  }

}
