#include <iostream>

// zadanie nr 1 1

using namespace std;

bool czyDwucyfrowa (int liczba) {
    if (liczba >=10 && liczba <=99) {
        return true;
    }
    return false;
}

bool czyPodzielnaPrzezMOrazWiekszaOdPoprzednikow (int liczba, int m, int poprzednik, int poprzednikPoprzednika) {
    if (liczba % m == 0 && liczba > poprzednik && liczba > poprzednikPoprzednika) {
        return true;
    }
    return false;
}

void uruchomZadanie1() {
    cout << "Uruchamiam zad 1" << endl;

    int m = 3;
    int dwucyfroweSuma = 0;
    int dwucyfroweCount = 0;
    int liczba = 0;
    int poprzednik = 0;
    int poprzednikPoprzednika = 0;
    do {
        poprzednikPoprzednika = poprzednik;
        poprzednik = liczba;

        cin >> liczba;
        if(czyDwucyfrowa(liczba)) {
            dwucyfroweSuma += liczba;
            dwucyfroweCount++;
        }
    } while (!czyPodzielnaPrzezMOrazWiekszaOdPoprzednikow(liczba, m, poprzednik, poprzednikPoprzednika));

    if (dwucyfroweCount != 0) {
        int srednia = dwucyfroweSuma / dwucyfroweCount;
        cout << "SREDNIA: "<< srednia << endl;
    } else {
        cout << "nie policze sredniej, bo musialbym dzielic przez zero " << endl;
    }
}