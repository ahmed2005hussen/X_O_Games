#ifndef XO_NUM__TIC_TAC_TOE_H
#define XO_NUM__TIC_TAC_TOE_H


#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <cctype> // For toupper()
#include <cstdlib> // For srand and rand
#include <ctime>   // For time
#include <numeric> // For accumulate
#include <algorithm> // For find

using namespace std;

vector <int> v1 = { 1, 3, 5, 7, 9 };
vector <int> v2 = { 2, 4, 6, 8 };

//----------------------------------------

template <typename T>
class Num_Board :public Board<T> {
public:
    Num_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();

private:
    bool check_sum(vector<int> l);
};

template <typename T>
class Num_Player : public Player<T> {
public:
    Num_Player(string name, T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class Num_Random_Player : public RandomPlayer<T> {
public:
    Num_Random_Player(T symbol);
    void getmove(int& x, int& y);

private:
    vector<int>& get_available_numbers();
};


//--------------------- IMPLEMENTATION ------------------


// Constructor for Num_Board
template <typename T>
Num_Board<T>::Num_Board() {
    this->rows = this->columns = 3;
    this->board = new T * [this->rows]; 
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0; 
        }
    }
    this->n_moves = 0;
}


template<typename T>
bool Num_Board<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0) {
        vector<int>& availableNums = (symbol % 2 != 0) ? v1 : v2;

        auto it = find(availableNums.begin(), availableNums.end(), symbol);
        if (it == availableNums.end()) {
            cout << "Invalid Number! Please choose a valid number.\n";
            return false;
        }
        this->board[x][y] = symbol;
        availableNums.erase(it);
        this->n_moves++;
        return true;

    }
    cout << "Invalid move! Position is either occupied or out of bounds.\n";
    return false;
}



// Display the board and the pieces on it
template <typename T>
void Num_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            if (this->board[i][j] == 0) {
                cout << "(" << i << "," << j << ") ";
            }
            else {
                cout << "   " << this->board[i][j] << "   ";
            }
            cout << " |";
        }
        cout << "\n--------------------------";
    }
    cout << endl;
}



// Returns true if there is any winner
template <typename T>
bool Num_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        if (check_sum({ this->board[i][0], this->board[i][1], this->board[i][2] }) ||
            check_sum({ this->board[0][i], this->board[1][i], this->board[2][i] })) {
            return true;
        }
    }

    // Check diagonals
    if (check_sum({ this->board[0][0], this->board[1][1], this->board[2][2] }) ||
        check_sum({ this->board[0][2], this->board[1][1], this->board[2][0] })) {
        return true;
    }

    return false;
}

template <typename T>
bool Num_Board<T> ::check_sum(vector <int> l)
{
    return accumulate(l.begin(), l.end(), 0) == 15;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool Num_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Num_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for Num_Player
template <typename T>
Num_Player<T>::Num_Player(string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void Num_Player<T>::getmove(int& x, int& y) {
    cout << "\n" << this->name << "'s turn.\n";

    int num = this->symbol - '0';
    vector<int>& availableNumbers = (num % 2 != 0) ? v1 : v2;

    cout << "Available numbers: ";
    for (int num : availableNumbers) cout << num << " ";

    int chosenNumber;
    cout << "\n" << this->name << ", Enter your move (choose a number): ";
    cin >> chosenNumber;

    auto it = find(availableNumbers.begin(), availableNumbers.end(), chosenNumber);
    if (it == availableNumbers.end()) {
        cout << "Invalid Number! Please choose a valid number.\n";
        x = -1; 
        y = -1;
        return;
    }

    cout << "\n" << this->name << ", enter your position : ";
    char move;
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

    this->symbol = chosenNumber;
}


// Constructor for Num_Random_Player
template <typename T>
Num_Random_Player<T>::Num_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); 
}

// Fetch the correct available numbers based on the player's symbol
template <typename T>
vector<int>& Num_Random_Player<T>::get_available_numbers() {
    return (this->symbol == 1) ? v1 : v2;
}

// Generate a random move
template <typename T>
void Num_Random_Player<T>::getmove(int& x, int& y) {
    vector<int>& availableNumbers = get_available_numbers();

    if (availableNumbers.empty()) {
        cout << this->name << " has no available numbers to play.\n";
        x = -1;
        y = -1;
        return;
    }

    int chosenNumber = availableNumbers[rand() % availableNumbers.size()];
    cout << this->name << " (Random Player) chooses number: " << chosenNumber << endl;

    x = rand() % 3;
    y = rand() % 3; 
}

#endif 
