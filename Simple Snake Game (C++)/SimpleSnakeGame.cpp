#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20, height = 20;
int snakeX, snakeY, foodX, foodY, score, bodyC, bodyX[100], bodyY[100];
string level, wall;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void HideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Setup() {
    gameOver = false;
    score = 0;
    dir = STOP;
    snakeX = width / 2;
    snakeY = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    HideCursor();
}

void Draw() {
    string frame;

    frame += "\n\tSimple Snake Game\n   By SHAHRIAR TECHNOLOGIES LTD.\n\n";

    frame += string((width + 2), '=') + "\n";
    for(int i=0 ; i<width ; i++) {
        for(int j=0 ; j<height ; j++) {
            if(j == 0) {
                frame += "|";
            }

            if(i == snakeY && j == snakeX) {
                frame += "0";
            }
            else if(i == foodY && j == foodX) {
                frame += "*";
            }
            else {
                bool print = false;
                for(int k=0 ; k<bodyC ; k++) {
                    if(bodyX[k] == j && bodyY[k] == i) {
                        print = true;
                        frame += "o";
                    }
                }

                if(print == false) {
                    frame += " ";
                }
            }

            if(j == (width - 1)) {
                frame += "|";
            }
        }
        frame += "\n";
    }
    frame += string((width + 2), '=') + "\n";

    frame += "Score: " + to_string(score) + "\n";
    frame += "Game Level: " + level + "\n";
    frame += "Wall Restriction: " + wall + "\n";
    frame += "\nUse W A S D key to move and to exit game press X\n";

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});

    cout << frame;
}

void Input() {
    if(_kbhit()) {
        char key = _getch();
        if(key == 'a') {
            dir = LEFT;
        }
        else if(key == 'd') {
            dir = RIGHT;
        }
        else if(key == 'w') {
            dir = UP;
        }
        else if(key == 's') {
            dir = DOWN;
        }
        else if(key == 'x') {
            gameOver = true;
        }
    }
}

void Logic() {
    for(int i=bodyC ; i>0 ; i--) {
        bodyX[i] = bodyX[i-1];
        bodyY[i] = bodyY[i-1];
    }
    bodyX[0] = snakeX;
    bodyY[0] = snakeY;

    if(dir == LEFT) {
        snakeX--;
    }
    else if(dir == RIGHT) {
        snakeX++;
    }
    else if(dir == UP) {
        snakeY--;
    }
    else if(dir == DOWN) {
        snakeY++;
    }

    if(wall == "Enabled") {
        if(snakeX < 0 || snakeX > width-1 || snakeY < 0 || snakeY > height-1) {
            gameOver = true;
        }
    }
    else if(wall == "Disabled") {
        if(snakeX >= width) {
            snakeX = 0;
        }
        else if(snakeX < 0) {
            snakeX = width-1;
        }
        
        if(snakeY >= height) {
            snakeY = 0;
        }
        else if(snakeY < 0) {
            snakeY = height-1;
        }
    }

    for(int i=0 ; i<bodyC ; i++) {
        if(bodyX[i] == snakeX && bodyY[i] == snakeY) {
            gameOver = true;
        }
    }

    if(snakeX == foodX && snakeY == foodY) {
        score += 5;
        bodyC++;
        foodX = rand() % width;
        foodY = rand() % height;
    }
}

int main() {
    char op;
    int speed;
    bool settings = true;

    while(settings == true) {
        system("cls");

        cout << endl << "\tSimple Snake Game" << endl;
        cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

        cout << "Game Levels (Represents snake moving speed)" << endl;
        cout
            << "1. Easy" << endl
            << "2. Medium" << endl
            << "3. Hard" << endl
        << endl;
        cout << "Enter option: ";
        cin >> op;

        if(op == '1' || op == '2' || op == '3') {
            if(op == '1') {
                level = "Easy";
                speed = 250;
            }
            else if(op == '2') {
                level = "Medium";
                speed = 150;
            }
            else if(op == '3') {
                level = "Hard";
                speed = 50;
            }

            while(settings == true) {
                system("cls");

                cout << endl << "\tSimple Snake Game" << endl;
                cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;
                
                cout << "Wall Restriction" << endl;
                cout
                    << "1. Enable (If snake hits wall then it will die)" << endl
                    << "2. Disable (The snake will pass through the wall)" << endl
                << endl;
                cout << "Enter option: ";
                cin >> op;

                if(op == '1' || op == '2') {
                    if(op == '1') {
                        wall = "Enabled";
                    }
                    else if(op == '2') {
                        wall = "Disabled";
                    }

                    system("cls");

                    Setup();
                    
                    while(gameOver == false) {
                        Draw();
                        Input();
                        Logic();
                        Sleep(speed);
                    }
                    return 0;
                }
                else {
                    system("cls");

                    cout << endl << "\tSimple Snake Game" << endl;
                    cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

                    cout << "\t* Invalid Input!" << endl;
                    cout << "\t* Press any key to try again....";

                    getch();
                }
            }
        }
        else {
            system("cls");

            cout << endl << "\tSimple Snake Game" << endl;
            cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

            cout << "\t* Invalid Input!" << endl;
            cout << "\t* Press any key to try again....";

            getch();
        }
    }

    return 0;
}