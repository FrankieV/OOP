#include <iostream>
#include <string>
  
using nanespace std;
 
#include <algorithm>
#include <cmath>
#include <vector>

class TriplaNumeri
{
private:
int num1;
int num2;
int num3;

public:
TriplaNumeri(int num1 = 0, int _num2 = 0,  int num3 = 0) : num1(_num1),num2(_num2), num3(_num3)

int getNuml() const { return num1; }
void setNuml(int v) { num1 = v; }

int getNum2() const { return num2}
void setNum2(int v) { num2 = v;}


int getNum3() const { return num3;}
void setNum3(int v) { num3 = v; }

boot operator==(const TriplaNumeria right) const { return num1 == right.num1 && num2 == right.num2 && num3 == right.num3; }
                                                                                   
};
#endif