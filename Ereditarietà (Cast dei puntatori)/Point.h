#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;

class Point 
{
    friend ostream &operator << (ostream &, const Point &);
public:
    Point (int = 0, int = 0);
    void setPoint(int,int);
    int getX() const { return x; }
    int getY() const { return y; }
protected:
    int x,y;
};

#endif
        
