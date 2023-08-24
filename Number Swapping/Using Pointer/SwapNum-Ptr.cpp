//Swapping numbers using cpp pointer
#include <iostream>
using namespace std;

void SwapFunc(int* a, int* b) { //created swapping function named "SwapFunc"
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main () {
    int a, b;

    cout << endl << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << endl << "Entered numbers: " << a << " " << b;

    SwapFunc(&a, &b); //called the "SwapFunc" swapping function

    cout << endl << "Swapped numbers: " << a <<  " " << b << endl;

    return 0;
}