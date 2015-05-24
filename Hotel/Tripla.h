//Definizione della classe derivata Tripla

#include "Camera.h"

#ifndef TRIPLA_H
#define TRIPLA_H

class Tripla : public Camera
{
	public:
		Tripla();
		int getPrezzo() const;
		void print() const;

	private:
		int Prezzo;
};

#endif
