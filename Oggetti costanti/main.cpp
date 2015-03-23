#include <iostream>
#include "Time.h"


using namespace std;

int main()
{
  const Time noon(12,0,0);
  Time wakeUp(6,45,0);
  
  wakeUp.setTime(16,55,0);
  wakeUp.printTime();
  wakeUp.printTimeNoConst();
  
  // noon.setTime(15,33,22); Non posso richiamare una funzione non-costante su un oggetto costante
  
  noon.printTime();
 // noon.printTimeNoConst(); Non posso richiamare una funzione non-costante su un oggetto costante
  
  
  return 0;
}
