#ifndef KLIENT_H
#define KLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "Osoba.h"
#include "product.h"

using namespace std;

class Klient : public Osoba
{
private:
    vector<tuple<Product, int>> listazak;
    vector<tuple<Product, int>> items;
    int money;
    bool in_shop;
    bool want_facture;
    string adress;
    string post_code;
    string town;
    int items_amount;

public:
    Klient(string, string, int, int, bool, string = "", string = "", string = "");
    ~Klient();

    void AddToPurchaseList(Product, int);
    vector<tuple<Product, int>> ReadFromPurchaseList();
    void ReadPList();
    void AddToCart();
    vector<tuple<Product, int>> GetCart();
    void ReadCart();
    string GetAdress();
    string GetPostCode();
    string GetTown();
    void RemoveFromPurchaseList();
    int GetMoney();
    bool IsInShop();
    bool WantFacture();
    void GoToCheckout();
    int GetItemsAmount();
    void EmptyCart();
};

#endif