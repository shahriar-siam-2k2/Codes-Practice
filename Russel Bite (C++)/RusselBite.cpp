#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver, settings, pause;
const int width = 20, height = 20;
int snakeX, snakeY, foodX, foodY, score, bodyC, maxBody = 10;
int* bodyX = nullptr;
int* bodyY = nullptr;
int* clsTrack = nullptr;
string level, wall;
char over;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

//Console Functions. Courtesy: ChatGPT, Stack Overflow, YouTube.
void SetConsoleSize(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); // Get the current window size
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void DisableConsoleFullscreenButton() {
    HWND consoleWindow = GetConsoleWindow(); // Get the console window handle

    // Get the system menu of the console window and remove the maximize option
    HMENU hMenu = GetSystemMenu(consoleWindow, FALSE);
    if (hMenu != nullptr) {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND); // Disable the maximize button
    }
}
void DisableConsoleResize() {
    HWND consoleWindow = GetConsoleWindow(); // Get the console window handle

    // Retrieve the current window style
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

    // Remove the resizing and maximize box options from the style
    style &= ~(WS_MAXIMIZEBOX | WS_SIZEBOX); // Disable resizing
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void SetConsoleFontSize(int fontSize) {
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get current font settings
    GetCurrentConsoleFontEx(hConsole, false, &cfi);

    // Set new font size (fontSize is in pixels)
    cfi.dwFontSize.X = fontSize; // Set font size for width
    cfi.dwFontSize.Y = fontSize; // Set font size for height

    // Apply the new font settings
    SetCurrentConsoleFontEx(hConsole, false, &cfi);
}
void CenterConsole() {
    // Get the console window handle
    HWND consoleWindow = GetConsoleWindow();

    // Ensure console window handle is valid
    if (consoleWindow == nullptr)
    {
        cerr << "Failed to get console window handle!" << endl;
        return;
    }

    // Get screen resolution
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);
    int screenWidth = screenRect.right;
    int screenHeight = screenRect.bottom;

    // Get the size of the console window
    RECT consoleRect;
    GetWindowRect(consoleWindow, &consoleRect);

    // Get the size of the console window's client area
    RECT clientRect;
    GetClientRect(consoleWindow, &clientRect);

    // Calculate the width and height of the non-client area (title bar, borders)
    int borderWidth = (consoleRect.right - consoleRect.left) - (clientRect.right - clientRect.left);
    int borderHeight = (consoleRect.bottom - consoleRect.top) - (clientRect.bottom - clientRect.top);

    // Calculate console width and height
    int consoleWidth = consoleRect.right - consoleRect.left;
    int consoleHeight = consoleRect.bottom - consoleRect.top;

    // Calculate the new position for the console (centered, including borders)
    int posX = (screenWidth / 2) - (consoleWidth / 2);
    int posY = (screenHeight / 2) - (consoleHeight / 2);

    // Move the console window to the new position
    SetWindowPos(consoleWindow, HWND_TOP, posX, posY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}
void ConsoleCursor(bool visibility) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visibility;
    SetConsoleCursorInfo(consoleHandle, &info);
}

