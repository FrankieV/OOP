#include "Tratta.h"

Tratta::Tratta(string partenza,string arrivo,int dis,TipoTreno t):da(partenza),a(arrivo),distanza(dis),tipo(t){}

string Tratta::getDa()const
{
  return da;
}

string Tratta::getA()const
{
  return a;
}

int Tratta::getDistanza()const
{
  return distanza;
}

TipoTreno Tratta::getTipo()const
{
  return tipo;
}

void Tratta::setDa(string partenza)
{
  da=partenza;
}

void Tratta::setA(string arrivo)
{
  a=arrivo;
}

void Tratta::setDistanza(int dis)
{
  distanza=dis;
}

void Tratta::setTipo(TipoTreno t)
{
  tipo=t;
}

bool Tratta::operator==(const Tratta& v) const
{
  return da==v.da && a==v.a && distanza==v.distanza && tipo==v.tipo;
}
