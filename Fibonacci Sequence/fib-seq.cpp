#include <iostream>
#include <conio.h>
using namespace std;

void start(int &n){
    cout << endl << "----Fibonacci Sequence Creator----" << endl;
    cout << endl << "Enter your desired range for creating a fibonacci sequence, where the range is a positive real number (R\"): ";
    cin >> n;

    for( ; ; ){
        if(n<0) {
        cout << endl << "ERROR";
        cout << endl << "Only positive real number (R\") is allowed!" << endl;
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
    for(int i=0 ; i<=n ; ){
        if(i==0 || i==1){
            f[c] = i;
            i++;
            c++;
            continue;
        }
        else{
            int t = f[c-2] + f[c-1];
            if(t<=n){
                f[c] = t;
                i = f[c]+1;
                c++;
            }
            else{
                break;
            }
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