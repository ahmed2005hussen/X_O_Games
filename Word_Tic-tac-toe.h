//
// Created by ahmed on 03/12/2024.
//

#ifndef XO_WORD__TIC_TAC_TOE_H
#define XO_WORD__TIC_TAC_TOE_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include<algorithm>
#include <cstdlib>
#include <ctime>
#include<fstream>
#include "BoardGame_Classes.h"

using namespace std;


template<typename T>
class word_board : public Board<T> {
public:
    word_board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

template<typename T>
class word_player : public Player<T> {
public:
    word_player(string name, T symbol);

    void getmove(int &x, int &y);
};


template<typename T>
class word_random_player : public RandomPlayer<T> {
public:
    word_random_player(T symbol);

    void getmove(int &x, int &y);
};


// --------Implementation--------

template<typename T>
word_board<T>::word_board() {
    this->rows = this->columns = 3;
    this->board = new char *[this->rows];
    int counter = 1;
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = '0' + counter;
            counter++;
        }
    }
    this->n_moves = 0;
}

template<typename T>
bool word_board<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3 && isdigit(this->board[x][y])) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    return false;
}

template<typename T>
void word_board<T>::display_board() {
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


bool word_board<T>::is_win() {
    static vector<string> input;
    static bool check = false;
    if (!check) {
        fstream file("dic.txt");
        string line;
        while (getline(file, line)) {
            input.emplace_back(line);
        }
        file.close();
        sort(input.begin(), input.end());
        check = true;
    }

    // binary search for the results

    vector<string> binary;
    binary.emplace_back(string(1, this->board[0][0]) + string(1, this->board[0][1]) + string(1, this->board[0][2]));
    binary.emplace_back(string(1, this->board[1][0]) + string(1, this->board[1][1]) + string(1, this->board[1][2]));
    binary.emplace_back(string(1, this->board[2][0]) + string(1, this->board[2][1]) + string(1, this->board[2][2]));

    binary.emplace_back(string(1, this->board[0][0]) + string(1, this->board[1][1]) + string(1, this->board[2][2]));
    binary.emplace_back(string(1, this->board[2][0]) + string(1, this->board[1][1]) + string(1, this->board[0][2]));

    binary.emplace_back(string(1, this->board[0][0]) + string(1, this->board[1][0]) + string(1, this->board[2][0]));
    binary.emplace_back(string(1, this->board[0][1]) + string(1, this->board[1][1]) + string(1, this->board[2][1]));
    binary.emplace_back(string(1, this->board[0][2]) + string(1, this->board[1][2]) + string(1, this->board[2][2]));

    binary.emplace_back(string(1, this->board[0][2]) + string(1, this->board[0][1]) + string(1, this->board[0][0]));
    binary.emplace_back(string(1, this->board[1][2]) + string(1, this->board[1][1]) + string(1, this->board[1][0]));
    binary.emplace_back(string(1, this->board[2][2]) + string(1, this->board[2][1]) + string(1, this->board[2][0]));

    binary.emplace_back(string(1, this->board[2][2]) + string(1, this->board[1][1]) + string(1, this->board[0][0]));
    binary.emplace_back(string(1, this->board[0][2]) + string(1, this->board[1][1]) + string(1, this->board[2][0]));

    binary.emplace_back(string(1, this->board[2][0]) + string(1, this->board[1][0]) + string(1, this->board[0][0]));
    binary.emplace_back(string(1, this->board[2][1]) + string(1, this->board[1][1]) + string(1, this->board[0][1]));
    binary.emplace_back(string(1, this->board[2][2]) + string(1, this->board[1][2]) + string(1, this->board[0][2]));

    for (int i = 0; i < 16; i++) {
        int l, r, mid;
        r = input.size() - 1;
        l = 0;

        while (l <= r) {
            mid = (r + l) / 2;
            if (input[mid] < binary[i]) {
                l = mid + 1;

            } else if (input[mid] > binary[i]) {
                r = mid - 1;
            } else {
                return true;
            }
        }
    }
    binary.clear();
    binary.shrink_to_fit();
    return false;
}


template<typename T>
bool word_board<T>::is_draw() {
    return this->n_moves == 9 && !is_win();
}

template<typename T>
bool word_board<T>::game_is_over() {
    return is_win() || is_draw();
}


template<typename T>
word_player<T>::word_player(std::string name, T symbol) : Player<T>(name, symbol) {
}


template<typename T>
void word_player<T>::getmove(int &x, int &y) {
    cout << "\n" << this->name << ", enter your letter : ";
    char move;
    cin >> move;
    move = toupper(move);

    cout << "\n" << this->name << ", enter your position : ";
    char pos;
    cin >> pos;

    if (pos == '1') {
        x = 0;
        y = 0;
    } else if (pos == '2') {
        x = 0;
        y = 1;
    } else if (pos == '3') {
        x = 0;
        y = 2;
    } else if (pos == '4') {
        x = 1;
        y = 0;
    } else if (pos == '5') {
        x = 1;
        y = 1;
    } else if (pos == '6') {
        x = 1;
        y = 2;
    } else if (pos == '7') {
        x = 2;
        y = 0;
    } else if (pos == '8') {
        x = 2;
        y = 1;
    } else if (pos == '9') {
        x = 2;
        y = 2;
    } else {
        x = -1;
        y = -1;
    }
    this->symbol = move;
}

//----------------------------------------

template<typename T>
word_random_player<T>::word_random_player(T symbol): RandomPlayer<T>(symbol) {}

template<typename T>
void word_random_player<T>::getmove(int &x, int &y) {
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % 3;
    y = rand() % 3;
}


#endif //XO_WORD__TIC_TAC_TOE_H
