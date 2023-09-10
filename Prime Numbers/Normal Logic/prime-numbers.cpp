#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

bool detPrime(int num) {
    for(int i=2 ; i<=sqrt(num) ; i++) {
        if(num % i == 0) {
            return false;
        }   
    }
    return true;
}
void noPrime(int a, int b) {
    cout << endl << "No prime number between " << a << " and " << b << "." << endl;
    cout << endl << "Press any key to continue." << endl;
    getch();
}


int main () {
    int a, b;

    cout << endl << "----Prime Number Determiner----" << endl;
    cout << endl << "Enter two real (R\") numbers: ";
    cin >> a >> b;

    int prime[b+1], c=0;
    for(int i=a ; i<=b ; i++) {
        if(i==0 || i==1) {
            continue;
        }
        else if(detPrime(i)) {
            prime[c] = i;
            c++;
        } 
    }
    if(c==0) {
        noPrime(a, b);
    }
    else {
        cout << endl << c << " prime number(s) between " << a << " and " << b << ": " << endl;
        for(int i=0 ; i<c ; i++) {
            if(prime[i]==0 || prime[i]==1) {
                continue;
            }
            else if(i==(c-1)) {
                cout << prime[i] << "." << endl;
                cout << endl << "Press any key to continue." << endl;
                getch();
            }
            else {
                cout << prime[i] << ", ";
            }
        }
    }
    return 0;
}