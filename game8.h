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
};

template<typename T>
bool board8<T>::game_is_over() {
    return is_win() || is_draw();
}

template<typename T>
bool board8<T>::is_draw() {
    return (!is_win() && this->n_moves==9);
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

    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
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
        cout << "\n-----------------------------";
    }
    cout << endl;
}

template<typename T>
bool board8<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3 && (this->board[x][y] != 'X' && this->board[x][y] != 'O')) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    return false;
}

template<typename T>
board8<T>::board8() {
this->columns=this->rows=3;
this->board = new string[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new string[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = "("+ to_string(i)+","+to_string(j)+")";
        }
    }
    this->n_moves = 0;

}









template<typename T>
class unlimated_board : public Board<T> {
public:

    board8<T> b;
    int checkwin();


    unlimated_board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

template<typename T>
int unlimated_board<T>::checkwin() {
static int a1=1;
static int a2=1;
static int a3=1;
static int a4=1;
static int a5=1;
static int a6=1;
static int a7=1;
static int a8=1;
static int a9=1;

if(a1){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= 3 - 3; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a1=0;
                return 1;
            }
        }
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i <= 3 - 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                a1=0;
                return 1;
            }
        }
    }

    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
        a1=0;
        return 1;
    }
}

else if(a2){
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j <= 3; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a2=0;
                return 2;
            }
        }
    }

    for (int j = 3; j < 6; j++) {
        for (int i = 0; i <= 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {

                a2=0;
                return 2;
            }
        }
    }

    if ((this->board[0][3] == this->board[1][4] && this->board[1][4] == this->board[2][5] && this->board[1][4] != 0) ||
        (this->board[0][5] == this->board[1][4] && this->board[1][4] == this->board[2][3] && this->board[2][3] != 0)) {
        a2=0;
        return 2;    }


}

else if(a3){
    for (int i = 0; i < 3; i++) {
        for (int j = 6; j <= 6; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a3=0;
                return 3;
            }
        }
    }

    for (int j = 6; j < 9; j++) {
        for (int i = 0; i <= 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                a3=0;
                return 3;            }
        }
    }

    if ((this->board[0][6] == this->board[1][7] && this->board[1][7] == this->board[2][8] && this->board[2][8] != 0) ||
        (this->board[0][8] == this->board[1][7] && this->board[1][7] == this->board[2][6] && this->board[2][6] != 0)) {
        a3=0;
        return 3;
    }


}

else if(a4){
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j <= 0; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a4=0;
                return 4;
            }
        }
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 3; i <= 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {

                a4=0;
                return 4;
            }
        }
    }

    if ((this->board[3][0] == this->board[4][1] && this->board[4][1] == this->board[5][2] && this->board[5][2] != 0) ||
        (this->board[3][2] == this->board[4][1] && this->board[4][1] == this->board[5][0] && this->board[5][0] != 0)) {
        a4=0;
        return 4;    }

}


else if(a5){
    for (int i = 3; i < 6; i++) {
        for (int j = 3; j <= 3; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a5=0;
                return 5;            }
        }
    }

    for (int j = 3; j < 6; j++) {
        for (int i = 3; i <= 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                a5=0;
                return 5;             }
        }
    }

    if ((this->board[3][3] == this->board[4][4] && this->board[4][4] == this->board[5][5] && this->board[4][4] != 0) ||
        (this->board[3][5] == this->board[4][4] && this->board[4][4] == this->board[5][3] && this->board[3][5] != 0)) {
        a5=0;
        return 5;     }

}


else if(a6){
    for (int i = 3; i < 6; i++) {
        for (int j = 6; j <= 6; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a6=0;
                return 6;             }
        }
    }

    for (int j = 6; j < 9; j++) {
        for (int i = 3; i <= 3; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                a6=0;
                return 6;            }
        }
    }

    if ((this->board[3][6] == this->board[4][7] && this->board[4][7] == this->board[5][8] && this->board[5][8] != 0) ||
        (this->board[3][8] == this->board[4][7] && this->board[4][7] == this->board[5][6] && this->board[5][6] != 0)) {
        a6=0;
        return 6;    }

}


