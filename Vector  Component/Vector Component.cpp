#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main() {
    double s1, s2, s3, a1, a2, a3, R, theta, Sx, Sy;
    const double pi = 3.1416;
    cout << endl;

    //input
    cout << "Distance 1 = ";
    cin >> s1;
    cout << "Angle 1(degree) = ";
    cin >> a1;
    cout << endl;

    cout << "Distance 2 = ";
    cin >> s2;
    cout << "Angle 2(degree) = ";
    cin >> a2;
    cout << endl;

    cout << "Distance 3 = ";
    cin >> s3;
    cout << "Angle 3(degree) = ";
    cin >> a3;
    
    //convertion (deg to rad)
    a1 = a1 * (pi/180);
    a2 = a2 * (pi/180);
    a3 = a3 * (pi/180);
    
    //calculation
    Sx = s1*cos(a1) + s2*cos(a2) + s3*cos(a3);
    Sy = s1*sin(a1) + s2*sin(a2) + s3*sin(a3);
    R = sqrt((Sx*Sx) + (Sy*Sy));
    theta = atan(Sy/Sx);

    //Convertion (rad to deg)
    theta = theta * (180/pi);

    //Sx, Sy conditions
    if(Sx < 0) {
        theta = theta + 180;
    }

    //output
    cout << endl << "Resultant = " << R;
    cout << endl << "Resultant angle(from x axis) = " << theta << " degree";
    cout << endl << endl << "Press any key to continue." << endl;

    getch();
    return 0;
}