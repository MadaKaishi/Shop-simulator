#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

using namespace std;

class Product
{
public:
    int amount;
    double tax_class, price;
    string name;
    Product()
    {
        amount = 0;
        tax_class = 0;
        price = 0;
        name = "";
    }
    Product(double p, double t, string n, int a = 0)
    {
        amount = a;
        price = p;
        tax_class = t;
        name = n;
    }

    void modife_amount(int new_amount)
    {
        amount = new_amount;
    }
};

#endif