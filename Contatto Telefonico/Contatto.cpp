#include "Contatto.h"
#include "MyString.h"
#include <iostream>

using namespace std;

Contatto::Contatto():Nome("NoName"),Cognome("NoSurname"),Number("0"),Mail("yourmail@domain.xx")
{}

Contatto::Contatto(const MyString & name, const MyString &surname):Nome(name),Cognome(surname),Number("0"),Mail("yourmail@domain.xx")
{}

const MyString& Contatto::getNome() const
{
  return Nome;
}

const MyString& Contatto::getCognome() const
{
  return Cognome;
}

const MyString& Contatto::getTelNum() const
{
 return Number;
}

const MyString& Contatto::getMail() const
{
 return Mail;
}

void Contatto::setNome(const MyString & n)
{
  Nome = n;
}

void Contatto::setCognome(const MyString &s)
{
  Cognome = s;
}

void Contatto::setTelNum(const MyString &tel)
{
  Number = tel;
}

void Contatto::setMail(const MyString & m)
{
  Mail = m;
}

bool Contatto::operator<(const Contatto & c) const
{
  if(Cognome == c.Cognome)
  {
    if(Nome < c.Nome)
    return true;
  }
  
  if(Cognome < c.Cognome)
  return true;
  
  return false;
  
}

bool Contatto::operator>(const Contatto & c) const
{
  if(Cognome == c.Cognome)
  {
    if(Nome > c.Nome)
    return true;
  }
  
  if(Cognome > c.Cognome)
  return true;
  
  return false;
}

bool Contatto::operator==(const Contatto & c) const
{
  if((Nome == c.Nome) && (Cognome == c.Cognome) && (Number == c.Number) && (Mail == c.Mail))
   return true;
   
  return false;
}

bool Contatto::operator!=(const Contatto &c) const
{
  if(!(Nome == c.Nome))
  return true;
  else if(!(Cognome == c.Cognome))
  return true;
  else if(!(Number == c.Number))
  return true;
  else if(!(Mail == c.Mail))
  return true;
  
  return false;
  
}

istream &operator>>(istream & in, Contatto &c)
{
  cout << endl << "Nome: ";
  in >> c.Nome;
  cout << endl << "Cognome: ";
  in >> c.Cognome;
  cout << endl << "Numero di telefono: ";
  in >> c.Number;
  cout << endl << "Email: ";
  in >> c.Mail;
  
  return in;
}

ostream &operator<<(ostream & out, const Contatto &c)
{
 out << endl << "----------------------" << endl;
 out << endl << "Nome: " << c.Nome;
 out << endl << "Cognome: " << c.Cognome;
 out << endl << "Numero di telefono: " << c.Number;
 out << endl << "Email: " << c.Mail;
 out << endl << "----------------------" << endl;
 
 return out;
}