//Game Functions
void Setup() {
    gameOver = false;
    pause = false;
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
        bodyX = new int[maxBody];
    }

    if (bodyY == nullptr) {
        bodyY = new int[maxBody];
    }
}
void Draw() {
    string frame;

    frame += "\n\tRussel Bite\nBy SHAHRIAR TECHNOLOGIES LTD.\n\n";

    frame += string((width + 2), '=') + "\n";
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (j == 0) {
                frame += "|";
            }

            if (i == snakeY && j == snakeX) {
                frame += "0";
            }
            else if (i == foodY && j == foodX) {
                frame += "*";
            }
            else {
                bool print = false;
                for (int k = 0; k < bodyC; k++) {
                    if (bodyX[k] == j && bodyY[k] == i) {
                        print = true;
                        frame += "o";
                    }
                }

                if (print == false) {
                    frame += " ";
                }
            }

            if (j == (width - 1)) {
                frame += "|";
            }
        }
        frame += "\n";
    }
    frame += string((width + 2), '=') + "\n";

    frame += "Score: " + to_string(score) + "\n";
    frame += "Game Level: " + level + "\n";
    frame += "Wall Restriction: " + wall + "\n";

    if (pause == true) {
        frame += "\nGAME PAUSED. Press F to resume game.\n";
    }
    else {
        frame += "\nUse W A S D key to move. To pause game press F. To exit game press X\n";
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    cout << frame;
}
void Input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'f') {
            if (pause == false) {
                pause = true;
                if (clsTrack == nullptr) {
                    clsTrack = new int(0);
                }
            }
            else {
                pause = false;
                if (clsTrack != nullptr) {
                    delete clsTrack;
                    clsTrack = nullptr;
                }
            }
        }
        else {
            if (pause == false) {
                if (key == 'a') {
                    dir = LEFT;
                }
                else if (key == 'd') {
                    dir = RIGHT;
                }
                else if (key == 'w') {
                    dir = UP;
                }
                else if (key == 's') {
                    dir = DOWN;
                }
                else if (key == 'x') {
                    gameOver = true;
                    over = 'e';
                }
            }
        }
    }
}
void Logic() {
    //snake body memory logic
    if(bodyC >= maxBody) {
        maxBody += 10;

        int* tempBodyX = new int[maxBody];
        int* tempBodyY = new int[maxBody];

        for (int i = 0; i < bodyC; i++) {
            tempBodyX[i] = bodyX[i];
            tempBodyY[i] = bodyY[i];
        }

        delete[] bodyX;
        delete[] bodyY;

        bodyX = tempBodyX;
        bodyY = tempBodyY;
    }

    //snake body logic
    for (int i = bodyC; i > 0; i--) {
        bodyX[i] = bodyX[i - 1];
        bodyY[i] = bodyY[i - 1];
    }
    bodyX[0] = snakeX;
    bodyY[0] = snakeY;

    //input logic
    if (dir == LEFT) {
        snakeX--;
    }
    else if (dir == RIGHT) {
        snakeX++;
    }
    else if (dir == UP) {
        snakeY--;
    }
    else if (dir == DOWN) {
        snakeY++;
    }


    //wall hit logic
    if (wall == "Enabled") {
        if (snakeX < 0 || snakeX > width - 1 || snakeY < 0 || snakeY > height - 1) {
            gameOver = true;
            over = 'w';
        }
    }
    else if (wall == "Disabled") {
        if (snakeX >= width) {
            snakeX = 0;
        }
        else if (snakeX < 0) {
            snakeX = width - 1;
        }

        if (snakeY >= height) {
            snakeY = 0;
        }
        else if (snakeY < 0) {
            snakeY = height - 1;
        }
    }

    //body hit logic
    for (int i = 0; i < bodyC; i++) {
        if (bodyX[i] == snakeX && bodyY[i] == snakeY) {
            gameOver = true;
            over = 'b';
            break;
        }
    }

    //food eating logic
    if (snakeX == foodX && snakeY == foodY) {
        score += 5;
        bodyC++;
        foodX = rand() % width;
        foodY = rand() % height;
    }
}
void Over() {
    char op;

    ConsoleCursor(true);

    if (bodyX != nullptr) {
        delete[] bodyX;
        bodyX = nullptr;
    }

    if (bodyY != nullptr) {
        delete[] bodyY;
        bodyY = nullptr;
    }

    if (clsTrack != nullptr) {
        delete clsTrack;
        clsTrack = nullptr;
    }

    while (true) {
        system("cls");

        cout << endl << "\tRussel Bite" << endl;
        cout << "By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

        cout << "\tGAME OVER" << endl;
        cout << "Your Score: " << score << endl;

        if (over == 'w') {
            cout << "Your snake hit the wall and died." << endl << endl;
        }
        else if (over == 'b') {
            cout << "Your snake hit its own body and died." << endl << endl;
        }
        else if (over == 'e') {
            cout << "You pressed exit button (X key)." << endl << endl;
        }

        cout
            << "1. Play Again" << endl
            << "2. Exit" << endl
            << endl;
        cout << "Enter option: ";
        cin >> op;

        if (op == '1') {
            return;
        }
        else if (op == '2') {
            settings = false;
            return;
        }
        else {
            system("cls");

            cout << endl << "\tRussel Bite" << endl;
            cout << "By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

            cout << "\t* Invalid Input!" << endl;
            cout << "\t* Press any key to try again....";

            _getch();
        }
    }
}
void DevInfo() {
    system("cls");

    cout << endl << endl << "   Thank You For Playing Russel Bite." << endl << endl << endl;

    cout << "\tDeveloper Informations" << endl;
    cout << "Developer Name: Shahriar Ali Siam" << endl
        << "Organization: Shahriar Technologies LTD." << endl
        << "Education: BSc. CSE, American International University-Bangladesh" << endl
        << "Email (Personal): shahriaraliseam@gmail.com" << endl
        << "Email (Edu): 23-53004-3@student.aiub.edu" << endl
        << "GitHub: shahriar-siam-2k2" << endl
    << endl << endl;

    cout << "\tProgram Informations" << endl;
    cout << "Program Name: Russel Bite" << endl
        << "Program Type: Console Game (Windows)" << endl
        << "Program Language: C++" << endl
        << "Topics Used: Basics of C++ & Data Structure (Dynamic Array, Pointer)" << endl
        << "Extra Topics Used: Console Customizations" << endl
        << "(Disabling full screen button & resizing, custom console sizing, centering console, customized font size & cursor)" << endl
        << "Program Features: Memory & CPU Efficiency" << endl
        << "Source Code: https://t.ly/3Qge8" << endl
    << endl << endl;

    cout << "Press any key to close...";
    _getch();
}

