#include <iostream>
#include <fstream>

using namespace std;

double** mnozenieMacierzy(double** macierzA, double** macierzB, int wiersze);
double* mnozenieMacierzWektor(double** macierzA, double* wektorB, int wiersze);
double* dodawanieWektorow(double* wektorA, double* wektorB, int wiersze);



int main() {

    int wiersze = 0;
    fstream plik;
    plik.open("MN-8.txt", ios_base::in);
    plik >> wiersze;
    double** macierzA = new double* [wiersze];
    double** macierzU = new double* [wiersze];
    double** macierzL = new double* [wiersze];
    double** macierzD = new double* [wiersze];
    double** macierzLU = new double* [wiersze];
    double* wektorX = new double[wiersze];
    double* wektorB = new double[wiersze];

    for (int i = 0; i < wiersze; i++) {
        macierzA[i] = new double[wiersze + 1];
        macierzU[i] = new double[wiersze];
        macierzL[i] = new double[wiersze];
        macierzD[i] = new double[wiersze];
        macierzLU[i] = new double[wiersze];
    }
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < wiersze + 1; j++) {
            plik >> macierzA[i][j];
            if (i == j && macierzA[i][j] == 0) {
                plik.close();
                cout << "Wystapilo 0 na przekatnej macierzy" << '\n';
                return 0;
            }
            macierzU[i][j] = 0;
            macierzL[i][j] = 0;
            macierzD[i][j] = 0;
        }
    }
    plik.close();

    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < wiersze; j++) {
            if (i < j) {
                macierzL[i][j] = macierzA[i][j];
            }
            else if (i == j){
                macierzD[i][j] = macierzA[i][j];
            }
            else {
                macierzU[i][j] = macierzA[i][j];
            }
        }
    }

    cout << "macierzA: " << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < wiersze + 1; j++) {
            cout << macierzA[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //cout << "macierzU:" << endl;
    //for (int i = 0; i < wiersze; i++) {
    //    for (int j = 0; j < wiersze; j++) {
    //        cout << macierzU[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    //cout << "macierzL:" << endl;
    //for (int i = 0; i < wiersze; i++) {
    //    for (int j = 0; j < wiersze; j++) {
    //        cout << macierzL[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    //cout << "macierzD:" << endl;
    //for (int i = 0; i < wiersze; i++) {
    //    for (int j = 0; j < wiersze; j++) {
    //        cout << macierzD[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    //czy diagonalnie slabo dominujaca
    bool warunek = true;
    bool warunek2 = false;
    double suma;
    for (int i = 0; i < wiersze; i++) {
        suma = 0.0;
        for (int j = 0; j < wiersze; j++) {
            if (i != j) {
                suma += abs(macierzA[i][j]);
            }
        }
        // sprawdzam warunek przeciwny do aii >= suma 
        if (abs(macierzA[i][i]) < suma) {
            warunek = false;
        }
        if (abs(macierzA[i][i] > suma)) {
            warunek2 = true;
        }
    }
    if (warunek && warunek2) {
        cout << "Macierz jest diagonalnie slabo dominujaca" << endl;
    }
    else {
        cout << "Macierz nie jest diagonalnie slabo dominujaca" << endl;
    }
    cout << endl;

    // L + U
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < wiersze; j++) {
            if (i != j)
                macierzLU[i][j] = macierzA[i][j];
            else
                macierzLU[i][j] = 0;
        }
    }

    cout << "macierzL + macierzU:" << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < wiersze; j++) {
            cout << macierzLU[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // D^-1
    cout << "macierzD^-1" << endl;
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < wiersze; j++) {
            if (i == j) {
                macierzD[i][j] = pow(macierzD[i][j], -1);
            }
            cout << macierzD[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //D^-1 * LU
    double** DxLU = mnozenieMacierzy(macierzD, macierzLU, wiersze);
    //D^-1 * b
    for (int i = 0; i < wiersze; i++) {
        wektorB[i] = macierzA[i][wiersze];
    }
    double* DxB = mnozenieMacierzWektor(macierzD, wektorB, wiersze);
    //wynik to wektor
    for (int i = 0; i < wiersze; i++) {
        wektorX[i] = 0.0;
    }

    /*double roznica;

    for (int i = 1; i <= 5; i++) {
        double* DxLUxX = mnozenieMacierzWektor(DxLU, wektorX, wiersze);
        double* newX = dodawanieWektorow(DxLUxX, DxB, wiersze);

        wektorX = newX;
    }
    for (int i = 0; i < wiersze; i++) {
        cout << "x[" << i << "]: " << wektorX[i] << endl;
    }*/

    double blad = 0.000001;
    double roznica;
    int stop;
    std::cout << "Tolerancja: " << blad << endl;
    int k = 1;
    bool warunek3;
    int iteracje = 0;
    while(k) {
        warunek3 = false;

        double* DxLUxX = mnozenieMacierzWektor(DxLU, wektorX, wiersze);
        double* newX = dodawanieWektorow(DxLUxX, DxB, wiersze);

        std::cout << "Iteracja " << k << endl;
       
           stop = 0;
           for (int i = 0; i < wiersze; i++) {
               roznica = abs(newX[i] - wektorX[i]);
               std::cout << "Wartosc bledu dla x[" << i << "]: " << roznica << endl;

               if (roznica < blad) {
                   stop++;
                   std::cout << "BLAD" << endl;
               }

           }
           if (stop == wiersze || iteracje == 5) {
                warunek3 = true;
           }
        
        if (warunek3) break;
        wektorX = newX;
        k++;
        iteracje++;
    }
    cout << "\nRozwiazanie: " << endl;
    for (int i = 0; i < wiersze; i++) {
        cout << "x[" << i << "]: " << wektorX[i] << endl;
    }

    
}


double** mnozenieMacierzy(double** macierzA, double** macierzB, int wiersze)
{
    double** result = new double* [wiersze];
    double suma;
    for (int i = 0; i < wiersze; i++) {
        result[i] = new double[wiersze];
        for (int j = 0; j < wiersze; j++) {
            suma = 0.0;
            for (int k = 0; k < wiersze; k++) {
                suma += macierzA[i][k] * macierzB[k][j];
            }
            result[i][j] = suma;
        }
    }
    return result;
}

double* mnozenieMacierzWektor(double** macierzA, double* wektorB, int wiersze)
{
    double* result = new double[wiersze];
    for (int i = 0; i < wiersze; i++) {
        result[i] = 0.0;
        for (int j = 0; j < wiersze; j++) {
            result[i] += macierzA[i][j] * wektorB[j];
        }
    }
    return result;
}

double* dodawanieWektorow(double* wektorA, double* wektorB, int wiersze)
{
    double* result = new double[wiersze];
    for (int i = 0; i < wiersze; i++) {
        result[i] = -wektorA[i] + wektorB[i];
    }
    return result;
}

