#include <iostream>
using namespace std;

double funkcja1(double x, double y) {
	return pow(x, 2) + y;
}
double funkcja2(double x, double y) {
	return x + y;
}

void Euler(double y, double x, double x1, double x2, double N, double (*f)(double, double)) {
	double* xi = new double[N];
	double* yi = new double[N];
	double h = (x2 - x1) / N;
	cout << "Warunek poczatkowy: " << endl;
	cout << "y(" << x1 << ") = " << y << endl;
	cout << "Punkt koncowy: " << endl;
	cout << x2 << endl;
	int i;
	for (i = 0; i < N; i++) {
		if (i == 0) {
			xi[i] = x1 + h;
			yi[i] = y + h * f(x1, y);
			//cout << "Krok nr " << i + 1 << endl;
			//cout << xi[i] << endl << yi[i] << endl;
		}
		else
		{
			xi[i] = xi[i - 1] + h;
			yi[i] = yi[i - 1] + h * f(xi[i - 1], yi[i - 1]);
			//cout << "Krok nr " << i + 1 << endl;
			//cout << xi[i] << endl << yi[i] << endl;
		}
	}
	cout << "y(" << x << ") = " << yi[i - 1] << endl;
	delete[] xi;
	delete[] yi;
}

double RK2(double x, double y, double h, double (*f)(double,double)) {
	double k1 = f(x, y);
	double k2 = f(x + h, y + h * k1);
	return 0.5 * (k1 + k2);
}

double RK4(double x, double y, double h, double (*f)(double, double)) {
	double k1 = f(x, y);
	double k2 = f(x + 0.5*h, y + 0.5 * h * k1);
	double k3 = f(x + 0.5 * h, y + 0.5 * h * k2);
	double k4 = f(x + h, y + h * k3);
	//cout << " RK4: " << (k1 + 2 * k2 + 2 * k3 + k4)/6 << endl;
	return (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

void Runge_Kutty(double y, double x, double h, double N, double (*rk)(double, double, double, double (*f)(double, double)), double (*f)(double, double)) {
	double* yi = new double[N];
	double* xi = new double[N];
	int i;
	for (i = 0; i < N; i++) {
		if (i == 0) {
			xi[i] = 0 + h;
			yi[i] = y + h * rk(0, y, h, f);
			//cout << "Krok nr " << i + 1 << endl;
			//cout << xi[i] << endl << yi[i] << endl;
		}
		else
		{
			xi[i] = xi[i - 1] + h;
			yi[i] = yi[i - 1] + h * rk(xi[i - 1], yi[i - 1], h, f);
			//cout << "Krok nr " << i + 1 << endl;
			//cout << xi[i] << endl << yi[i] << endl;
		}
	}
	cout << "y(" << x << ") = " << yi[i - 1] << endl;
	delete[] xi;
	delete[] yi;
}


int main() {
	double h = 0.1;
	cout << "Euler: " << endl;
	Euler(0.1, 0.3, 0, 1, 10, funkcja1);
	Euler(0.1, 0.3, 0, 1, 10, funkcja2);
	cout << "Runge-kutty2: " << endl;
	Runge_Kutty(0.1, 1, h, 10, RK2, funkcja1);
	Runge_Kutty(0.1, 1, h, 10, RK2, funkcja2);
	cout << "Runge-kutty4: " << endl;
	Runge_Kutty(0.1, 1, h, 10, RK4, funkcja1);
	Runge_Kutty(0.1, 1, h, 10, RK4, funkcja2);
}