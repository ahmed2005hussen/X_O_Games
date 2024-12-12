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

template <typename T>
class Four_In_Row :public Board<T> {
public:
    Four_In_Row();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();

};

template <typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player(string name, T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class X_O_Random_Player : public RandomPlayer<T> {
public:
    X_O_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//--------------------- IMPLEMENTATION ------------------

// Constructor for Four_In_Row
template <typename T>
Four_In_Row<T>::Four_In_Row() {
    this->rows = 6;
    this->columns = 7;
    this->board = new char* [this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template<typename T>
bool Four_In_Row<T>::update_board(int x, int y, T symbol) {
    // Only update if move is valid
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0) {
        if (this->n_moves == 0 && x != this->rows - 1) {
            cout << "The first move must be in the last row!" << endl;
            return false;
        }
        
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }

    cout << "Invalid move. Please try again." << endl;
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Four_In_Row<T>::display_board() {
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
        cout << "\n---------------------------------------------------";
    }
    cout << endl;
}


template <typename T>
bool Four_In_Row<T>::is_win() {
    // Check rows for a win
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 4; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] &&
                this->board[i][j] == this->board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check columns for a win
    for (int i = 0; i <= this->rows - 4; i++) {
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] &&
                this->board[i][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int i = 0; i <= this->rows - 4; i++) {
        for (int j = 0; j <= this->columns - 4; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] &&
                this->board[i][j] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check diagonals (top-right to bottom-left)
    for (int i = 0; i <= this->rows - 4; i++) {
        for (int j = 3; j < this->columns; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j - 1] &&
                this->board[i][j] == this->board[i + 2][j - 2] &&
                this->board[i][j] == this->board[i + 3][j - 3]) {
                return true;
            }
        }
    }

    return false;
}


// Return true if 9 moves are done and no winner
template <typename T>
bool Four_In_Row<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Four_In_Row<T>::game_is_over() {
    return is_win() || is_draw();
}


//----------------------------------------


// Constructor for X_O_Player
template <typename T>
X_O_Player<T>::X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void X_O_Player<T>::getmove(int& x, int& y) {
    cout << "Enter your move x (0-5): ";
    cin >> x;
    cout << "Enter your move y (0-6): ";
    cin >> y;
}

// Constructor for X_O_Random_Player
template <typename T>
X_O_Random_Player<T>::X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  
}

template <typename T>
void X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % 6;  
    y = rand() % 7;  
}

#endif //_3X3X_O_H
