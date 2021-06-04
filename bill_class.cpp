#include <iostream>
#include <iomanip>
#include <ctime>
#include "bill_class.h"
#include "product.h"

using namespace std;

int Bill::previous_number = 0;

int Facture::previous_facture_number = 0;

Bill::Bill()
{
    counter_number = 0;
    number = previous_number + 1;
    previous_number += 1;
}

Bill::Bill(int counter_number, vector<tuple<Product, int>> items, string seller_street, string seller_zip, string seller_town, string seller_name)
{
    this->seller_name = seller_name;
    this->seller_street = seller_street;
    this->seller_town = seller_town;
    this->seller_zip = seller_zip;
    this->counter_number = counter_number;
    this->items = items;
    number = previous_number + 1;
    previous_number += 1;
}

double Bill::brutto_price()
{
    double total_price = 0;
    int items_list_size = items.size();
    for (int i = 0; i < items_list_size; i++)
    {
        Product item = get<0>(items[i]);
        double tax;
        int amount = get<1>(items[i]);
        double price = item.price;
        tax = item.tax_class / 100;
        total_price += amount * (price + (price * tax));
    }
    return total_price;
}

int Bill::get_number()
{
    return number;
}

int Bill::get_counter_number()
{
    return counter_number;
}

void Bill::display_items_list()
{
    cout << fixed;
    cout << setw(5) << left << "No." << setw(4) << left << "|"
         << setw(34) << left << "Product name:" << setw(4) << left << "|"
         << setw(12) << left << "Quantity:" << setw(4) << left << "|"
         << setw(14) << left << "Unit price:" << setw(4) << left << "|"
         << setw(15) << right << "Total Price (with VAT):" << endl;
    for (int i = 0; i < 104; i++)
    {
        cout << "-";
    }
    cout << endl;
    int items_list_size = items.size();
    for (int i = 0; i < items_list_size; i++)
    {
        Product item = get<0>(items[i]);
        string name = item.name;
        int amount = get<1>(items[i]);
        double price, total_price, tax;
        tax = item.tax_class / 100;
        price = item.price + item.price * tax;
        total_price = price * amount;
        cout << setw(5) << left << i + 1 << setw(4) << left << "|"
             << setw(34) << left << name << setw(4) << left << "|"
             << setw(9) << right << amount << setw(4) << right << "|"
             << setw(14) << right << setprecision(2) << price << setw(4) << right << "|"
             << setw(25) << right << setprecision(2) << total_price << endl;
    }
    for (int i = 0; i < 104; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void Bill::display_bill()
{
    string seller_name = get_seller_name();
    string town_zip = get_seller_zip() + ", " + get_seller_town();
    cout << "\n\n\n";
    cout << "Bill nr and date: " << get_number() << "  " << get_date() << "\n\n";
    cout << string((80 - get_seller_name().size()) / 2, ' ') << seller_name << endl;
    cout << string((80 - get_seller_name().size()) / 2, ' ') << get_seller_street() << endl;
    cout << string((80 - get_seller_name().size()) / 2, ' ') << town_zip << "\n";
    cout << "Counter number: " << setw(60) << left << get_counter_number() << "\n\n";
    display_items_list();
    cout << fixed;
    cout << setw(84) << right << "TOTAL: " << setw(16) << right << setprecision(2) << brutto_price() << " PLN" << endl;
}

void Bill::set_counter_number(int new_number)
{
    counter_number = new_number;
}

void Bill::remove_item(int item_index)
{
    items.erase(items.begin() + item_index);
}

string Bill::get_date()
{
    string date;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    date = to_string(tm.tm_mday) + "/" + to_string(tm.tm_mon + 1) + "/" + to_string(tm.tm_year + 1900);
    return date;
}

string Bill::get_seller_street()
{
    return seller_street;
}

string Bill::get_seller_zip()
{
    return seller_zip;
}

string Bill::get_seller_town()
{
    return seller_town;
}

string Bill::get_seller_name()
{
    return seller_name;
}

int Facture::get_facture_number()
{
    return facture_number;
}

string Facture::get_id()
{
    string id;
    string date;
    date = get_date();
    facture_number = get_facture_number();
    id = to_string(facture_number) + "/" + date;
    return id;
}

string Facture::get_buyer_street()
{
    return buyer_street;
}

string Facture::get_buyer_zip()
{
    return buyer_zip;
}

string Facture::get_buyer_town()
{
    return buyer_town;
}

string Facture::get_buyer_name()
{
    return buyer_name;
}

string Facture::get_place_of_issue()
{
    return place_of_issue;
}

Facture::Facture(int counter_number, vector<tuple<Product, int>> items, string buyer_street, string buyer_zip, string buyer_town, string buyer_name, string seller_street, string seller_zip, string seller_town, string seller_name)
{
    this->seller_name = seller_name;
    this->seller_street = seller_street;
    this->seller_town = seller_town;
    this->seller_zip = seller_zip;
    this->place_of_issue = seller_town;
    this->buyer_street = buyer_street;
    this->buyer_zip = buyer_zip;
    this->buyer_town = buyer_town;
    this->buyer_name = buyer_name;
    this->counter_number = counter_number;
    this->items = items;
    facture_number = previous_facture_number + 1;
    previous_facture_number += 1;
}

void Facture::display_items_list()
{
    cout << fixed;
    cout << setw(5) << left << "No." << setw(4) << left << "|"
         << setw(34) << left << "Product name:" << setw(4) << left << "|"
         << setw(12) << left << "Quantity:" << setw(4) << left << "|"
         << setw(14) << left << "Unit price:" << setw(4) << left << "|"
         << setw(14) << left << "Netto price:" << setw(4) << left << "|"
         << setw(14) << left << "Unit price:" << setw(4) << left << "|"
         << setw(15) << right << "Total Price (with VAT):" << endl;
    for (int i = 0; i < 104; i++)
    {
        cout << "-";
    }
    cout << endl;
    int items_list_size = items.size();
    for (int i = 0; i < items_list_size; i++)
    {
        Product item = get<0>(items[i]);
        string name = item.name;
        int amount = get<1>(items[i]);
        double price, total_price, tax;
        tax = item.tax_class / 100;
        price = item.price + item.price * tax;
        total_price = price * amount;
        cout << setw(5) << left << i + 1 << setw(4) << left << "|"
             << setw(34) << left << name << setw(4) << left << "|"
             << setw(9) << right << amount << setw(4) << right << "|"
             << setw(14) << right << setprecision(2) << price << setw(4) << right << "|"
             << setw(25) << right << setprecision(2) << total_price << endl;
    }
    for (int i = 0; i < 104; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void Facture::display_facture()
{
    cout << "\n\n\n";
    cout << "Facture nr/date: " << setw(60) << left << get_id() << get_place_of_issue() << " " << get_date() << "\n\n";
    cout << setw(60) << left << "Seller:"
         << "Buyer:" << endl;
    cout << setw(60) << left << get_seller_name() << get_buyer_name() << endl;
    cout << setw(60) << left << get_seller_street() << get_buyer_street() << endl;
    cout << get_seller_zip() << ", " << setw(52) << left << get_seller_town() << get_buyer_zip() << ", " << get_buyer_town() << "\n\n\n";
    display_items_list();
    cout << fixed;
    cout << setw(84) << right << "TOTAL: " << setw(16) << right << setprecision(2) << brutto_price() << " PLN" << endl;
}