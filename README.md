Symulator supermarketu:

Symulacja będzie przebiegać w sposób turowy, każda tura będzie polegała na wykonywaniu zadań przez ustalone obiekty, i będzie podzielona na kilka części:
1. Stan sklepu (co któreś tury np. co 10 tur) - zależność otwartych kas od pracowników, co ma wpływ na to ile zakupów można zrobić w danej turze.
2. Wejście losowego klienta do sklepu (klienci wczytywanie z pliku).
3. Chodzenie i zbieranie produktów z listy (1 na turę), w tej turze odbywa się też sprawdzanie czy nie ma braków przedmiotów w sklepie.
4. Faza kupowania, klient który zebrał wszystkie przedmioty z listy udaję się do kasy i ustawia w kolejce, w tej turze 1 klient może zostać obsłużony na każdą otwartą kasę.
	



Klasy:

Kasa:
- numer
- ilość pieniędzy
- obsługujący pracownik
- położenie
- otwartość
- kolejka klientów

Paragon:
- numer paragonu/id;
- lista produktów na które opiewa;
- nr kasjera oraz kasy;
- całkowita cena wszystkich produktów;

Faktura:
- numer faktury/id;
- lista produktów na które opiewa;
- dane kupującego;
- dane sprzedawcy;
- całkowita cena wszystkich produktów;
- dziedziczy po Paragon

Osoba:
- imię
- nazwisko
- id

Klient:
- lista produktów
- pieniądze
- czy klient już w sklepie
- dziedziczy po Osoba


Pracownik:
- nr kasjera
- czy pracownik ma przerwę (raz na jakiś czas)
- dziedziczy po Osoba


Produkt:
- nazwa
- id
- ilość w sklepie
- podatek

Arg wywołania: liczba kas,liczba pracowników, liczba tur

Informacje do wczytania z pliku: lista klientów, lista produktów

