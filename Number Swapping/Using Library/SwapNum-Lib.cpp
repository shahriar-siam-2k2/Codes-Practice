//Swapping numbers using cpp library
#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << endl << "Enter two numbers: ";
    cin >> a >> b;

    cout << endl << "Entered numbers: " << a << " " << b;

    swap(a, b); //used library "swap()" for swapping numbers

    cout << endl << "Swapped numbers: " << a <<  " " << b << endl;
    
    return 0;
}