#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
    double m, h, hm, hc, BMI, BMR, a, cal;
    char N[30], C[3], G[3], E[3];
    cout << endl << endl << "***Body Mass Index (BMI) Counter***" << endl << endl;
    cout << "Enter your name: ";
    cin >> N;
    cout << "Enter your weight (Kg): ";
    cin >> m;
    cout << "Enter your height (Inch): ";
    cin >> h;

    //BMI
    hm = h * 0.0254;//inch to meter
    BMI = m / (hm*hm);

    cout << endl << N << "'s BMI report:" << endl << endl << "BMI= " << BMI << endl;

    //BMI chart
    if(BMI < 18.5) {
        cout << "It's Underweight" << endl;
    }
    else if(BMI >= 18.5 && BMI <= 24.99) {
        cout << "It's Normal weight" << endl;
    }
    else if(BMI >= 25.0 && BMI <= 29.99) {
        cout << "It's Over weight" << endl;
    }
    else if(BMI >= 30.0 && BMI <= 34.99) {
        cout << "It's Class 1 obesity" << endl;
    }
    else if(BMI >= 35.0 && BMI <= 39.99) {
        cout << "It's Class 2 obesity" << endl;
    }
    else if(BMI >= 40.0) {
        cout << "It's Class 3 obesity" << endl;
    }

    cout << endl << "Do you want to count your BMR? ('Y'/'y' for yes, 'N'/'n' for no): " << endl;
    cin >> C;
    for(; ;) {
        if(strcmp("N",C)==0 || strcmp("n",C)==0) {
            break;
        }
        else if(strcmp("Y",C)==0 || strcmp("y",C)==0) {
            cout << endl << endl << "***Body Metabolic Rate (BMR) Counter***" << endl << endl;
            cout << "Enter your age: ";
            cin >> a;
            cout << "Enter your gender ('M'/'m' for male, 'F'/'f' for female): ";
            cin >> G;

            cout << endl << "Inform more about " << N << ":" << endl;
            cout << "1. If " << N << " is not hardworking; press 1" << endl;
            cout << "2. If " << N << " is light-hardworking, plays sports 2-3 days per week; press 2" << endl;
            cout << "3. If " << N << " is hardworking, plays sports a lot 2-3 days per week; press 3" << endl;
            cout << "4. If " << N << " is hardworking, plays sports a lot daily per week; press 4" << endl;
            cout << "5. If " << N << " is extremely hardworking, plays sports extremely; press 5" << endl;
            cout << "Enter your number: " << endl;
            cin >> cal;
            //inch to centimeter
            hc = h*2.54;
            if(strcmp("M",G)==0 || strcmp("m",G)==0) {
                BMR = 66+(13.7*m)+(5*hc)-(6.8*a);
                cout << endl << endl << N << "'s BMR Report: " << endl << endl << "Ideal BMR= " << BMR << " " << "Calorie" << endl;
                if(cal == 1) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.2 << " " << "Calorie" << endl;
                }
                else if(cal == 2) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.375 << " " << "Calorie" << endl;
                }
                else if(cal == 3) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.55 << " " << "Calorie" << endl;
                }
                else if(cal == 4) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.725 << " " << "Calorie" << endl;
                }
                else if(cal == 5) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.9 << " " << "Calorie" << endl;
                }
                cout << endl <<  "Enter any key to close:" << endl;
                cin >> E;
                if(E) {
                    break;
                }
            }
            else if (strcmp("F",G)==0 || strcmp("f",G)==0) {
                BMR = 655+(9.6*m)+(1.8*hc)-(4.7*a);
                cout << endl << endl << N << "'s BMR Report: " << endl << endl << "Ideal BMR= " << BMR << " " << "Calorie" << endl;
                if(cal == 1) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.2 << " " << "Calorie" << endl;
                }
                else if(cal == 2) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.375 << " " << "Calorie" << endl;
                }
                else if(cal == 3) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.55 << " " << "Calorie" << endl;
                }
                else if(cal == 4) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.725 << " " << "Calorie" << endl;
                }
                else if(cal == 5) {
                    cout << N << "'s Daily BMR Demand= " << BMR * 1.9 << " " << "Calorie" << endl;
                }
                cout << endl <<  "Enter any key to close:" << endl;
                cin >> E;
                if(E) {
                    break;
                }
            }
            else {
                cout << "Enter correct data." << endl << endl;
                break;
            }
        }
        else {
            cout << "Enter correct data." << endl << endl;
            break;
        }
    }
    return 0;
}





