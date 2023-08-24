//Swaping two numbers without any pointers or 3rd variables
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int a, b;

    cout << endl << "Enter two numbers: ";
    cin >> a >> b;

    cout << endl << "Entered numbers: " << a << " " << b;

    a = a + b;
    b = a - b;
    a = a - b;

    cout << endl << "Swapped numbers: " << a <<  " " << b << endl;
    cout << endl << "Press any key to continue." << endl;
    getch();
    
    return 0;
}