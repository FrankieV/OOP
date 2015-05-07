#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <iostream>

using namespace std;

class Circle : public Point
{
    friend ostream &operator << (ostream &, const Circle &);
    public:
           Circle(double r = 0.0, int x = 0, int y = 0);
           void setRadius(double);
           double getRadius() const { return radius; }
    protected:
           double radius;
};

#endif
