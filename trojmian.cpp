#include <iostream>
using namespace std;
class trojmian {
private:
    int a, b, c;
public:
    trojmian()
    {
        a = 0;
        b = 0;
        c = 0;

    }
    trojmian(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
    }
    friend istream& operator>>(istream& in, trojmian& T);
    friend ostream& operator<<(ostream& out, trojmian& T);
    friend trojmian& operator+(trojmian& T1, trojmian& T2);
    friend trojmian& operator*(int x, trojmian& T);

    float pierwiastki() {
        int wiekszy = 0;
        float d = pow(b, 2) + 4 * a * c;
        float x1 = (-b + sqrt(d)) / 2 * a;
        float x2 = (-b - sqrt(d)) / 2 * a;
        cout << x1 << ',' << x2;
        if (x1 >= x2) wiekszy = x1;
        else wiekszy = x2;
        return wiekszy;
    }
};

istream& operator>>(istream& in, trojmian& T)
{
    float A, B, C;
    cout << "podaj kolejno wspolczynniki trojmianu: ";
    in >> A >> B >> C;
    T.a = A;
    T.b = B;
    T.c = C;
    return in;
}
ostream& operator<<(ostream& out, trojmian& T)
{
    out << T.a << T.b << T.c;
    return out;
}
trojmian& operator+(trojmian& T1, trojmian& T2) {
    trojmian T3;
    T3.a = T1.a + T2.a;
    T3.b = T1.b + T2.b;
    T3.c = T1.c + T2.c;
    return T3;
}
trojmian& operator*(int x, trojmian& T) {
    trojmian T4;
    T4.a = x * T.a;
    T4.b = x * T.b;
    T4.c = x * T.c;
    return T;
}