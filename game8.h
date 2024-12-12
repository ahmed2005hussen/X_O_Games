//
// Created by ahmed on 10/12/2024.
//
#include"BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include<algorithm>
#include <cstdlib>
#include <ctime>
#include<fstream>

#ifndef XO_GAME8_H
#define XO_GAME8_H
//
using namespace std;

template<typename T>
class board8 : public Board<T> {
public:
    board8();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();

    ~board8();
};


template<typename T>
bool board8<T>::game_is_over() {
    return is_win() || is_draw();
}

template<typename T>
bool board8<T>::is_draw() {
    return (!is_win() && this->n_moves == 9);
}

template<typename T>
bool board8<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                return true;
            }
        }
    }

    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i <= this->rows - 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                return true;
            }
        }
    }

    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] &&
         this->board[0][0] != ' ') ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] &&
         this->board[0][2] != ' ')) {
        return true;
    }
    return false;
}

template<typename T>
void board8<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n--------------";
    }
    cout << endl;
}

template<typename T>
bool board8<T>::update_board(int x, int y, T symbol) {
    if ((this->board[x][y] != 'X' && this->board[x][y] != 'O')) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    return false;
}

template<typename T>
board8<T>::board8() {
    this->columns = 3;
    this->rows = 3;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;

}

template<typename T>
board8<T>::~board8() {
    delete this->board;
}


template<typename T>
class unlimated_board : public Board<T> {
public:

    int checkwin();

    board8<T> b = new board8<T>();


