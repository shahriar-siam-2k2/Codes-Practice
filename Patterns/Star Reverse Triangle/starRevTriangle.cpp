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
    
    int c = n;
    for(int i=1 ; i <= n ; i++){
        for(int j=1 ; j <= (c*2)-2 ; j++){
            cout << " ";
        }
        for(int j=i ; j != 0 ; j--){
            cout << "* ";
        }
        cout << endl;
        c--;
    }
    return 0;
}