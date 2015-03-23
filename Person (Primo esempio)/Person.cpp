#include <iostream>
#include<stdlib.h>
#include<cstring>
#include "Person.h"

using namespace std;



void Person::InsertAge(int a)
{
  if(a > 0 && a < 100)
  {
    age = a;
  }
}

void Person::PrintAge()
{
  cout << "L'eta' inserita e' " << age << endl;
}


void Person::InsertName(string n)
{
  name = n;
}

void Person::PrintName()
{
  cout << "Il tuo nome e' " << name << endl;
}
