#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(double r, int a, int b) : Point(a,b)
{
    setRadius(r);
}

void Circle::setRadius(double a)
{
    radius = a;
}

ostream &operator << (ostream & out, const Circle & c)
{
  out << "Coordinate del centro " << static_cast<Point>(c); //oppure c.x e c.y (poichè x,y sono di tipo protected)
  out << "Raggio " << c.radius << endl;
  return out;
}
