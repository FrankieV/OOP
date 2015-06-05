#ifndef TRIPLA_H
#define TRIPLA_H

#include "Camera.h"

class Tripla : public Camera
{
public:
	Tripla(){};
	virtual ~Tripla(){};
	int getPrezzo() const { return 75; }
	string getTipo() const { return "Tripla"; }
};

#endif