    unlimated_board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

template<typename T>
int unlimated_board<T>::checkwin() {
    static int a1 = 1;
    static int a2 = 1;
    static int a3 = 1;
    static int a4 = 1;
    static int a5 = 1;
    static int a6 = 1;
    static int a7 = 1;
    static int a8 = 1;
    static int a9 = 1;
    if (a1) {
        if (this->board[0][0] != ' ' && this->board[0][0] == this->board[0][1] &&
            this->board[0][0] == this->board[0][2]) {
            a1 = 0;
            return 1;
        }
        if (this->board[1][0] != ' ' && this->board[1][0] == this->board[1][1] &&
            this->board[1][0] == this->board[1][2]) {
            a1 = 0;
            return 1;
        }
        if (this->board[2][0] != ' ' && this->board[2][0] == this->board[2][1] &&
            this->board[2][0] == this->board[2][2]) {
            a1 = 0;
            return 1;
        }
        if (this->board[0][0] != ' ' && this->board[0][0] == this->board[1][0] &&
            this->board[0][0] == this->board[2][0]) {
            a1 = 0;
            return 1;
        }
        if (this->board[0][1] != ' ' && this->board[0][1] == this->board[1][1] &&
            this->board[0][1] == this->board[2][1]) {
            a1 = 0;
            return 1;
        }
        if (this->board[0][2] != ' ' && this->board[0][2] == this->board[1][2] &&
            this->board[0][2] == this->board[2][2]) {
            a1 = 0;
            return 1;
        }
        if (this->board[0][0] != ' ' && this->board[0][0] == this->board[1][1] &&
            this->board[0][0] == this->board[2][2]) {
            a1 = 0;
            return 1;
        }
        if (this->board[0][2] != ' ' && this->board[0][2] == this->board[1][1] &&
            this->board[0][2] == this->board[2][0]) {
            a1 = 0;
            return 1;
        }
    }

    if (a2) {
        if (this->board[0][3] != ' ' && this->board[0][3] == this->board[0][4] &&
            this->board[0][3] == this->board[0][5]) {
            a2 = 0;
            return 2;
        }
        if (this->board[1][3] != ' ' && this->board[1][3] == this->board[1][4] &&
            this->board[1][3] == this->board[1][5]) {
            a2 = 0;
            return 2;
        }
        if (this->board[2][3] != ' ' && this->board[2][3] == this->board[2][4] &&
            this->board[2][3] == this->board[2][5]) {
            a2 = 0;
            return 2;
        }
        if (this->board[0][3] != ' ' && this->board[0][3] == this->board[1][3] &&
            this->board[0][3] == this->board[2][3]) {
            a2 = 0;
            return 2;
        }
        if (this->board[0][4] != ' ' && this->board[0][4] == this->board[1][4] &&
            this->board[0][4] == this->board[2][4]) {
            a2 = 0;
            return 2;
        }
        if (this->board[0][5] != ' ' && this->board[0][5] == this->board[1][5] &&
            this->board[0][5] == this->board[2][5]) {
            a2 = 0;
            return 2;
        }
        if (this->board[0][3] != ' ' && this->board[0][3] == this->board[1][4] &&
            this->board[0][3] == this->board[2][5]) {
            a2 = 0;
            return 2;
        }
        if (this->board[0][5] != ' ' && this->board[0][5] == this->board[1][4] &&
            this->board[0][5] == this->board[2][3]) {
            a2 = 0;
            return 2;
        }
    }

    if (a3) {
        if (this->board[0][6] != ' ' && this->board[0][6] == this->board[0][7] &&
            this->board[0][6] == this->board[0][8]) {
            a3 = 0;
            return 3;
        }
        if (this->board[1][6] != ' ' && this->board[1][6] == this->board[1][7] &&
            this->board[1][6] == this->board[1][8]) {
            a3 = 0;
            return 3;
        }
        if (this->board[2][6] != ' ' && this->board[2][6] == this->board[2][7] &&
            this->board[2][6] == this->board[2][8]) {
            a3 = 0;
            return 3;
        }
        if (this->board[0][6] != ' ' && this->board[0][6] == this->board[1][6] &&
            this->board[0][6] == this->board[2][6]) {
            a3 = 0;
            return 3;
        }
        if (this->board[0][7] != ' ' && this->board[0][7] == this->board[1][7] &&
            this->board[0][7] == this->board[2][7]) {
            a3 = 0;
            return 3;
        }
        if (this->board[0][8] != ' ' && this->board[0][8] == this->board[1][8] &&
            this->board[0][8] == this->board[2][8]) {
            a3 = 0;
            return 3;
        }
        if (this->board[0][6] != ' ' && this->board[0][6] == this->board[1][7] &&
            this->board[0][6] == this->board[2][8]) {
            a3 = 0;
            return 3;
        }
        if (this->board[0][8] != ' ' && this->board[0][8] == this->board[1][7] &&
            this->board[0][8] == this->board[2][6]) {
            a3 = 0;
            return 3;
        }
    }

    if (a4) {
        if (this->board[3][0] != ' ' && this->board[3][0] == this->board[3][1] &&
            this->board[3][0] == this->board[3][2]) {
            a4 = 0;
            return 4;
        }
        if (this->board[4][0] != ' ' && this->board[4][0] == this->board[4][1] &&
            this->board[4][0] == this->board[4][2]) {
            a4 = 0;
            return 4;
        }
        if (this->board[5][0] != ' ' && this->board[5][0] == this->board[5][1] &&
            this->board[5][0] == this->board[5][2]) {
            a4 = 0;
            return 4;
        }
        if (this->board[3][0] != ' ' && this->board[3][0] == this->board[4][0] &&
            this->board[3][0] == this->board[5][0]) {
            a4 = 0;
            return 4;
        }
        if (this->board[3][1] != ' ' && this->board[3][1] == this->board[4][1] &&
            this->board[3][1] == this->board[5][1]) {
            a4 = 0;
            return 4;
        }
        if (this->board[3][2] != ' ' && this->board[3][2] == this->board[4][2] &&
            this->board[3][2] == this->board[5][2]) {
            a4 = 0;
            return 4;
        }
        if (this->board[3][0] != ' ' && this->board[3][0] == this->board[4][1] &&
            this->board[3][0] == this->board[5][2]) {
            a4 = 0;
            return 4;
        }
        if (this->board[3][2] != ' ' && this->board[3][2] == this->board[4][1] &&
            this->board[3][2] == this->board[5][0]) {
            a4 = 0;
            return 4;
        }
    }

    if (a5) {
        if (this->board[3][3] != ' ' && this->board[3][3] == this->board[3][4] &&
            this->board[3][3] == this->board[3][5]) {
            a5 = 0;
            return 5;
        }
        if (this->board[4][3] != ' ' && this->board[4][3] == this->board[4][4] &&
            this->board[4][3] == this->board[4][5]) {
            a5 = 0;
            return 5;
        }
        if (this->board[5][3] != ' ' && this->board[5][3] == this->board[5][4] &&
            this->board[5][3] == this->board[5][5]) {
            a5 = 0;
            return 5;
        }
        if (this->board[3][3] != ' ' && this->board[3][3] == this->board[4][3] &&
            this->board[3][3] == this->board[5][3]) {
            a5 = 0;
            return 5;
        }
        if (this->board[3][4] != ' ' && this->board[3][4] == this->board[4][4] &&
            this->board[3][4] == this->board[5][4]) {
            a5 = 0;
            return 5;
        }
        if (this->board[3][5] != ' ' && this->board[3][5] == this->board[4][5] &&
            this->board[3][5] == this->board[5][5]) {
            a5 = 0;
            return 5;
        }
        if (this->board[3][3] != ' ' && this->board[3][3] == this->board[4][4] &&
            this->board[3][3] == this->board[5][5]) {
            a5 = 0;
            return 5;
        }
        if (this->board[3][5] != ' ' && this->board[3][5] == this->board[4][4] &&
            this->board[3][5] == this->board[5][3]) {
            a5 = 0;
            return 5;
        }
    }

    if (a6) {
        if (this->board[3][6] != ' ' && this->board[3][6] == this->board[3][7] &&
            this->board[3][6] == this->board[3][8]) {
            a6 = 0;
            return 6;
        }
        if (this->board[4][6] != ' ' && this->board[4][6] == this->board[4][7] &&
            this->board[4][6] == this->board[4][8]) {
            a6 = 0;
            return 6;
        }
        if (this->board[5][6] != ' ' && this->board[5][6] == this->board[5][7] &&
            this->board[5][6] == this->board[5][8]) {
            a6 = 0;
            return 6;
        }
        if (this->board[3][6] != ' ' && this->board[3][6] == this->board[4][6] &&
            this->board[3][6] == this->board[5][6]) {
            a6 = 0;
            return 6;
        }
        if (this->board[3][7] != ' ' && this->board[3][7] == this->board[4][7] &&
            this->board[3][7] == this->board[5][7]) {
            a6 = 0;
            return 6;
        }
        if (this->board[3][8] != ' ' && this->board[3][8] == this->board[4][8] &&
            this->board[3][8] == this->board[5][8]) {
            a6 = 0;
            return 6;
        }
        if (this->board[3][6] != ' ' && this->board[3][6] == this->board[4][7] &&
            this->board[3][6] == this->board[5][8]) {
            a6 = 0;
            return 6;
        }
        if (this->board[3][8] != ' ' && this->board[3][8] == this->board[4][7] &&
            this->board[3][8] == this->board[5][6]) {
            a6 = 0;
            return 6;
        }
    }

    if (a7) {
        if (this->board[6][0] != ' ' && this->board[6][0] == this->board[6][1] &&
            this->board[6][0] == this->board[6][2]) {
            a7 = 0;
            return 7;
        }
        if (this->board[7][0] != ' ' && this->board[7][0] == this->board[7][1] &&
            this->board[7][0] == this->board[7][2]) {
            a7 = 0;
            return 7;
        }
        if (this->board[8][0] != ' ' && this->board[8][0] == this->board[8][1] &&
            this->board[8][0] == this->board[8][2]) {
            a7 = 0;
            return 7;
        }
        if (this->board[6][0] != ' ' && this->board[6][0] == this->board[7][0] &&
            this->board[6][0] == this->board[8][0]) {
            a7 = 0;
            return 7;
        }
        if (this->board[6][1] != ' ' && this->board[6][1] == this->board[7][1] &&
            this->board[6][1] == this->board[8][1]) {
            a7 = 0;
            return 7;
        }
        if (this->board[6][2] != ' ' && this->board[6][2] == this->board[7][2] &&
            this->board[6][2] == this->board[8][2]) {
            a7 = 0;
            return 7;
        }
        if (this->board[6][0] != ' ' && this->board[6][0] == this->board[7][1] &&
            this->board[6][0] == this->board[8][2]) {
            a7 = 0;
            return 7;
        }
        if (this->board[6][2] != ' ' && this->board[6][2] == this->board[7][1] &&
            this->board[6][2] == this->board[8][0]) {
            a7 = 0;
            return 7;
        }
    }

    if (a8) {
        if (this->board[6][3] != ' ' && this->board[6][3] == this->board[6][4] &&
            this->board[6][3] == this->board[6][5]) {
            a8 = 0;
            return 8;
        }
        if (this->board[7][3] != ' ' && this->board[7][3] == this->board[7][4] &&
            this->board[7][3] == this->board[7][5]) {
            a8 = 0;
            return 8;
        }
        if (this->board[8][3] != ' ' && this->board[8][3] == this->board[8][4] &&
            this->board[8][3] == this->board[8][5]) {
            a8 = 0;
            return 8;
        }
        if (this->board[6][3] != ' ' && this->board[6][3] == this->board[7][3] &&
            this->board[6][3] == this->board[8][3]) {
            a8 = 0;
            return 8;
        }
        if (this->board[6][4] != ' ' && this->board[6][4] == this->board[7][4] &&
            this->board[6][4] == this->board[8][4]) {
            a8 = 0;
            return 8;
        }
        if (this->board[6][5] != ' ' && this->board[6][5] == this->board[7][5] &&
            this->board[6][5] == this->board[8][5]) {
            a8 = 0;
            return 8;
        }
        if (this->board[6][3] != ' ' && this->board[6][3] == this->board[7][4] &&
            this->board[6][3] == this->board[8][5]) {
            a8 = 0;
            return 8;
        }
        if (this->board[6][5] != ' ' && this->board[6][5] == this->board[7][4] &&
            this->board[6][5] == this->board[8][3]) {
            a8 = 0;
            return 8;
        }
    }

    if (a9) {
        if (this->board[6][6] != ' ' && this->board[6][6] == this->board[6][7] &&
            this->board[6][6] == this->board[6][8]) {
            a9 = 0;
            return 9;
        }
        if (this->board[7][6] != ' ' && this->board[7][6] == this->board[7][7] &&
            this->board[7][6] == this->board[7][8]) {
            a9 = 0;
            return 9;
        }
        if (this->board[8][6] != ' ' && this->board[8][6] == this->board[8][7] &&
            this->board[8][6] == this->board[8][8]) {
            a9 = 0;
            return 9;
        }
        if (this->board[6][6] != ' ' && this->board[6][6] == this->board[7][6] &&
            this->board[6][6] == this->board[8][6]) {
            a9 = 0;
            return 9;
        }
        if (this->board[6][7] != ' ' && this->board[6][7] == this->board[7][7] &&
            this->board[6][7] == this->board[8][7]) {
            a9 = 0;
            return 9;
        }
        if (this->board[6][8] != ' ' && this->board[6][8] == this->board[7][8] &&
            this->board[6][8] == this->board[8][8]) {
            a9 = 0;
            return 9;
        }
        if (this->board[6][6] != ' ' && this->board[6][6] == this->board[7][7] &&
            this->board[6][6] == this->board[8][8]) {
            a9 = 0;
            return 9;
        }
        if (this->board[6][8] != ' ' && this->board[6][8] == this->board[7][7] &&
            this->board[6][8] == this->board[8][6]) {
            a9 = 0;
            return 9;
        }
    }
    return 0;

}

template<typename T>
bool unlimated_board<T>::game_is_over() {
    return b.is_win() || b.is_draw();
}

template<typename T>
bool unlimated_board<T>::is_draw() {
    return b.is_draw();

}

template<typename T>
bool unlimated_board<T>::is_win() {
    return (b.is_win());
}

template<typename T>
void unlimated_board<T>::display_board() {

    cout << "the ultimate board" << endl;
    cout << endl;
    cout << "y: 0   1   2       3   4   5       6   7   8    ";
    for (int i = 0; i < this->rows; i++) {
        if (i == 3 || i == 6) {
            cout << endl << endl;;
        }
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << this->board[i][j] << " |";
            if (j == 8) {
                cout << "  " << i;
            }
            if (j == 2 || j == 5) {
                cout << "   |";
            }
        }
        cout << "\n--------------   -------------   --------------   ";
    }
    cout << endl << endl;
    cout << "The main board " << endl;
    b.display_board();
    cout << endl;
    cout << endl;


}

