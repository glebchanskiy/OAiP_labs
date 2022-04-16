#include <iostream>
#include <cmath>

using namespace std;


double f(double);

double iter_x(double, double, double);


// x^2 - 10sin^2(x)+2
int main() {

    double a, b, h, counter = 0;
    double root,x;
    double eps = 0.0001;

    a = -1;
    b = 3;
    h = 0.01;

    cout << "Функция:  x^2-10sin^2(x)+2" << endl;
    cout << "Искать корни на отрезке [a,b]:" << endl;
    cout << "(a)>>> "; cin >> a;
    cout << "(b)>>> "; cin >> b;
    cout << endl;
    cout << "(шаг цикла)>>> "; cin >> h;
    cout << "(точность eps)>>> "; cin >> eps; cout << endl;

    cout << "Корни функции:" << endl;
    for ( x = a; x < b + h; x += h) {
        if (f(x) * f(x + h) < 0) {
            counter++;
            root = iter_x(x, x + h, eps);
            cout << counter << "-й = " << root << endl;
        }
    }

    return 0;
}


double f(double x) {
    // x^2 - 10sin^2(x)+2 //
    return pow(x,2) - 10 * pow(sin(x), 2) + 2;
}


double iter_x(double x_begin, double x_end, double eps) {
    double x_mid, y_mid, y_begin;

    y_begin = f(x_begin);
    while (abs(x_begin - x_end) > eps) {
        x_mid = (x_begin + x_end) / 2;
        y_mid = f(x_mid);

        if (y_mid * y_begin > 0) {
            x_begin = x_mid;
            y_begin = y_mid;
        }
        else
            x_end = x_mid;
    }
    return (x_begin + x_end) / 2;
}