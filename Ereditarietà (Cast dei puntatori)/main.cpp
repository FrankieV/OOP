#include "Circle.h"
#include <iostream>

using namespace std;


int main()
{
    Circle c(2);
    cout << c; 
    
    Circle c2(3.5,5,6);
    cout << c2;
    
    Point p;
    cout << p;
    
    p = c2; // posso assegnare ad un oggetto di tipo punto un oggetto di tipo Cerhio
    cout << p;
    cout << c.getX(); // posso richiamare le funzioni membro public di Point dalla classe Cerchio
    
    //c = p  NO! non posso assegnare ad un cerchio un punto (non c'è nessuna informazione per il raggio)
    
    
    
 
    return 0;
}
