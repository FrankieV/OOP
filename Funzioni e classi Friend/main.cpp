#include <iostream>
#include "Time.h"
#include "Date.h"


using namespace std;

int main()
{
  Time t1;
  Date d1;
  
  setTime(t1,14,23,20); // funzione setTime della classe Time
  setTime(d1, 9,17,2004); // funzione setTime della classe Date
  
  t1.printTime();
  d1.printDate();
  
  
  return 0;
}
