//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main() {
//    int wiersze = 0;
//    fstream plik;
//    plik.open("RURL_dane2.txt", ios_base::in);
//    plik >> wiersze;
//    double** macierzA = new double* [wiersze];
//    double** macierzU = new double* [wiersze];
//    double** macierzL = new double* [wiersze];
//    for (int i = 0; i < wiersze; i++) {
//        macierzA[i] = new double[wiersze + 1];
//        macierzU[i] = new double[wiersze];
//        macierzL[i] = new double[wiersze];
//    }
//    for (int i = 0; i < wiersze; i++) {
//        for (int j = 0; j < wiersze + 1; j++) {
//            plik >> macierzA[i][j];
//            if (i == j && macierzA[i][j] == 0) {
//                plik.close();
//                cout << "Wystapilo 0 na przekatnej macierzy" << '\n';
//                return 0;
//            }
//            macierzU[i][j] = 0;
//            macierzL[i][j] = 0;
//            if(i == j)
//                macierzL[i][j] = 1;
//        }
//    }    
//    plik.close();
//
//
//    double suma;
//    for (int i = 0; i < wiersze; i++) {
//        for (int j = 0; j < wiersze; j++) {
//            suma = 0.0;
//            for (int k = 0; k <= i - 1; k++) {
//                suma += macierzL[i][k] * macierzU[k][j];
//            }
//
//            if (i <= j) {
//                macierzU[i][j] = macierzA[i][j] - suma;
//            }
//            else {
//                macierzL[i][j] = (1 / macierzU[j][j]) * (macierzA[i][j] - suma);
//            }
//
//        }
//    }
//
//    cout << "macierzA: " << endl;
//    for (int i = 0; i < wiersze; i++) {
//        for (int j = 0; j < wiersze + 1; j++) {
//            cout << macierzA[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    cout << "macierzU:" << endl;
//    for (int i = 0; i < wiersze; i++) {
//        for (int j = 0; j < wiersze; j++) {
//            cout << macierzU[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    cout << "macierzL:" << endl;
//    for (int i = 0; i < wiersze; i++) {
//        for (int j = 0; j < wiersze; j++) {
//            cout << macierzL[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    //      wektorY
//    double* wektorY = new double[wiersze];
//    wektorY[0] = macierzA[0][wiersze];
//
//    for (int i = 1; i < wiersze; i++) {
//        suma = 0.0;
//        for (int j = 0; j <= i - 1; j++) {
//            suma += macierzL[i][j] * wektorY[j];
//        }
//        wektorY[i] = macierzA[i][wiersze] - suma;
//    }
//    std::cout << "wektorY:" << endl;
//
//    for (int i = 0; i < wiersze; i++) {
//        std::cout << wektorY[i] << " ";
//    }
//    std::cout << endl;
//
//
//    double* wektorX = new double[wiersze];
//
//    wektorX[wiersze-1] = wektorY[wiersze-1] / macierzU[wiersze-1][wiersze-1];
//
//    for (int i = wiersze - 2; i >= 0; i--) {
//        suma = 0.0;
//        for (int j = i + 1; j < wiersze; j++) {
//            suma += macierzU[i][j] * wektorX[j];
//        }
//
//        wektorX[i] = (1 / macierzU[i][i]) * (wektorY[i]- suma);
//    }
//
//
//    cout << "wyniki:" << endl;
//    for (int i = 0; i < wiersze; i++) {
//        std::cout << "x" << i << ": " << wektorX[i] << endl;;
//    }
//
//    //delete
//    for (int i = 0; i < wiersze; i++) {
//        delete[] macierzA[i];
//        //delete[] macierzL[i];
//        //delete[] macierzU[i];
//    }
//    
//    //delete[] macierzU;
//    //delete[] macierzL;
//    delete[] macierzA;
//}