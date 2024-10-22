#include <iostream>
#include <windows.h>
#include <locale>

using namespace std;

const int X1 = 25, Y1 = 8, X2 = 55, Y2 = 18;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw_border() {
    for (int x = X1; x <= X2; x++) {
        gotoxy(x, Y1);
        cout << "-";
        gotoxy(x, Y2);
        cout << "-";
    }

    for (int y = Y1; y <= Y2; y++) {
        gotoxy(X1, y);
        cout << "|";
        gotoxy(X2, y);
        cout << "|";
    }
}

void draw_corners() {
    gotoxy(X1, Y1 - 2);
    cout << "(25, 8)";

    gotoxy(X2, Y1 - 2);
    cout << "(55, 8)";

    gotoxy(X1, Y2 + 1);
    cout << "(25, 18)";

    gotoxy(X2, Y2 + 1);
    cout << "(55, 18)";
}

void display_instructions() {
    gotoxy(10, 2);
    cout << "Стрелка вверх - движение вверх, Стрелка вниз - движение вниз";
}

int main() {
    int x = X1 + 1, y = Y1 + 1;
    char symbol = '*';
    setlocale(LC_ALL, "Ru");
    system("cls");
    display_instructions();
    draw_border();
    draw_corners();

    gotoxy(x, y);
    cout << symbol;

    while (true) {
        gotoxy(x, y);
        cout << " ";

        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (y > Y1 + 1) y--;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if (y < Y2 - 1) y++;
        }

        gotoxy(x, y);
        cout << symbol;

        Sleep(100);
    }

    return 0;
}
