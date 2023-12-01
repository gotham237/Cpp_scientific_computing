#include <iostream>
#include <cmath>
using namespace std;

double silnia(double n)
{
    if (n == 0) return 1;
    else return n * silnia(n - 1);
}

double dwumian_newtona(double n, double k) {
    return silnia(n) / (silnia(k) * silnia(n - k));
}

double wielomian_czynnikowy(double x, double n) {
    double result = 1.0;
    for (int j = 0; j <= n - 1; j++) {
        result *= (x - j);
    }
    return result;
}

double wielomian_grama(double k, double q, int n) {
    double suma = 0.0;
    if (q == 0) {
        return 1;
    }
    for (int s = 0; s <= k; s++) {
        suma += pow(-1, s) * dwumian_newtona(k, s) * dwumian_newtona(k + s, s)
            * wielomian_czynnikowy(q, s) / wielomian_czynnikowy(n, s);
    }
    return suma;
}

double ck(int k, int n) {
    double result = 0.0;
    for (int i = 0; i <= n; i++) {
        result += pow(wielomian_grama(k, i, n), 2);
    }
    return result;
}

double sk(int k, int n, double wezly[][2]) {
    double result = 0.0;
    for (int i = 0; i <= n; i++) {
        result += wezly[i][1] * wielomian_grama(k, i, n);
    }
    return result;
}

int main() {
    double wezly[8][2] = {
        {1, 2}, {2, 4}, {3, 3}, {4, 5}, {5, 6}, {6, 9}, {7, 11}, {8, 11}
    };

    double x ;
    cout << "Podaj x: ";
    cin >> x;
    cout << "\n";
    int n = 8; //liczba punktow
    int m = 2; // stopien wielomianu
    double h = 1;
    //double q = x - wezly[0][0]/h;
    cout << "Liczba wezlow: " << n << endl;

    cout << "Wspolczynniki: " << endl;
    for (int k = 0; k <= m; k++) {
        cout << "ck[" << k << "]: " << ck(k, n - 1) << endl;
        cout << "sk[" << k << "]: " << sk(k, n - 1, wezly) << endl;
    }
    double y;
    double q;
    //double Fk = wielomian_grama(m, q, n);
    for (int i = 0; i < n; i++) {
        y = 0.0;
        q = (wezly[i][0] - wezly[0][0]) / h;
        for (int k = 0; k <= m; k++) {
            y += sk(k, n -1, wezly) / ck(k, n-1) * wielomian_grama(k, q, n-1);
        }
        cout << "x[" << i << "]: " << wezly[i][0] << ", y[" << i << "]: " << y << endl;
    }
    
        y = 0.0;
        q = (x - wezly[0][0]) / h;
        for (int k = 0; k <= m; k++) {
            y += sk(k, n-1, wezly) / ck(k, n-1) * wielomian_grama(k, q, n-1);
        }
        cout << "x=" << x << ", y= " << y << endl;
}