#include <iostream>
#include <fstream>

using namespace std;

double* metodaGaussa2(int wiersze, int kolumny, double** macierz) {
    cout << "Macierz przed obliczeniami: " << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    double mnoznik = 0.0;
    double* temp = new double[kolumny];
    //double maksimum = macierz[0][0];
    int max_index = 0;
    for (int k = 0; k < wiersze; k++) {
        max_index = k;
        for (int i = k+1; i < wiersze; i++) {
            if (abs(macierz[k][max_index]) < abs(macierz[i][k])) {
                max_index = i;
                //cout << max_index << endl;
            }
        }
        for (int j = 0; j < kolumny; j++) {
            temp[j] = macierz[k][j];
            macierz[k][j] = macierz[max_index][j];
            macierz[max_index][j] = temp[j];
        }
        /*cout << "Po zamianie: " << endl;
        for (int i = 0; i < wiersze; i++) {
                for (int j = 0; j < kolumny; j++) {
                    cout << macierz[i][j] << " ";
                }
                cout << endl;
            }*/
        for (int i = k; i < wiersze ; i++) {
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
    cout << "Rozwiazania ukladu: " << endl;
    for (int i = 0; i < wiersze; i++) {
        cout << "x" << i << " = " << tabx[i] << endl;
    }
    delete[] temp;

    return tabx;
}

void metodaGaussa3(int wiersze, int kolumny, double** macierz) {
    cout << "Macierz przed obliczeniami: " << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            cout << macierz[i][j] << " ";
        }
        cout << endl;
    }
    double mnoznik = 0.0;
    double* temp = new double[wiersze];
    int max_index = 0;
    for (int k = 0; k < wiersze; k++) {
        max_index = k;
        for (int i = k + 1; i < kolumny - 1; i++) {
            if (abs(macierz[k][max_index]) < abs(macierz[k][i])) {
                max_index = i;
                
            }
        }
        for (int j = 0; j < wiersze; j++) {
            temp[j] = macierz[j][k];
            macierz[j][k] = macierz[j][max_index];
            macierz[j][max_index] = temp[j];
        }
        /*cout << "Po zamianie: " << endl;
        for (int i = 0; i < wiersze; i++) {
                for (int j = 0; j < kolumny; j++) {
                    cout << macierz[i][j] << "  ";
                }
                cout << endl;
            }*/
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
        /*cout << "po wyzerowaniu: " << endl;
        for (int i = 0; i < wiersze; i++) {
            for (int j = 0; j < kolumny; j++) {
                cout << macierz[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "------" << endl;*/
    }
    cout << "Macierz po pierwszym etapie obliczen: " << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            cout << macierz[i][j] << "  ";
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
    cout << "Rozwiazania ukladu: " << endl;
    for (int i = 0; i < wiersze; i++) {
        cout << "x" << i << " = " << tabx[i] << endl;
    }
    delete[] temp;
}

//int main()
//{
//    int wiersze = 0;
//    fstream plik;
//    plik.open("MN-6-2.txt", ios_base::in);
//    plik >> wiersze;
//    int kolumny = wiersze + 1;
//    double** macierz = new double* [wiersze];
//    for (int i = 0; i < wiersze; i++) {
//        macierz[i] = new double[kolumny];
//    }
//    for (int i = 0; i < wiersze; i++) {
//        for (int j = 0; j < kolumny; j++) {
//            plik >> macierz[i][j];
//        }
//    }
//    metodaGaussa2(wiersze, kolumny, macierz);
//    //metodaGaussa3(wiersze, kolumny, macierz);
//    plik.close();
//}