int main() {
    char op;
    int speed;
    settings = true;

    DisableConsoleFullscreenButton();
    DisableConsoleResize();
    SetConsoleSize(700, 700);
    SetConsoleFontSize(22);
    CenterConsole();

    while (settings == true) {
        system("cls");

        cout << endl << "\tRussel Bite" << endl;
        cout << "By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

        cout << "Game Levels (Represents snake moving speed)" << endl;
        cout
            << "1. Easy" << endl
            << "2. Medium" << endl
            << "3. Hard" << endl
            << endl;
        cout << "Enter option: ";
        cin >> op;

        if (op == '1' || op == '2' || op == '3') {
            if (op == '1') {
                level = "Easy";
                speed = 200;
            }
            else if (op == '2') {
                level = "Medium";
                speed = 150;
            }
            else if (op == '3') {
                level = "Hard";
                speed = 80;
            }

            while (settings == true) {
                system("cls");

                cout << endl << "\tRussel Bite" << endl;
                cout << "By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

                cout << "Wall Restriction" << endl;
                cout
                    << "1. Enable (If snake hits wall then it will die)" << endl
                    << "2. Disable (The snake will pass through the wall)" << endl
                    << endl;
                cout << "Enter option: ";
                cin >> op;

                if (op == '1' || op == '2') {
                    if (op == '1') {
                        wall = "Enabled";
                    }
                    else if (op == '2') {
                        wall = "Disabled";
                    }

                    system("cls");

                    Setup();

                    while (gameOver == false) {
                        if (pause == true) {
                            if (clsTrack != nullptr && *clsTrack == 0) {
                                system("cls");
                                Draw();
                                (*clsTrack)++;
                            }
                            Input();
                        }
                        else {
                            Draw();
                            Input();
                            Logic();
                        }
                        Sleep(speed);
                    }

                    Over();
                    break;
                }
                else {
                    system("cls");

                    cout << endl << "\tRussel Bite" << endl;
                    cout << "By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

                    cout << "\t* Invalid Input!" << endl;
                    cout << "\t* Press any key to try again....";

                    _getch();
                }
            }
        }
        else {
            system("cls");

            cout << endl << "\tRussel Bite" << endl;
            cout << "By SHAHRIAR TECHNOLOGIES LTD." << endl << endl;

            cout << "\t* Invalid Input!" << endl;
            cout << "\t* Press any key to try again....";

            _getch();
        }
    }

    DevInfo();

    return 0;
}