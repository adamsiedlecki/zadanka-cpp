#include <iostream> // biblioteka input/output
#include <cstdlib> // biblioteka do randomowych liczb

// zadanie nr 2 1

using namespace std;

/*
 * W zadaniu zakladam, ze 'glowna przekatna' jest od lewego gornego rogu tablicy do prawego dolnego,
 * gdzie ten pierwszy rog to tablicy ma index [0][0], a ten drugi [n][n]
 *
 * Wizualizauje sobie tablice dwuwymiarowa jako tablice tablic, gdzie podtablice sa wierszami
 *
 * */

int pobierzX(){
    int x = 0;
    while(x<10 || x>99){
        cout << "Podaj x :" << endl;
        cin >>x;
        cout << "x ma byc dwucyfrowe!" << endl;
    }
    return x;
}

double generujLiczbyRzeczywisteDo(int max, bool czyUjemneTez) {
    double wynik = rand() % max +1;
    if(czyUjemneTez) {
        if(rand() %10 > 5 ){
            wynik *=-1;
        }
    }
    return wynik;
}

bool czyToJestPodGlownaPrzekatna(int i, int j){
    if(i > j) { // najlepiej narysowac sobie to na kartce
        return true;
    }
    return false;
}

void wyswietlTablice(double** a, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void uruchomZadanie2() {
    cout << "Uruchamiam zad 2" << endl;

    int n = 5; // rozmiar tablicy oraz ilosc tablic
    int x = pobierzX(); // max liczba w tablicy

    // tworzymy tablice
    double** a = new double*[n];
    for(int i = 0; i < n; ++i)
        a[i] = new double[n];

    // uzupelniamy tablice
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(czyToJestPodGlownaPrzekatna(i, j)){
                a[i][j] = generujLiczbyRzeczywisteDo(9, true);
            }else {
                a[i][j] = (int) generujLiczbyRzeczywisteDo(x, false); //generuje losowe liczby z zakresu 0 do x wlacznie
            }
        }
    }
    // wyswietlamy uzupelniona tablice
    cout << "Po uzupelnieniu:" << endl;
    wyswietlTablice(a, n);

    for(int i = 0; i<n; i++){
        int liczbyUjemneCounter = 0;
        for(int j = 0; j<n; j++){
            if(a[i][j] < 0 ){
                liczbyUjemneCounter++;
            }
        }
        if(liczbyUjemneCounter > (n - liczbyUjemneCounter)){
            //przesuwamy o jedno miejsce w lewo
            double first = a[i][0];
            for(int j = 0; j<n; j++){
                a[i][j] = a[i][j+1];
                if(j == n-1) {
                    a[i][j] = first;
                }
            }
        }

    }
    // wyswietlamy uzupelniona tablice po operacji przesuwania
    cout << "Po przesunieciu:" << endl;
    wyswietlTablice(a, n);

}

