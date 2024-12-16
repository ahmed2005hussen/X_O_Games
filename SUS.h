#ifndef SUS_H
#define SUS_H

#include "BoardGame_Classes.h"

template <typename T>
class SUS_Board :public Board<T> {
public:
    SUS_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class SUS_Player : public Player<T> {
public:
    SUS_Player(string name, T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class SUS_Random_Player : public RandomPlayer<T> {
public:
    SUS_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

// -------------------------------- IMPLEMENTATION --------------------------------

#include <iostream>
#include <iomanip>
#include <cctype>  
#include <string>

using namespace std;

int count1 = 0;
int count2 = 0;

// Constructor for X_O_Board
template <typename T>
SUS_Board<T>::SUS_Board() {
    this->rows = this->columns = 3;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool SUS_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < this->rows; i++) {
            if (this->board[i][0] == 'S' && this->board[i][1] == 'U' && this->board[i][2] == 'S') {
                count1++;
            }
            if (this->board[i][0] == 'U' && this->board[i][1] == 'S' && this->board[i][2] == 'U') {
                count2++;
            }
        }

        for (int i = 0; i < this->columns; i++) {
            if (this->board[0][i] == 'S' && this->board[1][i] == 'U' && this->board[2][i] == 'S') {
                count1++;
            }
            if (this->board[0][i] == 'U' && this->board[1][i] == 'S' && this->board[2][i] == 'U') {
                count2++;
            }
        }

        if (this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') {
            count1++;
        }
        if (this->board[0][2] == 'S' && this->board[1][1] == 'U' && this->board[2][0] == 'S') {
            count1++;
        }

        if (this->board[0][0] == 'U' && this->board[1][1] == 'S' && this->board[2][2] == 'U') {
            count2++;
        }
        if (this->board[0][2] == 'U' && this->board[1][1] == 'S' && this->board[2][0] == 'U') {
            count2++;
        }

        cout << "Player 1's count : " << count1 << endl;
        cout << "Player 2's count : " << count2 << endl;

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void SUS_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == 0) {
                cout << "(" << i << "," << j << ")";
            }
            else {
                cout << "  " << this->board[i][j] << "  ";
            }
            cout << " |";
        }
        cout << "\n-----------------------";
    }
    cout << endl;
}


// Returns true if there is any winner
template <typename T>
bool SUS_Board<T>::is_win() {

    if (this->n_moves < this->rows * this->columns) {
        return false; 
    }

    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] == 'S' && this->board[i][1] == 'U' && this->board[i][2] == 'S') {
            count1++;
        }
    }

    for (int i = 0; i < this->columns; i++) {
        if (this->board[0][i] == 'S' && this->board[1][i] == 'U' && this->board[2][i] == 'S') {
            count1++;
        }
    }

    if (this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') {
        count1++;
    }
    if (this->board[0][2] == 'S' && this->board[1][1] == 'U' && this->board[2][0] == 'S') {
        count1++;
    }

    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] == 'U' && this->board[i][1] == 'S' && this->board[i][2] == 'U') {
            count2++; 
        }
    }

    for (int i = 0; i < this->columns; i++) {
        if (this->board[0][i] == 'U' && this->board[1][i] == 'S' && this->board[2][i] == 'U') {
            count2++; 
        }
    }

    if (this->board[0][0] == 'U' && this->board[1][1] == 'S' && this->board[2][2] == 'U') {
        count2++; 
    }
    if (this->board[0][2] == 'U' && this->board[1][1] == 'S' && this->board[2][0] == 'U') {
        count2++; 
    }

    if (count1 > count2) {
        return true;  
    }
    else if (count2 > count1) {
        return false; 
    }

    return false; 
}


template <typename T>
bool SUS_Board<T>::is_draw() {
    if (is_win()) return false;

    if (this->n_moves == this->rows * this->columns) {
        return true;
    }

    return false;
}


template <typename T>
bool SUS_Board<T>::game_is_over() {
    if (is_win()) {
        return true;
    }

    if (this->n_moves == this->rows * this->columns) {
        return true;
    }

    return false; 
}


//--------------------------------------

// Constructor for X_O_Player
template <typename T>
SUS_Player<T>::SUS_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void SUS_Player<T>::getmove(int& x, int& y) {
    cout << "\n" << this->name << ", enter your move : ";
    char move = '0';
    cin >> move;

    if (move == '1') {
        x = 0;
        y = 0;
    }
    else if (move == '2') {
        x = 0;
        y = 1;
    }
    else if (move == '3') {
        x = 0;
        y = 2;
    }
    else if (move == '4') {
        x = 1;
        y = 0;
    }
    else if (move == '5') {
        x = 1;
        y = 1;
    }
    else if (move == '6') {
        x = 1;
        y = 2;
    }
    else if (move == '7') {
        x = 2;
        y = 0;
    }
    else if (move == '8') {
        x = 2;
        y = 1;
    }
    else if (move == '9') {
        x = 2;
        y = 2;
    }
    else {
        x = 0;
        y = 0;
    }

}

// Constructor for X_O_Random_Player
template <typename T>
SUS_Random_Player<T>::SUS_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void SUS_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 3;  
    y = rand() % 3;
}

#endif
