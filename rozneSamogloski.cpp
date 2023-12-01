#include <iostream>
#include <string>
using namespace std;

int roznesamogloski(string slowo) {
    int p = 0; //ustawiam p na 0 bo chce wpisywac samogloski w tablice
    string samogloski = "A¥EÊIOÓUY";
    const int size = 30;
    string tab; //to jest tablica do przechowywania samoglosek w slowie, ale niekoniecznie roznych
    int jednakowe = 0; ///chcialam zrobic licznik ktory jakos zliczy mi jednakowe wyrazy w tablicy i od p+1 odjac te liczbe
    for (char szukana : samogloski)
    {
        for (int i = 0; i < slowo.length(); ++i)
            if (szukana == slowo[i])
            {
                tab += szukana; //tworze tablice z samogloskami niekoniecznie roznymi
                p++;
            }
    }
    for (int i = 0; i < p; i++)
    {
            for (int j = i + 1; j < p; j++)
            {
                if (tab[i] == tab[j]) {
                    jednakowe++;
                    break;
                }
                  
            }
    }
    
    return p - jednakowe;
}

int main() {
    cout << "ilosc: " << roznesamogloski("KOLOKWIUM");
}