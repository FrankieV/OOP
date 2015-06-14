#ifndef GESTIONEHOTEL_H
#define GESTIONEHOTEL_H

#include <vector>
#include <iostream>
#include "Camera.h"
#include "Singola.h"
#include "Doppia.h"
#include "Tripla.h"

using namespace std;

class GestioneHotel
{
public:
	GestioneHotel() : num_singole(0), num_doppie(0), num_triple(0), num_camere_occupate(0){}
	~GestioneHotel();
	void InitHotel(unsigned int, unsigned int, unsigned int);
	void addPrenotazione();
	void removePrenotazione();
	int getNumCamere() const;
	int getNumCamereDisponibili() const;
	void getInfoAllCamere() const;
	int getRicaviTot() const;
	
private:
	vector<Camera*> Camere;
	unsigned int num_singole, num_doppie, num_triple, num_camere_occupate;
};

#endif
