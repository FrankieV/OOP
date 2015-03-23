#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
  Person person;
  int age;
  cin >> age;
  person.InsertAge(age);
  person.PrintAge();
  string name;
  cin >> name;
  person.InsertName(name);
  person.PrintName();
  
  return 0;
}

