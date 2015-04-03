#ifndef CONTATTO_H
#define CONTATTO_H

#include "MyString.h"

class Contatto
{
  friend istream& operator>>(istream &,Contatto &);
  friend ostream& operator<<(ostream &, const Contatto &);
  public:
  Contatto();
  Contatto(const MyString & , const MyString &);
  
  void setNome(const MyString &);
  void setCognome(const MyString &);
  void setTelNum(const MyString &);
  void setMail(const MyString &);
  
  const MyString& getNome() const;
  const MyString& getCognome() const;
  const MyString& getTelNum() const;
  const MyString& getMail() const; 
  
  
  bool operator<(const Contatto &) const;
  bool operator>(const Contatto &) const;
  bool operator==(const Contatto &) const;
  bool operator!=(const Contatto &) const;
  
  
  
  private:
  
  MyString Nome, Cognome, Number, Mail;
 

};

#endif
