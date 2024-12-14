
#ifndef MISERE_H
#define MISERE_H


#include "BoardGame_Classes.h"

 bool check1 = false;
static string c = "player 1" ;

template<typename T>
class Misere_Board : public Board<T> {
public:
    Misere_Board();
    ~Misere_Board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();



};
template<typename T>
Misere_Board<T>::~Misere_Board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i]; // Delete each row
    }
    delete[] this->board; // Delete the array of pointers to rows
    check1 =false;
}




template<typename T>
class Misere_Player : public Player<T> {
public:
    Misere_Player(string name, T symbol);

    void getmove(int &x, int &y);

};

template<typename T>
class Misere_Random_Player : public RandomPlayer<T> {
public:
    Misere_Random_Player(T symbol);

    void getmove(int &x, int &y);
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

// Constructor for X_O_Board
template<typename T>
Misere_Board<T>::Misere_Board() {
    this->rows = this->columns = 3;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template<typename T>
bool Misere_Board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!check1) {
        if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) {

                this->n_moves++;
                this->board[x][y] = toupper(mark);


            return true;
        }
    }
    else if(check1){
            c=mark;
        return true;
    }
    else{ return false; }

}

// Display the board and the pieces on it
template<typename T>
void Misere_Board<T>::display_board() {
    // Display the column numbers
    cout << "    1   2   3 \n";

    for (int i = 0; i < this->rows; i++) {
        // Display row number
        cout << i + 1 << " ";
        for (int j = 0; j < this->columns; j++) {
            cout << "| " << setw(2) << (this->board[i][j] == 0 ? ' ' : this->board[i][j]) << " ";
        }
        cout << "|\n";
        cout << "   -------------\n";
    }
    cout << endl;
}


// Returns true if there is any winner
template<typename T>
bool Misere_Board<T>::is_win() {
    if (!check1) {
        for (int i = 0; i < this->rows; i++) {
            if ((this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] &&
                 this->board[i][0] != 0) ||
                (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] &&
                 this->board[0][i] != 0)) {
                check1 = true;
                return false;
            }
        }

        // Check diagonals
        if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] &&
             this->board[0][0] != 0) ||
            (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] &&
             this->board[0][2] != 0)) {
            check1 = true;
            return false;
        }
    }

     else if (check1) {
         cout<< "Player : "<< c << " is win "<<endl;
        return true;
    }
    return false;

}

// Return true if 9 moves are done and no winner
template<typename T>
bool Misere_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template<typename T>
bool Misere_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template<typename T>
Misere_Player<T>::Misere_Player(string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void Misere_Player<T>::getmove(int &x, int &y) {
    if (!check1) {
        // Prompt the user to enter a move with 1-based coordinates
        cout << "\nPlease enter your move (row, column) between 1 and 3: ";
        cin >> x >> y;

        // Convert 1-based index to 0-based index for internal board representation
        x--; // Convert to 0-based row
        y--; // Convert to 0-based column
    }
    if (check1) {
        c = this->name;
    }
}


// Constructor for X_O_Random_Player
template<typename T>
Misere_Random_Player<T>::Misere_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template<typename T>
void Misere_Random_Player<T>::getmove(int &x, int &y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % this->dimension;
}



#endif //MISERE_H
