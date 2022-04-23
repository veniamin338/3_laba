#include "String_.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  TStringg a(10);
  a.SetStr("Hi! Hoy are you?");
  TStringg b(a);
  TStringg c;
  c.SetStr("im fine,thenks");
  int l = 0;
  l = a.GetLen();
  char* s = new char [256];
  s = a.GetStr();
  bool r;

  r = (a == b);
  bool bb = (a > b);
  bool mm = (b < a);
  
  b.SetStr("Hi! Hoy are xou?");
  r = (a == b);
  bb = (a > b);
  mm = (b < a);
  
  char cc = a[2];
  cout << b << endl;
  cin >> b;
  cout << b << endl;
  //c = a;
  //a.SetLen(25);
  //b.SetLen(10);
  
  delete[] s;
  return 0;
}