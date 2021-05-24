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

    public:
    Klient(string,string,int,int);
    ~Klient();

    void AddToPurchaseList(string);
    vector<string> ReadFromPurchaseList();
    void ReadPList();
    void AddToCart();
    vector<string> GetCart();
    void ReadCart();

    int GetMoney();
    bool IsInShop();

    void GoToCheckout();


};