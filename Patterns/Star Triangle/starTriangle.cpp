/*
*
* *
* * *
* * * *
* * * * *
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << endl << "Enter pattern range: ";
    cin >> n;
    cout << endl;

    for(int i=1 ; i<=n ; i++){
        cout << "*";
        for(int j=1 ; j<i ; j++){
            cout << " *";
        }
        cout << endl;
    }
    return 0;
}