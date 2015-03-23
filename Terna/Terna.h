#ifndef TERNA_H
#define TERNA_H

class Terna
{
   public:
      Terna(int = 0, int = 0, int = 0);
      int getPrimo();
      int getSecondo();
      int getTerzo();
      void setPrimo(int);
      void setSecondo(int);
      void setTerzo(int);
      void prodottoAssegna(const Terna &);
      bool Maggiore(const Terna &);
      bool Uguali(const Terna &);
      
      
   private:
      int primo,secondo,terzo;

};

#endif
