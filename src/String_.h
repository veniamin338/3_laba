#pragma one
#include <iostream>


class TStringg
{
public:
  TStringg(int len_ = 0);
  TStringg(const TStringg& p);
  ~TStringg();
  void SetLen(int len_);
  void SetStr(char* str_);
  int GetLen();
  char* GetStr();

 void Vhojdenie(TStringg& p,int** res_);// ������ ��� �������
 void SinvolVhojdenie1();
 TStringg Razbienie();
 TStringg Dubler(int k);// ������ �� �������
 void Posimvolno(int kluch,char** mas, int ** kmas, int* lenm);
 void Posimvolno(char** mas, int** kmas, int* lenm);//  ����� � ��������� ��� �������
 void ChastiySimvol();//������ ��� �������


  TStringg operator = (TStringg& p);
  TStringg operator + (TStringg& p); 
  bool operator == (TStringg& p);
  bool operator < (TStringg& p);
  bool operator > (TStringg& p);
  char operator [] (int a);

  friend std::istream& operator >> (std::istream& istr_, TStringg& p);

protected:
  int len;
  char* str;

};
std::ostream& operator << (std::ostream& ostr_, TStringg& p);