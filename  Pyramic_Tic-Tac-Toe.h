#ifndef _3X3X_O_H
#define _3X3X_O_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()
#include <cstdlib> // for srand and rand
#include <ctime>   // for time

using namespace std;

//----------------------------------------

template<typename T>
class pyramid : public Board<T> {
public:
    pyramid();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

//----------------------------------------
// تعريف فئة X_O_Player
template<typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player(string name, T symbol);

    void getmove(int &x, int &y);
};

//----------------------------------------
// تعريف فئة X_O_Random_Player
template<typename T>
class X_O_Random_Player : public RandomPlayer<T> {
public:
    X_O_Random_Player(T symbol);

    void getmove(int &x, int &y);
};

//----------------------------------------

// class pyramid :

template<typename T>
pyramid<T>::pyramid() {
    this->rows = 3;
    this->columns = 5;
    this->board = new char *[this->rows];
    int counter = 1;
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            if (i == 0 && j == 2) {
                this->board[i][j] = '0' + counter;
                counter++;
            } else if (i == 1 && j != 0 && j != 4) {
                this->board[i][j] = '0' + counter;
                counter++;
            } else if (i == 2) {
                this->board[i][j] = '0' + counter;
                counter++;
            } else {
                this->board[i][j] = ' ';
            }
        }
    }

    this->n_moves = 0;
}

template<typename T>
bool pyramid<T>::update_board(int x, int y, T symbol) {

    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] != ' ' && (this->board[x][y]!='X' && this->board[x][y]!='O')) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    return false;
}


template<typename T>
void pyramid<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-------------------------";
    }
    cout << endl;
}

template<typename T>
bool pyramid<T>::is_win() {
    // checks rows :
    if (this->board[1][1] == this->board[1][2] && this->board[1][2] == this->board[1][3])return true;
    if (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2])return true;
    if (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3])return true;
    if (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4])return true;

    // columns :
    if (this->board[0][2] == this->board[1][2] && this->board[1][2] == this->board[2][2])return true;
    // diagolans:

    if (this->board[0][2] == this->board[1][3] && this->board[1][3] == this->board[2][4])return true;
    if (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])return true;

    return false;
}

template<typename T>
bool pyramid<T>::is_draw() {
    return this->n_moves == 9 && !is_win();
}

template<typename T>
bool pyramid<T>::game_is_over() {
    return is_win() || is_draw();
}

//----------------------------------------
// تنفيذ فئة X_O_Player

template<typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void X_O_Player<T>::getmove(int &x, int &y) {
    cout << "\n" << this->name << ", enter your move : ";
    char move = '0';
    cin >> move;
    if (move == '1') {
        x = 0;
        y = 2;
    } else if (move == '2') {
        x = 1;
        y = 1;
    } else if (move == '3') {
        x = 1;
        y = 2;
    } else if (move == '4') {
        x = 1;
        y = 3;
    } else if (move == '5') {
        x = 2;
        y = 0;
    } else if (move == '6') {
        x = 2;
        y = 1;
    } else if (move == '7') {
        x = 2;
        y = 2;
    } else if (move == '8') {
        x = 2;
        y = 3;
    } else if (move == '9') {
        x = 2;
        y = 4;
    } else {
        x = 0;
        y = 0;
    }

}

//----------------------------------------
// تنفيذ فئة X_O_Random_Player

template<typename T>
X_O_Random_Player<T>::X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {}

template<typename T>
void X_O_Random_Player<T>::getmove(int &x, int &y) {
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % 3;
    y = rand() % 5;
}

#endif //_3X3X_O_H
