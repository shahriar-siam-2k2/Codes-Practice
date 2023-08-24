#include <iostream>
#include <conio.h>
using namespace std;


int main() {
    float n1,n2,r=0;
    char o;

    cout << endl << "Enter two numbers" << endl;
    cin >> n1 >> n2;

    cout << "Enter operator (+, -, *, /)" << endl;
    cin >> o;

    switch(o) {
        case '+':
            r =  n1 + n2;
            cout << "Result = " << r << endl;
            break;
        case '-':
            r = n1 - n2;
            cout << "Result = " << r << endl;
            break;
        case '*':
            r = n1 * n2;
            cout << "Result = " << r << endl;
            break;
        case '/':
            r = n1 / n2;
            cout << "Result = " << r << endl;
            break;
        default:
            cout << "Only (+, -, *, /) is allowed" << endl;
            break; 
    }
    cout << endl << "Press any key to continue" << endl;
    getch();

    return 0;
}