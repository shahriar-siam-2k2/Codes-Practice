#include <bits/stdc++.h>
using namespace std;

void SoE(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    
    for(int i=2 ; i*i <= n ; i++){
        if(prime[i]==true){
            for(int j= i*i ; j<=n ; j=i+j){
                prime[j] = false;
            }
        }
    }
    cout << "Prime numbers up to " << n << " are: ";
    for(int i=0 ; i<n ; i++){
        if(prime[i]==true){
            cout << i;
        }

        if(prime[i+1]==true && i>1){
            cout << ", ";
        }
    }
    cout << "." << endl;
}

int main(){
    int n;
    cout << endl << "----Prime Number Determiner----" << endl;
    cout << "----Sieve of Eratosthenes (SoE) Method----" << endl;
    cout << endl << "Enter a real (R\") number: ";
    cin >> n;
    SoE(n);
    return 0;
}