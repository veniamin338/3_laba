#include "String_.h"
#include <iostream>

TStringg::TStringg(int len_)
{
  str = new char [len_+1];
  str[len_] = '\0';
  len = len_;
  
}

TStringg::TStringg(const TStringg& p)
{
  len = p.len;
  str = new char[len+1];
  for (int i = 0; i < len; i++)
  {
    str[i] = p.str[i];
  }
  str[len] = '\0';
}

TStringg::~TStringg()
{
  len = 0;
  delete[] str;
}

void TStringg::SetLen(int len_)
{
  if (len != 0 && len<=len_)
  {
    char* tmp = new char[len_+1];
    for (int i = 0; i < len_; i++)
    {
      if (i < len)
      {
        tmp[i] = str[i];
      }
      else
        tmp[i] = '0';
    }
    tmp[len_] = '\0';
    len = len_;
    delete[] str;
    str = tmp;
  }
  if (len > len_)
  { 
    char P = ' ';
    std::cout << "novay dlinna menshe nastoyashey! hotite ymenshit stroky?" << std::endl;
    std::cout << "Vvedite: Y - podtverdit (poteruy dannih!!)" << std::endl;
    std::cout << "         N - otmena" << std::endl;
    std::cin >> P;
    if (P == 'Y')
    {
      delete[] str;
      len = len_;
      str = new char[len_ + 1];
      str[len_] = '\0';
    }
  }
   
  
}

void TStringg::SetStr(char* str_)
{
  bool f = 1;
  int lenn = 0;
  int i = 0;
  while (f)
  {
   
    if (str_[i] != '\0')
    {
      lenn++;
      i++;
    }
    
    if (str_[i] == '\0')
    {
      f = 0;
      delete[](*this).str;
 
      str = new char [lenn+1];
      len = lenn;
      for (int i = 0; i < lenn; i++)
      {
        str[i] = str_[i];
      }
      str[lenn] = '\0';
     }
    
  }
}

int TStringg::GetLen()
{
  return len;
}

char* TStringg::GetStr()
{
  char* tmp;
  tmp = new char[len+1];
  for (int i = 0; i < len ; i++)
  {
    tmp[i] = str[i];
  }
  tmp[len] = '\0';
  return tmp;
}

int* TStringg::Vhojdenie(TStringg& p, int kVhojdenie_,int **indexiVhojdenie_)
{
  //int kVhojdenie = kVhojdenie_;
  //int* indexiVhojdenie = indexiVhojdenie_;
  if (p.len <= len)
  {
    for (int i = 0; i < len - p.len+1; i++)
    {
      bool f = 1;
      if (str[i] == p.str[0])
      {
        for (int j = 1; j < p.len; j++)
        {
          if (p.str[j] != str[i + j])
            f = 0;
        }
      }
      if (f)
      {
        kVhojdenie += 1;
        int* tmp = new int[kVhojdenie];
        for (int l = 0; l < kVhojdenie-1; l++)
        {
          tmp[l] = indexiVhojdenie[i];
        }
        tmp[kVhojdenie] = i;
        delete[] indexiVhojdenie;
        indexiVhojdenie = tmp;

      }
    }
  }
  return indexiVhojdenie;
}

TStringg TStringg::operator=(TStringg& p)
{
  len = p.len;
  str = new char[len+1];
  for (int i = 0; i < len; i++)
  {
    str[i] = p.str[i];
  }
  str[len] = '\0';
  return *this;
}

TStringg TStringg::operator+(TStringg& p)
{
  int ltmp = len + p.len;
  char* tmp = new char[ltmp + 1];
  for (int i = 0; i < ltmp; i++)
  {
    
    if (i < len)
    {
      tmp[i] = str[i];
    }
    else
    {
      tmp[i] = p.str[i - len];
    }
  } 
  tmp[ltmp] = '\0';
  str = tmp;
  len = len + p.len;
  return (*this);
}

bool TStringg::operator == (TStringg& p)
{
  bool f = 1;
  if (len == p.len)
  {
    for (int i = 0; i < len; i++)
    {     
      if (str[i] != p.str[i])
      {
        f = 0;
        break;
      }
    }
  }
  return f;
}

bool TStringg::operator < (TStringg& p)
{
  
  bool f = 0;
  if (len < p.len)
    return 1;
  else if (len > p.len)
  {
    return 0;
  }
  else
  {
    int k = 0;
    for (int i = 0; i < len; i++)
    {
      if (str[i] > p.str[i])
        return 0;
      if (str[i] == p.str[i])
        k++;
    }
    if (k != len)
      f=1;
    return f;
      
  }
    
   
  
}

bool TStringg::operator > (TStringg& p)
{
  bool f = 0;
  if (len > p.len)
    return 1;
  else if (len < p.len)
  {
    return 0;
  }
  else
  {
    int k = 0;
    for (int i = 0; i < len; i++)
    {
      if (str[i] < p.str[i])
        return 0;
      if (str[i] == p.str[i])
        k++;
    }
    if (k != len)
      f = 1;
    return f;

  }
  
}

char TStringg::operator [] (int a)
{
  if(a<len)
    return (*this).str[a];
}

std::istream& operator>>(std::istream& istr_, TStringg& p)
{
  std::cout << "Ne bolee " << p.GetLen() << " simvolov" << std::endl;
  istr_ >> p.str;
  return istr_;
  
}

std::ostream& operator<<(std::ostream& ostr_, TStringg& p)
{
  ostr_ << p.GetStr() << "\n";
  return ostr_;
}
