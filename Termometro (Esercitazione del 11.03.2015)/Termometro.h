#ifndef TERMOMETRO_H
#define TERMOMETRO_H

class Termometro
{
  public:
   Termometro(): attuale(0), minima(0), massima(0){}
   Termometro(int,int,int);
   void setNow(int);
   void setMin(int);
   void setMax(int);
   int getMax() const;
   int getMin() const;
   int getNow() const;
   void printTemperatura() const;
  
  private:
  
  int attuale,minima,massima;

}

#endif
