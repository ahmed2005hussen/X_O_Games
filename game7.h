//
// Created by ahmed on 06/12/2024.
//
#include"BoardGame_Classes.h"

#include <iostream>
#include <iomanip>
#include <cctype>
#include<algorithm>
#include <cstdlib>
#include <ctime>
#include<fstream>

#ifndef XO_GAME7_H
#define XO_GAME7_H

using namespace std;


template<typename T>
class board7 : public Board<T> {
public:
    board7();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

template<typename T>
class player_7 : public Player<T> {
public:
    player_7(string name, T symbol);

    void getmove(int &x, int &y);
};


template<typename T>
class random_player_7 : public RandomPlayer<T> {
public:
    random_player_7(T symbol);

    void getmove(int &x, int &y);
};


// --------Implementation--------

template<typename T>
board7<T>::board7() {
    this->rows = this->columns = 4;
    this->board = new char *[this->rows];
    bool flag = true;
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            if (i == 0) {
                if (flag) {
                    this->board[i][j] = 'O';
                    flag = !flag;
                } else {
                    this->board[i][j] = 'X';
                    if (j != 3) { flag = !flag; }
                }
            } else if (i == 3) {
                if (flag) {
                    this->board[i][j] = 'O';
                    flag = !flag;
                } else {
                    this->board[i][j] = 'X';
                    flag = !flag;
                }
            } else {
                this->board[i][j] = ' ';
            }
        }
    }
    this->n_moves = 0;
}

