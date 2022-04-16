#include "cmath"
#include <iostream>

using namespace std;


double func_s(double, int);

double func_y(double);

double func_abs_y_minus_s(double, double);

// проверка на 0.1  1  0.1  10
int main()
{
    double a, b, h, x;
    int n;

    cout<< "Input  a: ";
    cin>> a;
    cout<< "Input  b: ";
    cin>> b;
    cout<< "Input  h: ";
    cin>> h;
    cout<< "Input  n: ";
    cin>> n;

    for (x = a; x <= b; x += h){
        printf("\n x = %3.2lf,   |Y(x) - S(x)| = %8.4lf", x, func_abs_y_minus_s( func_y(x), func_s(x, n) ));
    }

//    int wait;
//    cin>> wait;
    cout<< endl;
    return 0;
}


double func_y(double x) {
    double Y;
    Y = -1*log(sqrt(1+x*x)) + x*atan(x);
    return Y;
}


double func_s(double x, int n) {
    double S=0;

    for (int k = 1; k <= n; k++)
        S += pow(-1,(k+1)) * (pow(x, (2*k))) / (2*k * (2*k - 1));
    return S;
}


double func_abs_y_minus_s( double Y, double S) {
    return fabs(Y-S);
}

