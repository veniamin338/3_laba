#include "String_.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


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

void TStringg::Vhojdenie(TStringg& p, int** res_)
{
  int kVhojdenie = 0;
  int* indexiVhojdenie = new int [kVhojdenie];
  //TStringg p(this->len);
 // std::cout << "mi ishem:" << std::endl;
  //std ::cin >> p;
  if (p.len <= len)
  {
    for (int i = 0; i < (len - p.len + 1); i++)
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
      else
        f = 0;
      if (f)
      {
        kVhojdenie += 1;
        int* tmp = new int[kVhojdenie];
        if (kVhojdenie - 1 == 0)
          tmp[0] = i;
        else
        {
          for (int l = 0; l < kVhojdenie; l++)
          {
            tmp[l] = indexiVhojdenie[l];
          }
          tmp[kVhojdenie-1] = i;
        }
    
        delete[] indexiVhojdenie;
        indexiVhojdenie = tmp;

      }
    }
  }
  *res_ = indexiVhojdenie;
  
}

void TStringg::SinvolVhojdenie1()
{
  std::cout << "mi ishem simvol:   ";
  char s = ' ';
  std::cin >> s;
  bool f = 0;
  for (int i = 0; i < len; i++)
  {
    if (str[i] == s)
    {
      std::cout << "simvol = " << s << " stoit na "<< i << " meste" << std::endl;
      f = 1;
      break;
    }
      
  }
  if (f == 0)
  {
    std::cout << "simvol = " << s << " v stroke ne naiyden!" << std::endl;
  }
}

TStringg TStringg::Razbienie()
{
  std::cout << "mi razbivaem po simvoly: ";
  char s = ' ';
  std::cin >> s;
  for (int i = 0; i < len; i++)
  {
    if ((*this).str[i] == s)
    {
      //int k = 0;
      str[i] = ' ';
    }
  }
  return *this;
}

TStringg TStringg::Dubler(int k)
{
  TStringg tmp((*this));
  for (int i = 1; i < k; i++)
  {
    (*this) = (*this) + tmp;

  }
  cout << (*this) << endl;
  return *this;
}

void TStringg::Posimvolno(int kluch,char** mas, int** kmas, int*lenm)
{
  for(int i = 0; i < len; i++)
  {
    bool f = 1;
    for (int j = 0; j < *lenm; j++)
    {
      
      if (str[i] == (*mas)[j])
      {
        (*kmas)[j] += 1;
        f = 0;
        break;
      }
      
    }
    if (f)
    {
      *lenm += 1;
      char* tmp = new char[(*lenm)];
      int* tmp2 = new int[(*lenm)];
      for (int l = 0; l < (*lenm) - 1; l++)
      {
        tmp[l] = (*mas)[l];
        tmp2[l] = (*kmas)[l];
      }
      tmp[(*lenm) - 1] = str[i];
      tmp2[(*lenm) - 1] = 1;
      delete[] (*mas);
      delete[](*kmas);
      (*mas) = tmp;
      (*kmas) = tmp2;
    }
  }
  for (int i = 0; i < (*lenm); i++)
  {
    if (kluch == 4)
    {
      cout << (*mas)[i] << ", ";
    }
    else if(kluch ==5)
    {
      cout << (*mas)[i] << " - " << (*kmas)[i] << ", ";
    }
    
  }
  cout << endl;
}

void TStringg::Posimvolno(char** mas, int** kmas, int* lenm)
{
  char* t1 = &(**mas);
  int* t2 = &(**kmas);
  int* t3 = &(*lenm);
  (*this).Posimvolno(-1, &t1, &t2, t3);
}

void TStringg::ChastiySimvol()
{
  char* t1 = new char[0];
  int* t2 = new int[0];
  int t3 = 0;
  (*this).Posimvolno(0, &t1, &t2, &t3);
  int maxk = 1;
  int index_maxk = 0;
  for (int i = 0; i < t3; i++)
  {
   
    if (t2[i] > maxk)
    {
      maxk = t2[i];
      index_maxk = i;

    }
      
  }
  cout << "chashe vstrechaetsy " << t1[index_maxk] << endl;
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
