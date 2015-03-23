#ifndef CERCHIO_H
#define CERCHIO_H

class Cerchio
{
  public:
     int getX() { return x;}
     void setX(int); 
     double getArea();
     Cerchio(int x1, int y1, double r): x(x1), y(y1), raggio(r){}
     Cerchio(): x(0),y(0), raggio(0){}
    // Cerchio(int = 0, int = 0, double = 0.0); // è ambiguo, esiste già un altro costruttore che effettua le stesse operazioni
  private:
     int x,y;
     double raggio;
};




#endif
