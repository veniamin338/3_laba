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

 int* Vhojdenie(TStringg& p, int kVhojdenie_, int **indexiVhojdenie_);

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