#ifndef KASA_H
#define KASA_H

#include <iostream>
#include <list>
#include "Klient.h"
using namespace std;

class Kasa
{
public:
  int num, money, tury_pracy, tury_przerwy;
  bool isopen;

  Kasa();
  Kasa(int n, int cash, bool o);
  ~Kasa();
  int getnum();
  int getmoney();
  bool isKasaopened();
  void setnum(int);
  void setmoney(int);
  void openKasa();
  void closeKasa();
  //void addtoQueue(Klient);
  //void removefromQueue();
  int get_tury_pracy();
  int get_tury_przerwy();
  bool break_ended();
  bool needs_break();
  void increment_tury_pracy();
  void clear_tury_pracy();
  void increment_tury_przerwy();
  void clear_tury_przerwy();
  void change_Kasa_status();
};

#endif