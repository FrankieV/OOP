#ifndef SINGOLA_H
#define SINGOLA_H

#include "Camera.h"

class Singola : public Camera
{
public:
	Singola(){};
	virtual ~Singola(){};
    int getPrezzo() const { return 30; }
    string getTipo() const { return "Singola";}
};

#endif
