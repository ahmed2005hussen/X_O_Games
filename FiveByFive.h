#ifndef _FiveByFive_H
#define _FiveByFive_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <cctype> // for toupper()
#include <cstdlib>
#include <ctime>

using namespace std;

static int countx = 0;
static int counto = 0;

template<typename T>
class FiveByFive_Board : public Board<T> {
public:
    FiveByFive_Board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

template<typename T>
class FiveByFive_Player : public Player<T> {
public:
    FiveByFive_Player(string name, T symbol);

    void getmove(int &x, int &y);
};

template<typename T>
class FiveByFive_Random_Player : public RandomPlayer<T> {
public:
    FiveByFive_Random_Player(T symbol);

    void getmove(int &x, int &y);
};

// -------------------- IMPLEMENTATION --------------------

// Constructor for FiveByFive_Board
template<typename T>
FiveByFive_Board<T>::FiveByFive_Board() {
    this->rows = 5;
    this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; ++i) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; ++j) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;
}

// Update the board with the player's move
template<typename T>
bool FiveByFive_Board<T>::update_board(int x, int y, T mark) {
    // Convert 1-based user input to 0-based indexing
    x -= 1;
    y -= 1;

    // Check bounds and if the cell is empty
    if ((x >= 0 && x < this->rows && y >= 0 && y < this->columns) && (this->board[x][y] == ' ')) {
        this->n_moves++;
        this->board[x][y] = toupper(mark);
        return true;
    }
    return false;
}


// Display the current state of the board without coordinates
template<typename T>
void FiveByFive_Board<T>::display_board() {
    // Column numbers above the board
    cout << "   "; // Space for row labels on the left
    for (int j = 1; j <= this->columns; ++j) {
        cout << setw(4) << j;
    }
    cout << "\n---------------------------------";

    for (int i = 0; i < this->rows; ++i) {
        // Row number to the left of the board
        cout << "\n" << setw(2) << i + 1 << " | ";
        for (int j = 0; j < this->columns; ++j) {
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n---------------------------------";
    }
    cout << "\n                                   ";
    cout << endl;
}


// Check if there is a winner
template<typename T>
bool FiveByFive_Board<T>::is_win() {
    if (this->n_moves == 24) {
        // Check rows and columns
        for (int i = 0; i < this->rows; ++i) {
            if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] == 'X') ||
                (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] == 'X')) {
                countx++;
            } else if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] == 'O') ||
                       (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] == 'O')) {
                counto++;
            }
        }
        // Check diagonals
        if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] &&
             this->board[3][3] == this->board[4][4] && this->board[0][0] == 'X') ||
            (this->board[0][4] == this->board[1][3] && this->board[2][2] == this->board[3][1] &&
             this->board[4][0] == 'X')) {
            countx++;
        } else if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] &&
                    this->board[3][3] == this->board[4][4] && this->board[0][0] == 'O') ||
                   (this->board[0][4] == this->board[1][3] && this->board[2][2] == this->board[3][1] &&
                    this->board[4][0] == 'O')) {
            counto++;
        }

        cout << "X Wins: " << countx << endl;
        cout << "O Wins: " << counto << endl;

        return countx > counto || counto > countx;
    }
    return false;
}

// Check if the game is a draw
template<typename T>
bool FiveByFive_Board<T>::is_draw() {
    return (this->n_moves == 24 && !is_win());
}

// Check if the game is over
template<typename T>
bool FiveByFive_Board<T>::game_is_over() {
    if (is_win()) {
        cout << (countx > counto ? "X wins!" : "O wins!") << endl;
        return true;
    }
    if (is_draw()) {
        cout << "It's a draw!" << endl;
        return true;
    }
    return false;
}

// Constructor for FiveByFive_Player
template<typename T>
FiveByFive_Player<T>::FiveByFive_Player(string name, T symbol)
    : Player<T>(name, symbol) {}

// Get the move from the player
template<typename T>
void FiveByFive_Player<T>::getmove(int &x, int &y) {
    cout << "\nPlease enter your move (x and y from 1 to 5): ";
    cin >> x >> y;
}

// Constructor for FiveByFive_Random_Player
template<typename T>
FiveByFive_Random_Player<T>::FiveByFive_Random_Player(T symbol)
    : RandomPlayer<T>(symbol) {
    this->dimension = 5;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); // Seed RNG
}

// Get a random move
template<typename T>
void FiveByFive_Random_Player<T>::getmove(int &x, int &y) {
    x = (rand() % this->dimension) + 1;
    y = (rand() % this->dimension) + 1;
}

#endif