else if(a7){
    for (int i = 6; i < 9; i++) {
        for (int j = 0; j <= 0; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a7=0;
                return 7;            }
        }
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 6; i <= 6; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                a7=0;
                return 7;
            }
        }
    }

    if ((this->board[6][0] == this->board[7][1] && this->board[7][1] == this->board[8][2] && this->board[6][0] != 0) ||
        (this->board[6][2] == this->board[7][1] && this->board[7][1] == this->board[8][0] && this->board[8][0] != 0)) {
        a7=0;
        return 7;    }

}


else if(a8)
{
    for (int i = 6; i < 9; i++) {
        for (int j = 3; j <= 3; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a8=0;
                return 8;            }
        }
    }

    for (int j = 3; j < 6; j++) {
        for (int i = 6; i <= 6; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                a8=0;
                return 8;            }
        }
    }

    if ((this->board[6][3] == this->board[7][4] && this->board[7][4] == this->board[8][5] && this->board[7][4] != 0) ||
        (this->board[6][5] == this->board[7][4] && this->board[7][4] == this->board[8][3] && this->board[8][3] != 0)) {
        a8=0;
        return 8;
    }

}

else if(a9)
{
    for (int i = 6; i < 9; i++) {
        for (int j = 6; j <= 6; j++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) {
                a9=0;
                return 9;            }
        }
    }

    for (int j = 6; j < 9; j++) {
        for (int i = 6; i <= 6; i++) {
            if (this->board[i][j] != ' ' &&
                this->board[i][j] == this->board[i][j] &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) {


                a9=0;
                return 9;             }
        }
    }

    if ((this->board[6][6] == this->board[7][7] && this->board[7][7] == this->board[8][8] && this->board[6][6] != 0) ||
        (this->board[6][8] == this->board[7][7] && this->board[7][7] == this->board[8][6] && this->board[6][8] != 0)) {
        a9=0;
        return 9;     }

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
    for (int i = 0; i < this->rows; i++) {
        if (i == 3 || i == 6) {
            cout << endl << endl;;
        }
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << this->board[i][j] << " |";
            if (j == 2 || j == 5) {
                cout << "   |";
            }
        }
        cout << "\n--------------   -------------   --------------   ";
    }
    cout << endl;

}

template<typename T>
bool unlimated_board<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < 9 && y >= 0 && y < 9 && (this->board[x][y] != 'X' && this->board[x][y] != 'O')) {
        this->board[x][y] = toupper(symbol);
        if(checkwin()){
            if(checkwin()==1)
            {
                b.board[0][0]= toupper(symbol);
            }
            else if(checkwin()==2){
                b.board[0][1]= toupper(symbol);

            }else if(checkwin()==3){
                b.board[0][2]= toupper(symbol);

            }else if(checkwin()==4){
                b.board[1][0]= toupper(symbol);

            }else if(checkwin()==5){
                b.board[1][1]= toupper(symbol);

            }else if(checkwin()==6){
                b.board[1][2]= toupper(symbol);

            }else if(checkwin()==7){
                b.board[2][0]= toupper(symbol);

            }else if(checkwin()==8){
                b.board[2][1]= toupper(symbol);

            }else if(checkwin()==9){
                b.board[2][2]= toupper(symbol);

            }

        }

        this->n_moves++;
        return true;
    }
    return false;
}

