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
  TStringg pstr;
  TStringg b1;
  TStringg d3;
  b1.SetStr("123_");
  c.SetStr("dfgdaskfjgaksdajfkl");
  pstr.SetStr("a");
  d3.SetStr("1a23adpg;apwa.t");
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

  b1.Dubler(5);// ������ ��� �������
  

  int lMas_simvolov = 0;
  char* mas_simvolov = new char[0]; // ��� ���������� ��� �������
  int* mas_simvolov_k = new int[0]; // ��� ������ �������
  b1.Posimvolno(4,&mas_simvolov, &mas_simvolov_k, &lMas_simvolov);// ��� ���������� ��� �������
  b1.Posimvolno(5, &mas_simvolov, &mas_simvolov_k, &lMas_simvolov);// ��� ������ �������

  d3.ChastiySimvol();// ������ ��� �������

  int* masVhoj;
  c.VhojdeniePodSlova(pstr, &masVhoj);// ������ ��� �������
  c.SinvolVhojdenie1();
  
  c.Razbienie();
  cout << c << endl;
  
  
  delete[] masVhoj;
  delete[] s;
  return 0;
}