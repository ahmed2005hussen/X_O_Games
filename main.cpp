#include <iostream>
#include "BoardGame_Classes.h"
#include " Pyramic_Tic-Tac-Toe.h"
#include "Word_Tic-tac-toe.h"
#include "Four_In_Row.h"
using namespace std;

void game1() {

    char choice;
    Player<char> *players[2];
    pyramid<char> *B = new pyramid<char>();
    string playerXName, player2Name;


    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while (true) {
        cin >> choice;

        if (choice == '1') {
            players[0] = new X_O_Player<char>(playerXName, 'X');
            break;
        } else if (choice == '2') {
            players[0] = new X_O_Random_Player<char>('X');
            break;
        } else {
            cout << "Invalid choice for Player 1. enter valid choice \n";
        }
    }
    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";

    while (true) {
        cin >> choice;

        if (choice == '1') {
            players[1] = new X_O_Player<char>(player2Name, 'O');
            break;
        } else if (choice == '2') {
            players[1] = new X_O_Random_Player<char>('O');
            break;
        } else {
            cout << "Invalid choice for Player 2. enter valid choice.\n";
        }
    }

    // Create the game manager and run the game
    GameManager<char> pyramid_game(B, players);
    pyramid_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}

void game2()
{
    char choice;
    Player<char>* players[2];
    Four_In_Row<char>* B = new Four_In_Row<char>();
    string playerXName, player2Name;


    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while (true) {
        cin >> choice;

        if (choice == '1') {
            players[0] = new X_O_Player<char>(playerXName, 'X');
            break;
        }
        else if (choice == '2') {
            players[0] = new X_O_Random_Player<char>('X');
            break;
        }
        else {
            cout << "Invalid choice for Player 1. enter valid choice \n";
        }
    }
    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";

    while (true) {
        cin >> choice;

        if (choice == '1') {
            players[1] = new X_O_Player<char>(player2Name, 'O');
            break;
        }
        else if (choice == '2') {
            players[1] = new X_O_Random_Player<char>('O');
            break;
        }
        else {
            cout << "Invalid choice for Player 2. enter valid choice.\n";
        }
    }

    // Create the game manager and run the game
    GameManager<char> pyramid_game(B, players);
    pyramid_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

void game3(){}
void game4(){

    
    char choice;
    Player<char> *players[2];
    word_board<char> *B = new word_board<char>();
    string playerXName, player2Name;
    char player1Symbol, player2Symbol;

    // Set up player 1
    cout << "Enter Player 1 name: ";
    cin >> playerXName;

    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while (true) {
        cin >> choice;
        if (choice == '1') {
            players[0] = new word_player<char>(playerXName, ' ');
            break;
        } else if (choice == '2') {
            players[0] = new word_random_player<char>(' ');
            break;
        } else {
            cout << "Invalid choice for Player 1. Enter a valid choice \n";
        }
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;


    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while (true) {
        cin >> choice;
        if (choice == '1') {
            players[1] = new word_player<char>(player2Name, ' ');
            break;
        } else if (choice == '2') {
            players[1] = new word_random_player<char>(' ');
            break;
        } else {
            cout << "Invalid choice for Player 2. Enter a valid choice.\n";
        }
    }

    // Create the game manager and run the game
    GameManager<char> word_game(B, players);
    word_game.run();

    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}
void game5(){}
void game6(){}
void game7(){

    Player<char> *players[2];
    board7<char> *B = new board7<char>();
    string playerXName, player2Name;


    cout << "Enter Player X name: ";
    cin >> playerXName;

    players[0] = new player_7<char>(playerXName, 'X');

    cout << "Enter Player 2 name: ";
    cin >> player2Name;


    players[1] = new player_7<char>(player2Name, 'O');


    GameManager<char> pyramid_game(B, players);
    pyramid_game.run();

    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void game8(){
     Player<char> *players[2];
    unlimated_board<char> *B = new unlimated_board<char>();
    string playerXName, player2Name;


    cout << "Enter Player X name: ";
    cin >> playerXName;

    players[0] = new player_8<char>(playerXName, 'X');

    cout << "Enter Player 2 name: ";
    cin >> player2Name;


    players[1] = new player_8<char>(player2Name, 'O');


    GameManager<char> pyramid_game(B, players);
    pyramid_game.run();

    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

int main() {

    char n;
    cout << "Welcome To you , let's We Play " << endl;
    cout << "-------------------------------" << endl;
    cout << "Choice a number " << endl;
    cout << "----------------" << endl;
    cout << "0 - exit " << endl;
    cout << "1- Pyramid Tic-Tac-Toe" << endl;
    cout << "2- Four-in-a-row" << endl;
    cout << "3- 5 x 5 Tic Tac Toe" << endl;
    cout << "4- Word Tic-tac-toe" << endl;
    cout << "5- Numerical Tic-Tac-Toe" << endl;
    cout << "6- Misere Tic Tac Toe" << endl;
    cout << "7- 4 x 4 Tic-Tac-Toe" << endl;
    cout << "8- Ultimate Tic Tac Toe" << endl;
    cin >> n;
    if (n == '0') {
        cout << "Good bye" << endl;
        return 0;
    } else if (n == '1') {
        game1();
        main();

    } else if (n == '2') {
        game2();
        main();

    } else if (n == '3') {
        //game3();
        main();

    } else if (n == '4') {
        game4();
        main();

    } else if (n == '5') {
        //game5();
        main();

    } else if (n == '6') {
        //game6();
        main();

    } else if (n == '7') {
       game7();
        main();

    } else if (n == '8') {
        game8();
        main();

    } else {
        cout << "Invalid choice " << endl;
        main();
    }

    return 0;
}