template<typename T>
bool unlimated_board<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < 9 && y >= 0 && y < 9 && (this->board[x][y] != 'X' && this->board[x][y] != 'O')) {
        this->board[x][y] = toupper(symbol);
        int c = checkwin();
        if (c != 0) {
            if (c == 1) {
                b.update_board(0, 0, symbol);
            }
            if (c == 2) {
                b.update_board(0, 1, symbol);

            }
            if (c == 3) {
                b.update_board(0, 2, symbol);

            }
            if (c == 4) {
                b.update_board(1, 0, symbol);

            }
            if (c == 5) {
                b.update_board(1, 1, symbol);

            }
            if (c == 6) {
                b.update_board(1, 2, symbol);

            }
            if (c == 7) {
                b.update_board(2, 0, symbol);

            }
            if (c == 8) {
                b.update_board(2, 1, symbol);


            }
            if (c == 9) {
                b.update_board(2, 2, symbol);

            }

        }

        this->n_moves++;
        return true;
    }
    return false;
}

template<typename T>
unlimated_board<T>::unlimated_board():b() {

    this->columns = 9;
    this->rows = 9;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;
}

//...............

template<typename T>
class player_8 : public Player<T> {
public:
    player_8(string name, T symbol);

    void getmove(int &x, int &y);
};

template<typename T>
player_8<T>::player_8(string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void player_8<T>::getmove(int &x, int &y) {
    cout << "enter x " << endl;
    cin >> x;
    cout << "enter y " << endl;
    cin >> y;

}




template<typename T>
class player_Random_8 : public RandomPlayer<T> {
public:
    player_Random_8(T symbol);

    void getmove(int &x, int &y);
};

template<typename T>
void player_Random_8<T>::getmove(int &x, int &y) {
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % 9;
    y = rand() % 9;
}

template<typename T>
player_Random_8<T>::player_Random_8(T symbol):RandomPlayer<T>(symbol) {}

#endif //XO_GAME8_H
