#include <iostream>
#include <conio.h>
using namespace std;

void start(int &n){
    cout << endl << "----Fibonacci Sequence Creator----" << endl;
    cout << endl << "Enter your desired range for creating a fibonacci sequence, where the range is a real & positive number (R\"): ";
    cin >> n;

    for( ; ; ){
        if(n<0) {
        cout << endl << "ERROR";
        cout << endl << "Only real & positive number (R\") is allowed!" << endl;
        cout << endl << "Re-executing this program..." << endl << endl;
        start(n);
        }
        else {
            break;
        }
    }
}

int main(){
    int n;

    start(n);

    int c=0, f[n+1];
    for(int i=0 ; i<n ; ){
        if(i==0 || i==1){
            f[c] = i;
            i++;
            c++;
            continue;
        }
        else{
            f[c] = f[c-2] + f[c-1];
            i = f[c]+1;
            c++;
        }
    }
    cout << endl << c << " Fibonacci numbers generated: " << endl;
    for(int i=0 ; i<c ; i++){
        if(i==(c-1)){
            cout << f[i] << "." << endl;
            cout << endl << "Press any key to continue." << endl;
            getch();
        }
        else{
            cout << f[i] << ", ";
        }
    }
    return 0;
}