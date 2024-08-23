#define _WIN32_WINNT 0x0600

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

#ifndef _CONSOLE_FONT_INFOEX
typedef struct _CONSOLE_FONT_INFOEX {
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT FontFamily;
    UINT FontWeight;
    WCHAR FaceName[LF_FACESIZE];
} CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
#endif

bool gameOver, settings;
const int width = 20, height = 20;
int snakeX, snakeY, foodX, foodY, score, bodyC;
int *bodyX = nullptr;
int *bodyY = nullptr;
string level, wall;
char over;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setConsoleSize(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); // Get the current window size
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SetConsoleFontSize(int fontSize) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cerr << "Error getting console handle" << std::endl;
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        std::cerr << "Error getting console screen buffer info" << std::endl;
        return;
    }

    // Adjust the buffer size to indirectly affect the font size
    COORD newSize;
    newSize.X = csbi.dwSize.X;  // Keep the current width
    newSize.Y = fontSize;       // Set the new height (font size)

    if (!SetConsoleScreenBufferSize(hConsole, newSize)) {
        std::cerr << "Error setting console screen buffer size" << std::endl;
    }
}

void ConsoleCursor(bool visibility) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visibility;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Setup() {
    gameOver = false;
    over = 'n';
    score = 0;
    bodyC = 0;
    dir = STOP;
    snakeX = width / 2;
    snakeY = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    ConsoleCursor(false);

    if (bodyX == nullptr) {
        bodyX = new int[200];
    }
    if (bodyY == nullptr) {
        bodyY = new int[200];
    }
}

void Draw() {
    string frame;

    frame += "\n\tSnake Bite\n   By SHAHRIAR TECHNOLOGIES LTD.\n\n";

    frame += string((width + 2), '-') + "\n";
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
    frame += string((width + 2), '-') + "\n";

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
            over = 'e';
        }
    }
}

void Logic() {
    //snake body logic
    for(int i=bodyC ; i>0 ; i--) {
        bodyX[i] = bodyX[i-1];
        bodyY[i] = bodyY[i-1];
    }
    bodyX[0] = snakeX;
    bodyY[0] = snakeY;

    //input logic
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

    //wall hit logic
    if(wall == "Enabled") {
        if(snakeX < 0 || snakeX > width-1 || snakeY < 0 || snakeY > height-1) {
            gameOver = true;
            over = 'w';
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

    //body hit logic
    for(int i=0 ; i<bodyC ; i++) {
        if(bodyX[i] == snakeX && bodyY[i] == snakeY) {
            gameOver = true;
            over = 'b';
            break;
        }
    }

    //food eating logic
    if(snakeX == foodX && snakeY == foodY) {
        score += 5;
        bodyC++;
        foodX = rand() % width;
        foodY = rand() % height;
    }
}

void Over() {
    int op;

    ConsoleCursor(true);

    if (bodyX != nullptr) {
        delete[] bodyX;
        bodyX = nullptr;
    }
    if (bodyY != nullptr) {
        delete[] bodyY;
        bodyY = nullptr;
    }

    while(true) {
        system("cls");
        
        cout << endl << "\tSnake Bite" << endl;
        cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

        cout << "\tGAME OVER" << endl;
        cout << "Your Score: " << score << endl;
        
        if(over == 'w') {
            cout << "Your snake hit the wall and died." << endl << endl;
        }
        else if(over == 'b') {
            cout << "Your snake hit its own body and died." << endl << endl;
        }
        else if(over == 'e') {
            cout << "You pressed exit button (X key)." << endl << endl;
        }
        
        cout 
            << "1. Play Again" << endl
            << "2. Exit" << endl
        << endl;
        cout << "Enter option: ";
        cin >> op;

        if(op == 1) {
            return;
        }
        else if(op == 2) {
            settings = false;
            return;
        }
        else {
            system("cls");

            cout << endl << "\tSnake Bite" << endl;
            cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

            cout << "\t* Invalid Input!" << endl;
            cout << "\t* Press any key to try again....";

            getch();
        }
    }
}

int main() {
    int op, speed;
    settings = true;

    setConsoleSize(800, 600);
    SetConsoleFontSize(24);

    while(settings == true) {
        system("cls");

        cout << endl << "\tSnake Bite" << endl;
        cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

        cout << "Game Levels (Represents snake moving speed)" << endl;
        cout
            << "1. Easy" << endl
            << "2. Medium" << endl
            << "3. Hard" << endl
        << endl;
        cout << "Enter option: ";
        cin >> op;

        if(op == 1 || op == 2 || op == 3) {
            if(op == 1) {
                level = "Easy";
                speed = 200;
            }
            else if(op == 2) {
                level = "Medium";
                speed = 150;
            }
            else if(op == 3) {
                level = "Hard";
                speed = 80;
            }

            while(settings == true) {
                system("cls");

                cout << endl << "\tSnake Bite" << endl;
                cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;
                
                cout << "Wall Restriction" << endl;
                cout
                    << "1. Enable (If snake hits wall then it will die)" << endl
                    << "2. Disable (The snake will pass through the wall)" << endl
                << endl;
                cout << "Enter option: ";
                cin >> op;

                if(op == 1 || op == 2) {
                    if(op == 1) {
                        wall = "Enabled";
                    }
                    else if(op == 2) {
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

                    Over();
                    break;
                }
                else {
                    system("cls");

                    cout << endl << "\tSnake Bite" << endl;
                    cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

                    cout << "\t* Invalid Input!" << endl;
                    cout << "\t* Press any key to try again....";

                    getch();
                }
            }
        }
        else {
            system("cls");

            cout << endl << "\tSnake Bite" << endl;
            cout << "   By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

            cout << "\t* Invalid Input!" << endl;
            cout << "\t* Press any key to try again....";

            getch();
        }
    }

    return 0;
}