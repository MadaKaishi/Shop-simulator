#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <list>
#include <sstream>
#include <string>
#include <fstream>
#include <windows.h>
#include "supermarket.h"

using namespace std;

void Supermarket::entering_phaze()
{
    ofstream out("Raport.txt", ios_base::app);
    streambuf *coutbuf = cout.rdbuf();
    FazaWchodzenieWypisz();
    add_client();
    cout.rdbuf(out.rdbuf());
    cout << "Ilość klientów w sklepie: " << aktywni_klienci.size() + queue.size() << endl;
    cout << "Ilość otwartych kas: " << get_openedkasy() << endl;
    cout << "\n\n";
    cout.rdbuf(coutbuf);
    cout << "Ilość klientów w sklepie: " << aktywni_klienci.size() + queue.size() << endl;
    cout << "Ilość otwartych kas: " << get_openedkasy() << endl;
    cout << "\n\n";
}

void Supermarket::add_kasy()
{
    for (int i = 0; i < liczba_kas; i++)
    {
        int num = i + 1;
        int money = abs((random_generator(i) % 10000) + 1000);
        bool isopen = abs(random_generator(i) % 2);
        if (isopen == 1)
        {
            opened_kasy++;
        }
        Kasa new_counter(num, money, isopen);
        kasy.push_back(new_counter);
    }
    if (opened_kasy == 0)
    {
        kasy[0].openKasa();
        opened_kasy++;
    }
}

int Supermarket::get_openedkasy()
{
    int i = 0;
    for (Kasa c : kasy)
    {
        if (c.isKasaopened() == 1)
        {
            i++;
        }
    }
    opened_kasy = i;
    return opened_kasy;
}

void Supermarket::add_client()
{
    int client_index = random_generator(1) % (klienci.size());
    aktywni_klienci.push_back(klienci[client_index]);
    ofstream out("Raport.txt", ios_base::app);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout << "Klient: " << klienci[client_index].GetName() << " " << klienci[client_index].GetSurname() << " wchodzi do sklepu." << endl;
    cout.rdbuf(coutbuf);
    cout << "Klient: " << klienci[client_index].GetName() << " " << klienci[client_index].GetSurname() << " wchodzi do sklepu." << endl;
    klienci.erase(klienci.begin() + client_index);
}

void Supermarket::move_to_queue(int client_index)
{
    queue.push_back(aktywni_klienci[client_index]);
    ofstream out("Raport.txt", ios_base::app);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout << "Klient: " << aktywni_klienci[client_index].GetName() << " " << aktywni_klienci[client_index].GetSurname() << " przechodzi do kolejki do kasy" << endl;
    cout.rdbuf(coutbuf);
    cout << "Klient: " << aktywni_klienci[client_index].GetName() << " " << aktywni_klienci[client_index].GetSurname() << " przechodzi do kolejki do kasy" << endl;
    aktywni_klienci.erase(aktywni_klienci.begin() + client_index);
}

int Supermarket::random_generator(int k)
{
    unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count() + k;
    mt19937 generator(seed);
    return generator();
}

void Supermarket::load_clients_from_file()
{
    std::ifstream file("klienci.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            string nam, sur, adr, code, tow, num;
            double mon;
            int ite;
            bool fac;
            std::istringstream iss(line);
            iss >> nam >> sur >> mon >> ite >> fac >> adr >> num >> code >> tow;
            adr = adr + " " + num;
            Klient new_client(nam, sur, mon, ite, fac, adr, code, tow);
            MakeNewPurchaseList(new_client);
            klienci.push_back(new_client);
        }
        file.close();
    }
}

void Supermarket::load_products_from_file()
{
    std::ifstream file("produkty.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            string name;
            int tax, price, amount;
            std::istringstream iss(line);
            iss >> name >> amount >> tax >> price;
            Product new_product(price, tax, name, amount);
            produkty.push_back(new_product);
        }
        file.close();
    }
}

