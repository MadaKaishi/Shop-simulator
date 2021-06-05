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
    void AddToCart();
    vector<tuple<Product, int>> GetCart();
    string GetAdress();
    string GetPostCode();
    string GetTown();
    void RemoveFromPurchaseList();
    int GetMoney();
    bool WantFacture();
    void GoToCheckout();
    int GetItemsAmount();
    void EmptyCart();
    void SubtractMoney(int);
};

#endif