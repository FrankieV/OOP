#include <cstring>
#include <stdlib.h>

using namespace std;

class Person
{
  public:
  Person(){age=1;}
  void InsertAge(int);
  void PrintAge();
  void InsertName(string);
  void PrintName();
  private:
  int age;
  string name;
};
