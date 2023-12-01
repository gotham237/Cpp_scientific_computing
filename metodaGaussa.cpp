#include <iostream>
#include <fstream>

using namespace std;

void metodaGaussa(int wiersze, int kolumny, double** macierz) {
    cout << "Macierz przed obliczeniami: " << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    double mnoznik = 0.0;
    for (int k = 0; k < wiersze; k++) {
        for (int i = k; i < wiersze - 1; i++) {
            if (macierz[i][i] != 0.0) {
                mnoznik = macierz[i + 1][k] / macierz[k][k];
                for (int j = k; j < kolumny; j++) {
                    macierz[i + 1][j] -= macierz[k][j] * mnoznik;
                }
            }
            else {
                cout << "Nie mozna dzeilic przez 0" << endl;
                break;
            }
        }
    }
    cout << "Macierz po pierwszym etapie obliczen: " << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }

    double *tabx = new double[wiersze -1];
    tabx[wiersze - 1] = macierz[wiersze - 1][wiersze] / macierz[wiersze - 1][wiersze - 1];
    double xn = 0.0;
    double sum = 0.0;
    
    for (int i = wiersze - 2; i >= 0; i--) {
        sum = 0.0;
        for (int k = i+1; k < wiersze; k++) {
            sum += macierz[i][k]* tabx[k];
        }
        tabx[i] = (macierz[i][wiersze]- sum) / macierz[i][i];
    }
    cout << "Rozwiazania ukladu: " << endl;
    for (int i = 0; i < wiersze; i++) {
        cout << "x" << i << " = " << tabx[i] << endl;
    }
}

int main()
{
    int wiersze = 0;
    fstream plik;
    plik.open("MN-8.txt", ios_base::in);
    plik >> wiersze;
    int kolumny = wiersze + 1;
    double** macierz = new double* [wiersze];
    for (int i = 0; i < wiersze; i++) {
        macierz[i] = new double[kolumny];
    }
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            plik >> macierz[i][j];
        }
    }
    metodaGaussa(wiersze, kolumny, macierz);
    plik.close();
}