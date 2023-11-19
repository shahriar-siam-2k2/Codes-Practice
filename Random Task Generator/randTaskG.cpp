#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int person;
    cout << endl << "Enter group/team member number: ";
    cin >> person;
    string per_names[person];
    cout << "Enter person names: ";
    for(int i=0 ; i<person ; i++){
        getline(cin, per_names[i]);
    }

    int tasks;
    cout << endl << "Enter total task number: ";
    cin >> tasks;
    string task_names[tasks];
    cout << "Enter task names: ";
    for(int i=0 ; i<tasks ; i++){
        getline(cin, task_names[i]);
    }

    int num = 0, per_assign_num[tasks], task_assign_num[tasks];
    bool unique = false;

    for(int i=0 ; i<tasks ; i++){
        srand((unsigned int)time(NULL));
        num = rand() % person;
        per_assign_num[i] = num;

        do{
            srand((unsigned int)time(NULL));
            num = rand() % tasks;
            unique = true;
            for(int j=0 ; j<i ; j++){
                if(task_assign_num[j] == num){
                    unique = false;
                }
            }
        }
        while(!unique);
        task_assign_num[i] = num;
    }
    cout << endl << "Your team's/group's person tasks given below- " << endl;
    for(int i=0 ; i<person ; i++){
        cout << i+1 << ". " << per_names[i] << ": ";
        for(int j=0 ; j<tasks ; j++){
            if(per_assign_num[j] == i){
                cout << task_names[j];
                if((j+1) != tasks){
                    cout << ", ";
                }
            }
        }
        cout << "." << endl;
    }
    return 0;
}