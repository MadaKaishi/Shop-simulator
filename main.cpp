#include <iostream>
#include <tuple>
#include <string>
#include "supermarket.h"

using namespace std;

bool input_verification(string number)
{
    for (char c : number)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

int main()
{
    int kasy = -1;
    int tury = -1;
    string liczba_kas, liczba_tur;
    while (kasy < 0)
    {
        cout << "Podaj liczbę kas: ";
        cin >> liczba_kas;
        if (input_verification(liczba_kas) && stoi(liczba_kas) != 0)
        {
            kasy = stoi(liczba_kas);
        }
        else
            cout << "Podaj dodatnią liczbę całkowitą!" << endl;
    }
    while (tury < 0)
    {
        cout << "Podaj liczbę tur: ";
        cin >> liczba_tur;
        if (input_verification(liczba_tur) && stoi(liczba_tur) != 0)
        {
            tury = stoi(liczba_tur);
        }
        else
            cout << "Podaj dodatnią liczbę całkowitą!" << endl;
    }
    cout << "\n\n";
    Supermarket s(kasy, tury);
    s.Start();
    return 0;
}
