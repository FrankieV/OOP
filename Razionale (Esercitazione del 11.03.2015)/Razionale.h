#ifndef RAZIONALE_H
#define RAZIONALE_H

class Razionale
{
   public:

   Razionale();
   Razionale(int);
   Razionale(int, int);
   int getNumeratore() const; // ok
   int getDenominatore() const; // ok
   void setNumeratore(int); // ok
   void setDenominatore(int); // ok
   double Converti() const; //ok
   void Print() const; //ok
   void Inverti(); //ok
   void prodottoAssegna(const Razionale &); // ok
   void sommaAssegna(const Razionale &); // ok
   void Riduci(); // ok
   
   private:
   
   int numeratore, denominatore;

};

#endif
