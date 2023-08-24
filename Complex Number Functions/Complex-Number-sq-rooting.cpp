#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main() {
    double a, b, x=0, y=0, p2=0;
    cout << "<<<Root Determiner of Complex Number>>>" << endl;
    cout << endl << "Enter the value of 'a' & 'b' where 'a' is real part and 'b' is imaginary part (a+bi)" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    p2 = sqrt((a*a) + (b*b));
    x = sqrt((p2 + a) / 2);
    y = sqrt((p2 - a) / 2);
    if(b > 0) {
        cout << endl << "Square Root of " << a << "+" << b << "i = ";
        cout << "(" << x << "+" << y << "i), " << "-(" << x << "+" << y << "i)";
    }
    else {
        cout << endl << "Square Root of " << a << b << "i = ";
        cout << "(" << x << "-" << y << "i), " << "-(" << x << "-" << y << "i)";
    }
    cout << endl << endl << "<<<Code by Shahriar Ali Siam>>>";
    cout << endl << endl << "Press any key to exit." << endl;
    getch();
    return 0;
}