bool Supermarket::is_there_product(string name, int number)
{
    for (Product p : produkty)
    {
        if (p.name == name)
        {
            if (p.amount >= number)
            {
                p.amount -= number;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

void Supermarket::choosing_phaze()
{
    FazaWybieraniaWypisz();
    ofstream out("Raport.txt", ios_base::app);
    string name;
    int amount;
    for (long long unsigned int i = 0; i < aktywni_klienci.size(); i++)
    {
        name = get<0>(aktywni_klienci[i].ReadFromPurchaseList()[0]).name;
        amount = get<1>(aktywni_klienci[i].ReadFromPurchaseList()[0]);
        if (is_there_product(name, amount))
        {
            aktywni_klienci[i].AddToCart();
            ofstream out("Raport.txt", ios_base::app);
            streambuf *coutbuf = cout.rdbuf();
            cout.rdbuf(out.rdbuf());
            cout << aktywni_klienci[i].GetName() << " " << aktywni_klienci[i].GetSurname() << " dodał do koszyka " << amount << " " << name << endl;
            cout.rdbuf(coutbuf);
            cout << aktywni_klienci[i].GetName() << " " << aktywni_klienci[i].GetSurname() << " dodał do koszyka " << amount << " " << name << endl;
        }
        else
        {
            ofstream out("Raport.txt", ios_base::app);
            streambuf *coutbuf = cout.rdbuf();
            cout.rdbuf(out.rdbuf());
            cout << "Nie ma wystarczającej ilości danego produktu - " << name << endl;
            cout.rdbuf(coutbuf);
            cout << "Nie ma wystarczającej ilości danego produktu - " << name << endl;
            aktywni_klienci[i].RemoveFromPurchaseList();
        }
        if (aktywni_klienci[i].ReadFromPurchaseList().size() == 0)
        {
            move_to_queue(i);
        }
    }
    cout << "\n\n";
}

void Supermarket::buying_phaze()
{
    int j = 0;
    ofstream out("Raport.txt", ios_base::app);
    streambuf *coutbuf = cout.rdbuf();
    FazaKupowaniaWypisz();

    for (long long unsigned int i = 0; i < kasy.size(); i++)
    {
        Kasa &c = kasy[i];
        if (c.isKasaopened())
        {
            c.increment_tury_pracy();
            if (queue.size() > 0)
            {
                j = 1;
                Klient *client = &queue.front();
                if (client->WantFacture() == 1)
                {
                    Facture f(c.getnum(), client->GetCart(), client->GetAdress(), client->GetPostCode(), client->GetTown(), client->GetName() + " " + client->GetSurname());
                    if (client->GetMoney() >= f.brutto_price())
                    {
                        ofstream out("Raport.txt", ios_base::app);
                        streambuf *coutbuf = cout.rdbuf();
                        cout.rdbuf(out.rdbuf());
                        cout << "\nDrukowanie faktury dla klienta: " << client->GetName() << " " << client->GetSurname() << endl;
                        cout.rdbuf(coutbuf);
                        cout << "\nDrukowanie faktury dla klienta: " << client->GetName() << " " << client->GetSurname() << endl;
                        cout.rdbuf(out.rdbuf());
                        f.display_facture();
                        cout.rdbuf(coutbuf);
                        f.display_facture();
                        //Sleep(2 * 1000);
                        client->SubtractMoney(f.brutto_price());
                        c.addmoney(f.brutto_price());
                    }
                    else
                    {
                        ofstream out("Raport.txt", ios_base::app);
                        streambuf *coutbuf = cout.rdbuf();
                        cout.rdbuf(out.rdbuf());
                        cout << "Klient: " << client->GetName() << " " << client->GetSurname() << " nie ma wystarczająco pieniędzy\n";
                        cout.rdbuf(coutbuf);
                        cout << "Klient: " << client->GetName() << " " << client->GetSurname() << " nie ma wystarczająco pieniędzy\n";
                        for (long long unsigned int i = 0; i < client->GetCart().size(); i++)
                        {
                            tuple<Product, int> item = client->GetCart()[i];
                            string name = get<0>(item).name;
                            int amount = get<1>(item);
                            for (long long unsigned int i = 0; i < produkty.size(); i++)
                            {
                                if (name == produkty[i].name)
                                {
                                    int current_amount = produkty[i].amount;
                                    produkty[i].modife_amount(current_amount + amount);
                                }
                            }
                        }
                    }
                }
                else
                {
                    Bill b(c.getnum(), client->GetCart());
                    if (client->GetMoney() >= b.brutto_price())
                    {
                        ofstream out("Raport.txt", ios_base::app);
                        streambuf *coutbuf = cout.rdbuf();
                        cout.rdbuf(out.rdbuf());
                        cout << "\nDrukowanie paragonu dla klienta: " << client->GetName() << " " << client->GetSurname() << endl;
                        cout.rdbuf(coutbuf);
                        cout << "\nDrukowanie paragonu dla klienta: " << client->GetName() << " " << client->GetSurname() << endl;
                        cout.rdbuf(out.rdbuf());
                        b.display_bill();
                        cout.rdbuf(coutbuf);
                        b.display_bill();
                        client->SubtractMoney(b.brutto_price());
                        c.addmoney(b.brutto_price());
                        Sleep(2 * 1000);
                    }
                    else
                    {
                        ofstream out("Raport.txt", ios_base::app);
                        streambuf *coutbuf = cout.rdbuf();
                        cout.rdbuf(out.rdbuf());
                        cout << "Klient: " << client->GetName() << " " << client->GetSurname() << " nie ma wystarczająco pieniędzy\n";
                        cout.rdbuf(coutbuf);
                        cout << "Klient: " << client->GetName() << " " << client->GetSurname() << " nie ma wystarczająco pieniędzy\n";
                        for (long long unsigned int i = 0; i < client->GetCart().size(); i++)
                        {
                            tuple<Product, int> item = client->GetCart()[i];
                            string name = get<0>(item).name;
                            int amount = get<1>(item);
                            for (long long unsigned int i = 0; i < produkty.size(); i++)
                            {
                                if (name == produkty[i].name)
                                {
                                    int current_amount = produkty[i].amount;
                                    produkty[i].modife_amount(current_amount + amount);
                                }
                            }
                        }
                    }
                }
                MakeNewPurchaseList(*client);
                client->EmptyCart();
                klienci.push_back(*client);
                queue.pop_front();
            }
        }
        else
        {
            c.increment_tury_przerwy();
        }
        c.change_Kasa_status();
    }
    if (j == 0)
    {
        ofstream out("Raport.txt", ios_base::app);
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(out.rdbuf());
        cout << "W tej turze nikt nie finalizuje swoich zakupow. \n";
        cout.rdbuf(coutbuf);
        cout << "W tej turze nikt nie finalizuje swoich zakupow. \n";
        j = 1;
    }
    cout.rdbuf(out.rdbuf());
    cout << "\n\n";
    cout.rdbuf(coutbuf);
    cout << "\n\n";
}

void Supermarket::MakeNewPurchaseList(Klient &k)
{
    for (int i = 0; i < k.GetItemsAmount(); i++)
    {
        int amount = abs((random_generator(i) % 10)) + 2;
        int product_index = random_generator(i) % (produkty.size());
        k.AddToPurchaseList(produkty[product_index], amount);
    }
}

void Supermarket::FazaWchodzenieWypisz()
{
    ofstream out("Raport.txt", ios_base::app);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout << "Faza wchodzenia klientów do sklepu. \n\n";
    cout.rdbuf(coutbuf);
    cout << "Faza wchodzenia klientów do sklepu. \n\n";
}

void Supermarket::FazaWybieraniaWypisz()
{
    ofstream out("Raport.txt", ios_base::app);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout << "Faza wybierania produktów. \n\n";
    cout.rdbuf(coutbuf);
    cout << "Faza wybierania produktów. \n\n";
}

void Supermarket::FazaKupowaniaWypisz()
{
    ofstream out("Raport.txt", ios_base::app);
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    cout << "\n\nFaza kupowania i wychodzenia klientów ze sklepu. \n\n";
    cout.rdbuf(coutbuf);
    cout << "Faza kupowania i wychodzenia klientów ze sklepu. \n\n";
}

void Supermarket::Start()
{
    ofstream ofs1;
    ofs1.open("Raport.txt", ofstream::out | ofstream::trunc);
    ofs1.close();
    load_products_from_file();
    load_clients_from_file();
    add_kasy();
    int i = 0;
    while (i < liczba_tur)
    {
        Sleep(2 * 1000);
        ofstream out("Raport.txt", ios_base::app);
        streambuf *coutbuf = cout.rdbuf();
        entering_phaze();
        Sleep(2 * 1000);
        choosing_phaze();
        Sleep(2 * 1000);
        buying_phaze();
        i = i + 1;
        cout.rdbuf(out.rdbuf());
        cout << "Tura nr " << i << " skonczona.\n\n\n";
        cout.rdbuf(coutbuf);
        cout << "Tura nr " << i << " skonczona.\n\n\n";
    }
}