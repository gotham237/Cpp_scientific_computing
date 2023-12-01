#include <iostream>
using namespace std;

//(1, 2), (2, 4), (3, 3), (4, 5), (5, 6), (6, 9), (7, 11), (8, 11)

void metodaGaussa(int wiersze, int kolumny, double** macierz, int wezly[8][2]) {
    
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

    double* tabx = new double[wiersze - 1];
    tabx[wiersze - 1] = macierz[wiersze - 1][wiersze] / macierz[wiersze - 1][wiersze - 1];
    double xn = 0.0;
    double sum = 0.0;

    for (int i = wiersze - 2; i >= 0; i--) {
        sum = 0.0;
        for (int k = i + 1; k < wiersze; k++) {
            sum += macierz[i][k] * tabx[k];
        }
        tabx[i] = (macierz[i][wiersze] - sum) / macierz[i][i];
    }   
    
    cout << "Wartosc wspolczynnikow: " << endl;
    for (int i = 0; i < wiersze; i++) {
        cout << "a[" << i << "] = " << tabx[i] << endl;
    }
    cout << "Wartosc funkcji aproksymujacej w punktach: " << endl;
    for (int i = 0; i < 8; i++) {
        double result = 0;
        for (int j = 0; j < kolumny; j++) {
            result += tabx[j] * pow(wezly[i][0], j);
        }
        cout << "x=" << wezly[i][0] << ", y=" << result << endl;
    }
}

int main(){

    int wezly[8][2] = {
        {1, 2}, {2, 4}, {3, 3}, {4, 5}, {5, 6}, {6, 9}, {7, 11}, {8, 11}
    };
    
    int m = 8; //ilosc punktow
    int n = 3; //stopien
    int w = 1; //waga 
    int* F = new int[n];
    int** g = new int* [n];
    double** macierz = new double* [n];
    for (int i = 0; i < n; i++) {
        F[i] = 0;
        g[i] = new int[n];
        macierz[i] = new double[n + 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = 0;
        }
    }
        for (int k = 0; k < n ; k++) {
            for (int j = 0; j < n + 1; j++) {
                for (int i = 0; i < m; i++) {
                    if (j == n) {
                        F[k] += pow(wezly[i][0], k) * wezly[i][1] * w;
                    }
                    else {
                        g[k][j] += pow(wezly[i][0], k) * pow(wezly[i][0], j) * w;
                    }
                }

            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                if (j == n)  macierz[i][j] = F[i];
                else macierz[i][j] = g[i][j];
            }
        }
        cout << "Liczba wezlow: " << m << endl;
        cout << "Uklad rownan(macierz): " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                cout << macierz[i][j] << "  ";
            }
            cout << endl;
        }
        
        metodaGaussa(n, n + 1, macierz, wezly);

        for (int i = 0; i < n; i++) {
            delete[] macierz[i];
            delete[] g[i];
        }
        delete[] g;
        delete[] macierz;
        delete[] F;
}

