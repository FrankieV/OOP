#ifndef DOPPIA_H
#define DOPPIA_H

#include "Camera.h"
class Doppia : public Camera
{
public:
	Doppia(){};
	virtual ~Doppia(){};
	int getPrezzo() const { return 50; }
	string getTipo() const { return "Doppia"; }
};

#endif
