#ifndef CLASS_KASA_H
#define CLASS_KASA_H

#include <iostream>
#include <list>
#include "Klient.h"
using namespace std;

class Kasa
{
protected:
  int num;
  int money;
  bool isopen;
  std::list<Klient> queue;

public:
  Kasa(int, unsigned long int, bool);
  ~Kasa();
  int getnum();
  unsigned long int getmoney();
  bool isKasaopened();
  void setnum(int);
  void setmoney(unsigned long int);
  void openKasa();
  void closeKasa();
  void addtoQueue(Klient);
  void removefromQueue();
};

#endif