template<typename T>
bool board7<T>::update_board(int x, int y, T symbol) {
    static bool flag = true;
    if(this->board[x][y]=='X'&& flag){
        flag = false ;
    }
    else if(this->board[x][y]=='O'&&!flag){
        flag = true ;
    }
    else{
        x = y = -1 ;
    }
    int pos1 = x;
    int pos2 = y;

    if (x >= 0 && x < 4 && y >= 0 && y < 4 ) {

        int n;

        if (x == 0 && y == 0) {

            if (this->board[x][y + 1] == ' ' && (this->board[x + 1][y] == ' ')) {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }
            else if ((this->board[x][y + 1] == ' ')) {
                cout << "it will right move " << endl;

                x = x;
                y = y + 1;
            }
            else if ((this->board[x + 1][y] == ' ')) {
                cout << "it will down move " << endl;
                x = x + 1;
                y = y;

            }
            else {
                cout<< "we can't move it in this position " <<endl;
                return false;
            }
        }

        else if (x == 0 && y == 3) {
            if ((this->board[x][y - 1] == ' ') && (this->board[x + 1][y] == ' ')) {
                cout << "do you want move it " << endl;
                cout << "1 - left " << endl;
                cout << "2 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y - 1;
                } else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }
            else if ((this->board[x][y + 1] == ' ')) {
                cout << "it will left move " << endl;
                x = x;
                y = y - 1;
            }
            else if ((this->board[x + 1][y] == ' ')) {
                cout << "it will down move " << endl;
                x = x + 1;
                y = y;
            }

            else {
                cout<< "we can't move it in this position " <<endl;
                return false;
            }

        }

        else if (x == 0) {
            if (this->board[x][y + 1] == ' ' && this->board[x][y - 1] == ' ' && this->board[x + 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - left " << endl;
                cout << "3 - down " << endl;

                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x;
                    y = y - 1;
                } else if (n == 3) {
                    x = x + 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x][y - 1] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - left " << endl;

                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x;
                    y = y-1;
                }
            }
            else if (this->board[x][y - 1] == ' ' && this->board[x + 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - left " << endl;
                cout << "2 - down " << endl;

                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y - 1;
                } else if (n == 2) {
                    x = x+1;
                    y = y  ;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x+1][y ] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - down " << endl;

                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }

            else if(this->board[x][y + 1] == ' ' ){
                cout << "we will move it right " << endl;
                x = x;
                y = y + 1;
            }
            else if(this->board[x][y - 1] == ' '){
                cout << "we will move it left " << endl;
                x = x;
                y = y - 1;
            }
            else if(this->board[x + 1][y] == ' '){

                cout << "we will move it down " << endl;
                x = x + 1;
                y = y;
            }


            else {
                cout<< "we can't move it in this position " <<endl;

                return false; }
        }

        else if((x == 1 && y == 0) || (x == 2 && y == 0)) {
            if (this->board[x][y + 1] == ' ' && this->board[x - 1][y] == ' ' && this->board[x + 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - up " << endl;
                cout << "3 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x - 1;
                    y = y;
                } else if (n == 3) {
                    x = x + 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x - 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - up " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x - 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x + 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }
            else if (this->board[x - 1][y] == ' ' && this->board[x + 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - up " << endl;
                cout << "2 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x - 1;
                    y = y;
                } else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }

            else if(this->board[x][y + 1] == ' ' ){
                cout<< "we will put it right"<<endl;
                x = x;
                y = y + 1;
            }
            else if(this->board[x - 1][y] == ' '){
                cout<< "we will put it up"<<endl;
                x = x - 1;
                y = y;
            }
            else if(this->board[x + 1][y] == ' '){
                cout<< "we will put it down"<<endl;
                x = x + 1;
                y = y;
            }

            else {
                cout<< "we can't move it in this position " <<endl;
                return false; }
        }

        else if ((x == 1 && y == 3) || (x == 2 && y == 3)){
if(this->board[x][y-1]==' ' && this->board[x-1][y]==' ' &&this->board[x+1][y]==' ' )
{
    cout << "do you want move it " << endl;
    cout << "1 - left " << endl;
    cout << "2 - up " << endl;
    cout << "3 - down " << endl;
    cin >> n;
    if (n == 1) {
        x = x;
        y = y - 1;
    } else if (n == 2) {
        x = x - 1;
        y = y;
    } else if (n == 3) {
        x = x + 1;
        y = y;
    }
}

else if(this->board[x][y-1]==' ' && this->board[x-1][y]==' '  )
{
    cout << "do you want move it " << endl;
    cout << "1 - left " << endl;
    cout << "2 - up " << endl;
    cin >> n;
    if (n == 1) {
        x = x;
        y = y - 1;
    } else if (n == 2) {
        x = x - 1;
        y = y;
    }
}
else if(this->board[x][y-1]==' ' && this->board[x+1][y]==' ' )
{
    cout << "do you want move it " << endl;
    cout << "1 - left " << endl;
    cout << "2 - down " << endl;
    cin >> n;
    if (n == 1) {
        x = x;
        y = y - 1;
    } else if (n == 2) {
        x = x + 1;
        y = y;
    }
}
else if(this->board[x-1][y]==' ' &&this->board[x+1][y]==' ' )
{
    cout << "do you want move it " << endl;
    cout << "1 - up " << endl;
    cout << "2 - down " << endl;
    cin >> n;
    if  (n == 1) {
        x = x - 1;
        y = y;
    } else if (n == 2) {
        x = x + 1;
        y = y;
    }
}
else if(this->board[x][y-1]==' '  )
{
    cout<< "we will put it left"<<endl;
    x = x;
    y = y - 1;
}
else if( this->board[x-1][y]==' '  )
{
    cout<< "we will put it up"<<endl;
    x = x - 1;
    y = y;
}
else if(this->board[x+1][y]==' ' )
{
    cout<< "we will put it down "<<endl;
    x = x + 1;
    y = y;
}
else
{
    cout<< "we can't move it in this position " <<endl;
    return false;

}


        }

        else if (x == 1 || x == 2) {
            if (this->board[x][y + 1] == ' ' && this->board[x][y - 1] == ' ' && this->board[x - 1][y] == ' ' &&
                this->board[x + 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - left " << endl;
                cout << "3 - up " << endl;
                cout << "4 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x;
                    y = y - 1;
                } else if (n == 3) {
                    x = x - 1;
                    y = y;
                } else if (n == 4) {
                    x = x + 1;
                    y = y;
                }
            }

            else if (this->board[x][y + 1] == ' ' && this->board[x][y - 1] == ' ' && this->board[x - 1][y] == ' ' )
            {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - left " << endl;
                cout << "3 - up " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x;
                    y = y - 1;
                } else if (n == 3) {
                    x = x - 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x - 1][y] == ' ' &&this->board[x + 1][y] == ' ')
            {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - up " << endl;
                cout << "3 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                }  else if (n == 2) {
                    x = x - 1;
                    y = y;
                } else if (n == 3) {
                    x = x + 1;
                    y = y;
                }
            }
            else if (this->board[x][y - 1] == ' ' && this->board[x - 1][y] == ' ' &&
                     this->board[x + 1][y] == ' ')
            {

                cout << "do you want move it " << endl;
                cout << "1 - left " << endl;
                cout << "2 - up " << endl;
                cout << "3 - down " << endl;
                cin >> n;
                if  (n == 1) {
                    x = x;
                    y = y - 1;
                } else if (n == 2) {
                    x = x - 1;
                    y = y;
                } else if (n == 3) {
                    x = x + 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x][y - 1] == ' ' )
            {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - left " << endl;

                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x;
                    y = y - 1;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x - 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - up " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                }  else if (n == 2) {
                    x = x - 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x + 1][y] == ' ')
            {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                }
                else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }
            else if ( this->board[x][y - 1] == ' ' && this->board[x - 1][y] == ' ')
            {
                cout << "do you want move it " << endl;
                cout << "1 - left " << endl;
                cout << "2 - up " << endl;
                cin >> n;
                if  (n == 1) {
                    x = x;
                    y = y - 1;
                } else if (n == 3) {
                    x = x - 1;
                    y = y;
                }
            }
            else if ( this->board[x][y - 1] == ' '  && this->board[x + 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - left " << endl;
                cout << "2 - down " << endl;
                cin >> n;
                if  (n == 1) {
                    x = x;
                    y = y - 1;
                }  else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }
            else if (this->board[x - 1][y] == ' ' && this->board[x + 1][y] == ' ')
            {
                cout << "do you want move it " << endl;
                cout << "1 - up " << endl;
                cout << "2 - down " << endl;
                cin >> n;
                if (n == 1) {
                    x = x - 1;
                    y = y;
                } else if (n == 2) {
                    x = x + 1;
                    y = y;
                }
            }
            else if (this->board[x + 1][y] == ' ') {
                cout << "we will move it down" << endl;

                x = x + 1;
                y = y;
            }
            else if (this->board[x - 1][y] == ' ') {
                cout << "we will move it up" << endl;

                x = x - 1;
                y = y;
            }
            else if (this->board[x][y - 1] == ' ') {
                cout << "we will move it left" << endl;

                x = x;
                y = y - 1;
            }
            else if (this->board[x][y + 1] == ' ') {
                cout << "we will move it right" << endl;
                x = x;
                y = y + 1;
            }
            else {
                cout<< "we can't move it in this position " <<endl;

                return false;
            }
        }

        else if (x == 3 && y == 0) {
            if (this->board[x][y + 1] == ' ' && this->board[x - 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - up " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x - 1;
                    y = y;
                }
            }

            else if (this->board[x][y + 1] == ' ') {
                cout << "we will move it right " << endl;
                x = x;
                y = y + 1;

            }
            else if (this->board[x - 1][y] == ' ') {
                cout << "we will move it up " << endl;
                x = x - 1;
                y = y;
            }
            else {
                cout<< "we can't move it in this position " <<endl;
                return false; }
        }

        else if (x == 3 && y == 3) {
            if (this->board[x][y - 1] == ' ' && this->board[x - 1][y]) {
                cout << "do you want move it " << endl;
                cout << "1 - left " << endl;
                cout << "2 - up " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y - 1;
                } else if (n == 2) {
                    x = x - 1;
                    y = y;
                }
            }
            else if (this->board[x][y - 1] == ' ') {
                cout << "we will move it left " << endl;
                x = x;
                y = y - 1;
            }
            else if (this->board[x - 1][y]) {
                cout << "we will move it up  " << endl;
                x = x - 1;
                y = y;
            }
            else {
                cout<< "we can't move it in this position " <<endl;

                return false;
            }
        }

        else if (x == 3) {
            if (this->board[x][y + 1] == ' ' && this->board[x][y - 1] == ' ' && this->board[x - 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - left " << endl;
                cout << "3 - up " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x;
                    y = y - 1;
                } else if (n == 3) {
                    x = x - 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x][y - 1] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - left " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x;
                    y = y - 1;
                }
            }
            else if (this->board[x][y + 1] == ' ' && this->board[x - 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - right " << endl;
                cout << "2 - up " << endl;
                cin >> n;
                if (n == 1) {
                    x = x;
                    y = y + 1;
                } else if (n == 2) {
                    x = x - 1;
                    y = y;
                }
            }
            else if (this->board[x][y - 1] == ' ' && this->board[x - 1][y] == ' ') {
                cout << "do you want move it " << endl;
                cout << "1 - left " << endl;
                cout << "2 - up " << endl;
                cin >> n;
                if (n == 2) {
                    x = x;
                    y = y - 1;
                } else if (n == 3) {
                    x = x - 1;
                    y = y;
                }
            }
            else if (this->board[x][y + 1] == ' ') {
                cout << "we will move it right " << endl;
                x = x;
                y = y + 1;
            }
            else if (this->board[x][y - 1] == ' ') {
                cout << "we will move it left " << endl;
                x = x;
                y = y - 1;
            }
            else if (this->board[x - 1][y] == ' ') {
                cout << "we will move it up " << endl;
                x = x - 1;
                y = y;
            }
            else {
                cout<< "we can't move it in this position " <<endl;

                return false;
            }
        }

        this->board[x][y] = toupper(symbol);
        this->board[pos1][pos2] = ' ';
        this->n_moves++;
        return true;
    }
    return false;
}

