#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
    float c, f, k;
    char T[1];

    cout << "***Temperature Converter***" << endl << endl;
    cout << "From Format (Type 'C' for Celcius, 'F' for Farenheit, 'K' for Kelvin) = ";
    cin >> T;

    if(strcmp(T, "C")==0 || strcmp(T, "c")==0) {
        cout << endl << "Enter Temperature in Celcius = ";
        cin >> c;

        f = ((9*c) / 5) + 32;
        k = c + 273.15;

        cout << endl << "Farenheit Result = " << f;
        cout << endl << "Kelvin Result = " << k;
    }
    else if(strcmp(T, "F")==0 || strcmp(T, "f")==0) {
        cout << endl << "Enter Temperature in Farenheit = ";
        cin >> f;

        c = (5*(f-32)) / 9;
        k = c + 273.15;

        cout << endl << "Celcius Result = " << c;
        cout << endl << "Kelvin Result = " << k;
    }
    else if(strcmp(T, "K")==0 || strcmp(T, "k")==0) {
        cout << endl << "Enter Temperature in Kelvin = ";
        cin >> k;

        c = k-273.15;
        f = ((9*c) / 5) + 32;

        cout << endl << "Celcius Result = " << c;
        cout << endl << "Farenheit Result = " << f;
    }
    cout << endl << endl << "Code by SHAHRIAR ALI SIAM" << endl;

    return 0;
}
