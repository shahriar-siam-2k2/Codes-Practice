#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char N1[5], N2[5], N3[5], N4[5], C[3];
    cout << endl << endl << "***Let's Watch Movie!!***" << endl << "First let's check persons:";

    cout << endl << endl << "Is Siam going? ('y' for Yes ; 'n' for No): ";
    cin >> N1;
    cout << "Is Jihan going? ('y' for Yes ; 'n' for No): ";
    cin >> N2;
    cout  << "Is Arian going? ('y' for Yes ; 'n' for No): ";
    cin >> N3;
    cout  << "Is Tafim going? ('y' for Yes ; 'n' for No): ";
    cin >> N4;

    if(strcmp("y",N1)==0 && strcmp("y",N2)==0 && strcmp("y",N3)==0 && strcmp("y",N4)==0) {
        cout << endl << "Shbai movie dekhbo, moja hobeee, Movie er por chicken party hobeee!!" << endl;
    }
    else if (strcmp("n",N1)==0 && strcmp("n",N2)==0 && strcmp("n",N3)==0 && strcmp("n",N4)==0) {
        cout << endl << "Heda r movie dekhar plan -_-" << endl;
    }
    else if(strcmp("n",N1)==0) {
        cout << endl << "Karo movie dekha lagbona. Siam";
        if(strcmp("n",N2)==0) {
            cout << ", Jihan";
        }
        if(strcmp("n",N3)==0) {
            cout << ", Arian";
        }
        cout << " re dhoira mar." << endl;
    }
    else if(strcmp("n",N2)==0) {
        cout << endl << "Karo movie dekha lagbona. Jihan";
        if(strcmp("n",N3)==0) {
            cout << ", Arian";
        }
        if(strcmp("n",N4)==0) {
            cout << ", Tafim";
        }
        cout << " re dhoira mar." << endl;
    }
    else if(strcmp("n",N3)==0) {
        cout << endl << "Karo movie dekha lagbona. Arian";
        if(strcmp("n",N4)==0) {
            cout << ", Tafim";
        }
        if(strcmp("n",N1)==0) {
            cout << ", Siam";
        }
        cout << " re dhoira mar." << endl;
    }
    else if(strcmp("n",N4)==0) {
        cout << endl << "Karo movie dekha lagbona. Tafim";
        if(strcmp("n",N1)==0) {
            cout << ", Siam";
        }
        if(strcmp("n",N2)==0) {
            cout << ", Jihan";
        }
        cout << " re dhoira mar." << endl;
    }
    else {
        cout << "Enter Correct value!" << endl;
        cout << endl << "Press 'c' to close: ";
        cin >> C;
    }

    cout << endl << "Press 'c' to close: ";
    cin >> C;
    return 0;
}

int main() {
    float F;

    cout << "Enter any number: ";
    cin >> F;

    if(F<0) {
        cout << "Arianer nanir heda";
    }
    else {
        cout << "Jihaner nanir heda";
    }
    return 0;
}