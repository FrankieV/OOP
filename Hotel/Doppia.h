//Definizione della classe derivata Doppia

#ifndef DOPPIA_H
#define DOPPIA_H

#include "Camera.h"

class Doppia : public Camera
{
	public:
		Doppia();
		int getPrezzo() const;
		void print() const;

	private:
		int Prezzo;
};

#endif
