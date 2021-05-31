#ifndef PARAGON_CLASS_H
#define PARAGON_CLASS_H
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include "product.h"

using namespace std;

class Bill
{
protected:
    static int previous_number;
    int number, cashier_number, counter_number;
    string seller_street, seller_zip, seller_town, seller_name;
    vector<Product> items_list;

public:
    Bill();
    Bill(int cashier_number, int counter_number, string seller_street, string seller_zip, string seller_town, string seller_name);
    int get_number();
    int get_cashier_number();
    int get_counter_number();
    double brutto_price();
    double netto_price();
    string get_date();
    std::string get_seller_street();
    std::string get_seller_zip();
    std::string get_seller_town();
    std::string get_seller_name();
    vector<Product> get_items_list();
    void display_items_list();
    void display_bill();
    void set_cashier_number(int new_number);
    void set_counter_number(int new_number);
    void add_item(string, int, double, double);
    void remove_item(int item_index);
};

class Facture : public Bill
{
    static int previous_facture_number;
    int facture_number;
    std::string id, buyer_street, buyer_zip, buyer_town, buyer_name, place_of_issue;

public:
    int get_facture_number();
    std::string get_id();
    std::string get_buyer_street();
    std::string get_buyer_zip();
    std::string get_buyer_town();
    std::string get_buyer_name();
    std::string get_place_of_issue();
    void display_facture();
};

#endif