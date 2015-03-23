#include <iostream>
#include "Terna.h"

using namespace std;

int main()
{
  Terna t1(2,4,101);  // il terzo elemento viene impostato a 0 poichè 101 è un numero non valido.
  Terna t2;
  Terna t3;
  t2.setPrimo(2);
  t2.setSecondo(4);
  t2.setTerzo(0);
 
  
  t1.prodottoAssegna(t2);
  
  cout << "Terna t1 " << t1.getPrimo() << " " << t1.getSecondo() << " " << t1.getTerzo() << endl;
  
  cout << "Terna t2 " << t2.getPrimo() << " " << t2.getSecondo() << " " << t2.getTerzo() << endl;
  
   cout << "Terna t3 " << t3.getPrimo() << " " << t3.getSecondo() << " " << t3.getTerzo() << endl;
  
  if(t1.Maggiore(t2))
         cout << "La terna 1 e' piu' grande della terna 2" << endl;
   
   t2 = t1;      
   
  if(t2.Uguali(t1))
      cout << "La terna e' costituita da tutti elementi uguali";
  
   
  
  
  return 0;

}
