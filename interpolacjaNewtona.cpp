#include <iostream>
#include <fstream>

using namespace std;

void newton(int size, double tabx[], double tabf[]) {
	double x = 0.0;
	cout << "Podaj punkt: ";
	cin >> x;
	cout << endl;

	double wielomian = tabf[0] * 1;
	double temp = 1;
	double p;
	double b;
	
	cout << "Wspolczynniki wielomianu: " << endl;
	for (int k = 1; k < size; k++) {
		p = 1.0;
		b = 0.0;
		//pk
		for (int i = 0; i <= k - 1; i++) {
			p *= (x - tabx[i]);
		}
		//bk
		for (int i = 0; i <= k; i++) {
			temp = 1;
			for (int j = 0; j <= k; j++) {
				if (i == j) continue;
				temp *= tabx[i] - tabx[j];
			}
			b += tabf[i] / temp;
		}
		cout << b << endl;
		wielomian += p * b;
	}
	cout << "Liczba wezlow: " << size << endl;
	cout << "dane: " << endl;
	for (int i = 0; i < size; i++) {
		cout << tabx[i] << "  " << tabf[i] << endl;
	}
	cout << "Punkt w ktorym liczymy: " << x << endl;
	cout << "Wartosc wielomianu newtona: " << wielomian << endl;
}

int main() {

	ifstream plik, plik2;
	plik.open("MN-2-p2.txt", ios_base::in);
	//plik2.open("MN-2-p2.txt", ios_base::in);
	int size;
	plik >> size;
	//plik2 >> size2;
	double* tabx = new double[size];
	double* tabf = new double[size];

	for (int i = 0; i < size; i++) {
		plik >> tabx[i] >> tabf[i];
	}
	plik.close();

	/*cout << "Liczba wezlow: " << size << endl;
	cout << "dane: " << endl;
	for (int i = 0; i < size; i++) {
		cout << tabx[i] << "  " << tabf[i] << endl;
	}*/

	newton(size, tabx, tabf);

	delete[] tabx;
	delete[] tabf;
}