template<typename T>
unlimated_board<T>::unlimated_board() {
    this->columns=this->rows=9;
    this->board = new string[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new string[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = "("+ to_string(i)+","+to_string(j)+")";
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
   cout<< "enter x "<<endl;
   cin>>x;
   cout<< "enter y "<< endl;
   cin>> y ;

}

//
//
//template<typename T>
//class random_player_7 : public RandomPlayer<T> {
//public:
//    random_player_7(T symbol);
//
//    void getmove(int &x, int &y);
//};
//
//
//// --------Implementation--------
//
//template<typename T>
//unlimated_board<T>::unlimated_board() {
//    this->rows = this->columns = 9;
//    this->board = new char *[this->rows];
//    for (int i = 0; i < this->rows; i++) {
//        this->board[i] = new char[this->columns];
//        for (int j = 0; j < this->columns; j++) {
//            this->board[i][j] = ' ';
//        }
//    }
//    this->n_moves = 0;
//}
//
//template<typename T>
//board8<T>::board8() {
//    this->rows = this->columns = 3;
//    this->board = new char *[this->rows];
//    for (int i = 0; i < this->rows; i++) {
//        this->board[i] = new char[this->columns];
//        for (int j = 0; j < this->columns; j++) {
//            this->board[i][j] = ' ';
//        }
//    }
//    this->n_moves = 0;
//}
//
//
//template<typename T>
//bool unlimated_board<T>::update_board(int x, int y, T symbol) {
//    if (x >= 0 && x < 9 && y >= 0 && y < 9 && (this->board[x][y] != 'X' && this->board[x][y] != 'O')) {
//        this->board[x][y] = toupper(symbol);
//        this->n_moves++;
//        return true;
//    }
//
//    return false;
//}
//
//template<typename T>
//bool board8<T>::update_board(int x, int y, T symbol) {
//
//    if (x >= 0 && x < 3 && y >= 0 && y < 3 && (this->board[x][y] != 'X' && this->board[x][y] != 'O')) {
//        this->board[x][y] = toupper(symbol);
//        this->n_moves++;
//        return true;
//    }
//
//    return false;
//}
//
//template<typename T>
//void unlimated_board<T>::display_board() {
//
//    for (int i = 0; i < this->rows; i++) {
//        cout << "\n| ";
//        for (int j = 0; j < this->columns; j++) {
//            cout << "(" << i << "," << j << ")";
//            cout << setw(2) << this->board[i][j] << " |";
//        }
//        cout << "\n-----------------------------";
//    }
//    cout << endl;
//}
//
//template<typename T>
//void board8<T>::display_board() {
//
//    for (int i = 0; i < this->rows; i++) {
//        cout << "\n| ";
//        for (int j = 0; j < this->columns; j++) {
//            cout << "(" << i << "," << j << ")";
//            cout << setw(2) << this->board[i][j] << " |";
//        }
//        cout << "\n-----------------------------";
//    }
//    cout << endl;
//}
//
//static bool check = false;
//
//template<typename T>
//bool unlimated_board<T>::is_win() {
//
//
//    if (board8::i) {
//        return true;
//    }
//    return false;
//}
//
//
//template<typename T>
//bool board8<T>::is_win() {
//
//
//    for (int i = 0; i < this->rows; i++) {
//        for (int j = 0; j <= this->columns - 3; j++) {
//            if (this->board[i][j] != ' ' &&
//                this->board[i][j] == this->board[i][j] &&
//                this->board[i][j] == this->board[i][j + 1] &&
//                this->board[i][j] == this->board[i][j + 2]) {
//                check = true;
//                return true;
//            }
//        }
//    }
//
//    for (int j = 0; j < this->columns; j++) {
//        for (int i = 0; i <= this->rows - 3; i++) {
//            if (this->board[i][j] != ' ' &&
//                this->board[i][j] == this->board[i][j] &&
//                this->board[i][j] == this->board[i + 1][j] &&
//                this->board[i][j] == this->board[i + 2][j]) {
//                check = true;
//
//                return true;
//            }
//        }
//    }
//
//    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||
//        (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)) {
//        check = true;
//        return true;
//    }
//    return false;
//}
//
//
//template<typename T>
//bool unlimated_board<T>::is_draw() {
//    return false;
//}
//
//template<typename T>
//bool unlimated_board<T>::game_is_over() {
//    return is_win();
//}
//
//
//template<typename T>
//player_7<T>::player_7(std::string name, T symbol) : Player<T>(name, symbol) {}
//
//
//template<typename T>
//void player_7<T>::getmove(int &x, int &y) {
//    cout << "\n" << this->name << ", enter the position for your token do you want to move : " << endl;
//    cout << "enter x : " << endl;
//    cin >> x;
//    cout << "enter y : " << endl;
//    cin >> y;
//
//
//}
//
////----------------------------------------
//
//template<typename T>
//random_player_7<T>::random_player_7(T symbol): RandomPlayer<T>(symbol) {}
//
//template<typename T>
//void random_player_7<T>::getmove(int &x, int &y) {
//    srand(static_cast<unsigned int>(time(0)));
//    x = rand() % 4;
//    y = rand() % 4;
//}

#endif //XO_GAME8_H