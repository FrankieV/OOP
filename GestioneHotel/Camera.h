#ifndef CAMERA_H
#define CAMERA_H

#include "Prenotazione.h"

class Camera
{
public:
	Camera() : prenotata(false){}
	virtual ~Camera(){};
	virtual int getPrezzo() const = 0; 
	virtual string getTipo() const = 0;
	bool getPrenotazione() const { return prenotata; }
	void setPrenotazione() { prenotata = true; }
	void setPrenotazione(const Prenotazione & prenotazione){p = prenotazione;}
	const Prenotazione& getInfoPrenotazione() const { return p; }
	void reset() { prenotata = false; p.eliminaDatiCliente();}
private:
	bool prenotata;
	Prenotazione p;
};

#endif