template<typename T>
void board7<T>::display_board() {

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


bool board7<T>::is_win() {


    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j <= this->columns - 3; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j ] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                return true;
            }
        }
    }


    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i <= this->rows - 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i ][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {
                return true;
            }
        }
    }


    if(this->board[0][2] != ' ' &&this->board[0][2] == this->board[1 ][1] &&
    this->board[1][1] == this->board[2][0]) { return true; }

    if(this->board[0][3] != ' ' &&this->board[0][3] == this->board[1 ][2] &&
       this->board[1][2] == this->board[2][1]) { return true; }


    if(this->board[1][2] != ' ' &&this->board[1][2] == this->board[2 ][1] &&
       this->board[2][1] == this->board[3][0]) { return true; }

    if(this->board[1][3] != ' ' &&this->board[1][3] == this->board[2 ][2] &&
       this->board[2][2] == this->board[3][1]) { return true; }

    //--------------------------------------------------------------
    if(this->board[1][0] != ' ' &&this->board[1][0] == this->board[2 ][1] &&
       this->board[2][1] == this->board[3][2]) { return true; }

    if(this->board[0][1] != ' ' &&this->board[0][1] == this->board[1 ][2] &&
       this->board[1][2] == this->board[2][3]) { return true; }

    if(this->board[0][0] != ' ' &&this->board[0][0] == this->board[1 ][1] &&
       this->board[1][1] == this->board[2][2]) { return true; }

    if(this->board[1][1] != ' ' &&this->board[1][1] == this->board[2 ][2] &&
       this->board[2][2] == this->board[3][3]) { return true; }

    return false;
}


template<typename T>
bool board7<T>::is_draw() {
    return false;
}

template<typename T>
bool board7<T>::game_is_over() {
    return is_win();
}


template<typename T>
player_7<T>::player_7(std::string name, T symbol) : Player<T>(name, symbol) {}


template<typename T>
void player_7<T>::getmove(int &x, int &y) {
    cout << "\n" << this->name << ", enter the position for your token do you want to move : " <<endl;
cout<< "enter x : "<<endl;
cin>> x;
cout<< "enter y : "<< endl;
cin>> y ;


}

//----------------------------------------

template<typename T>
random_player_7<T>::random_player_7(T symbol): RandomPlayer<T>(symbol) {}

template<typename T>
void random_player_7<T>::getmove(int &x, int &y) {
    srand(static_cast<unsigned int>(time(0)));
    x = rand() % 4;
    y = rand() % 4;
}


#endif //XO_GAME7_H
