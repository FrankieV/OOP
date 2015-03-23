#ifndef COPPIA_H
#define COPPIA_H

class Coppia
{
   public:
     Coppia(int = 0, int = 0);
     bool uguali(const Coppia &);
     void sommaAssegna(const Coppia &);
     void stampa();
     int getPrimo();
     int getSecondo();
     void setPrimo(int);
     void setSecondo(int);
   private:
     int primo, secondo;
};

#endif
