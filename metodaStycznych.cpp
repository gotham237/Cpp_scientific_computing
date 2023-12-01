#include <iostream>
using namespace std;

double funkcja(double x) {
	return -1 * pow(x, 3) + 10 * x + 5;
}

double funkcja2(double x) {
	return -5 * pow(x, 3) + 6 * x + 10;
}

double funkcja3(double x) {
	//-3x^2 + 2x + 5
	return -3 * pow(x, 2) + 2 * x + 5;
}

double pochodnaFunkcji(double x) {
	return -3 * pow(x, 2) + 10;
}

double pochodnaFunkcji2(double x) {
	return -15 * pow(x, 2) + 6;
}

double pochodnaFunkcji3(double x) {
	return -6 * x + 2;
}

//double ilorazRoznicowy(double x1, double x) {
//	return (funkcja(x1) - funkcja(x)) / (x1 - x);
//}

void metodaStycznych(double x0, double N, double(*f)(double), double(*f2)(double)) {
	double* xi = new double[N + 1];
	xi[0] = x0;
	int i;
	for (i = 1; i < N + 1; i++) {
		xi[i] = xi[i - 1] - f(xi[i - 1]) / f2(xi[i - 1]);
		//cout << "Wartosc funkcji dla " << i << " iteracji" << endl;
		//cout << f(xi[i - 1]) << endl;
		cout << xi[i] << endl;
	}
	cout << "x: " << xi[i - 1] << endl;
}

void metodaSiecznych(double x0, double N, double(*f)(double)) {
	double* xi = new double[N + 2];
	xi[0] = x0 - 0.1;
	xi[1] = x0;
	int i;
	for (i = 2; i < N + 2; i++) {
		xi[i] = xi[i - 1] - f(xi[i - 1]) * (xi[i - 1] - xi[i - 2]) / (f(xi[i - 1]) - f(xi[i - 2]));
		//cout << "Wartosc funkcji dla " << i - 1 << " iteracji" << endl;
		//cout << funkcja(xi[i]) << endl;
		cout << xi[i] << endl;
	}
	cout << "x: " << xi[i - 1] << endl;
}

int main() {
	cout << "Rownanie: -x^3 + 10x + 5" << endl;
	metodaStycznych(6, 5, funkcja, pochodnaFunkcji);
	metodaSiecznych(6, 5, funkcja);
	//
	cout << endl << "funkcja2: -5x^3 + 6x + 10" << endl;
	metodaStycznych(3, 6, funkcja2, pochodnaFunkcji2);
	metodaSiecznych(3, 6, funkcja2);
	//
	cout << endl << "funkcja3: -3x^2 + 2x + 5" << endl;
	metodaStycznych(10, 8, funkcja3, pochodnaFunkcji3);
	metodaSiecznych(10, 8, funkcja3);
}