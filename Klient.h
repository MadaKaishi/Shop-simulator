#ifndef KLIENT_H
#define KLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include "Osoba.h"

using namespace std;

class Klient : public Osoba
{
private:
    vector<string> listazak;
    vector<string> items;
    int money;
    bool in_shop;
    bool want_facture;
    string adress;
    string post_code;
    string town;

public:
    Klient(string, string, int, bool, string = "", string = "", string = "");
    ~Klient();

    void AddToPurchaseList(string);
    vector<string> ReadFromPurchaseList();
    void ReadPList();
    void AddToCart();
    vector<string> GetCart();
    void ReadCart();
    string GetAdress();
    string GetPostCode();
    string GetTown();

    int GetMoney();
    bool IsInShop();

    void GoToCheckout();
};

#endif