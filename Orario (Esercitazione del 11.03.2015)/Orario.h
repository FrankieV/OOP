#ifndef ORARIO_H
#define ORARIO_H

class Orario
{
  public:
   Orario(): hour(0), minute(0), second(0){ }
   Orario(int,int,int);
   void setOrario(int,int,int);
   void printOrario() const;
   void incrSec();
   void incrMin();
   void incrOra();
   bool confrontaOrario(const Orario &) const;
   
   private:
   
   int hour,minute,second;

};

#endif
