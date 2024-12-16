#include <iostream>
#include "BoardGame_Classes.h"
#include " Pyramic_Tic-Tac-Toe.h"
#include "Word_Tic-tac-toe.h"
#include "game7.h"
#include "game8.h"
#include"Four_In_Row.h"

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
            players[0] = new Pyramid_player<char>(playerXName, 'X');
            break;
        } else if (choice == '2') {
            players[0] = new Pyramid_Random_Player<char>('X');
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
            players[1] = new Pyramid_player<char>(player2Name, 'O');
            break;
        } else if (choice == '2') {
            players[1] = new Pyramid_Random_Player<char>('O');
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

} // done
void game2() {
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
    }} // done

void game3() {
    int choice;
    Player<char>* players[2];
    FiveByFive_Board<char>* B = new FiveByFive_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to FiveByFive XO Game :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new FiveByFive_Player<char>(playerXName, 'X');
        break;
        case 2:
            players[0] = new FiveByFive_Random_Player<char>('X');
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new FiveByFive_Player<char>(player2Name, 'O');
        break;
        case 2:
            players[1] = new FiveByFive_Random_Player<char>('O');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return 1;
    }

    // Create the game manager and run the game
    GameManager<char> FiveByFive_game(B, players);
    FiveByFive_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}

void game4() {

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

} // done
void game5()
{
    char choice;
    Player<char>* players[2];
    Num_Board<char>* B = new Num_Board<char>();
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
            players[0] = new Num_Player<char>(playerXName, 1);
            break;
        }
        else if (choice == '2') {
            players[0] = new Num_Random_Player<char>(1);
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
            players[1] = new Num_Player<char>(player2Name, 2);
            break;
        }
        else if (choice == '2') {
            players[1] = new Num_Random_Player<char>(2);
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

void game6() {
int choice;
    Player<char>* players[2];
    Misere_Board<char>* B = new Misere_Board<char>();
    string playerXName, player2Name;

    cout << "Welcome to Misere XO Game :)\n";

    // Set up player 1
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[0] = new Misere_Player<char>(playerXName, 'X');
        break;
        case 2:
            players[0] = new Misere_Random_Player<char>('X');
        break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
        return 1;
    }

    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> choice;

    switch(choice) {
        case 1:
            players[1] = new Misere_Player<char>(player2Name, 'O');
        break;
        case 2:
            players[1] = new Misere_Random_Player<char>('O');
        break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
        return 1;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }


}

void game7() {
    char choice;
    Player<char> *players[2];
    board7<char> *B = new board7<char>();
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
            players[0] = new player_7<char>(playerXName, 'X');
            break;
        } else if (choice == '2') {
            players[0] = new random_player_7<char>('X');
            break;
        } else {
            cout << "Invalid choice for Player 1. enter valid choice \n";
        }
    }

    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";

    while (true) {
        cin >> choice;

        if (choice == '1') {
            players[1] = new player_7<char>(player2Name, 'O');
            break;
        } else if (choice == '2') {
            players[1] = new random_player_7<char>('O');

            break;
        } else {
            cout << "Invalid choice for Player 2. enter valid choice.\n";
        }
    }
    GameManager<char> game7(B, players);
    game7.run();

    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

} // done


void game8() {

    char choice;
    Player<char> *players[2];
    unlimated_board<char> *B = new unlimated_board<char>();
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
            players[0] = new player_8<char>(playerXName, 'X');
            break;
        } else if (choice == '2') {
            players[0] = new player_Random_8<char>('X');
            break;
        } else {
            cout << "Invalid choice for Player 1. enter valid choice \n";
        }
    }

    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";

    while (true) {
        cin >> choice;

        if (choice == '1') {
            players[1] = new player_8<char>(player2Name, 'O');
            break;
        } else if (choice == '2') {
            players[1] = new player_Random_8<char>('O');

            break;
        } else {
            cout << "Invalid choice for Player 2. enter valid choice.\n";
        }
    }
    
    GameManager<char> game8(B, players);
    game8.run();

    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
} // done


void game9()
{
    char choice;
    Player<char>* players[2];
    SUS_Board<char>* B = new SUS_Board<char>();
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
            players[0] = new SUS_Player<char>(playerXName, 'S');
            break;
        }
        else if (choice == '2') {
            players[0] = new SUS_Random_Player<char>('S');
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
            players[1] = new SUS_Player<char>(player2Name, 'U');
            break;
        }
        else if (choice == '2') {
            players[1] = new SUS_Random_Player<char>('U');
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
    cout << "9- SUS" << endl;
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
        game5();
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

    } else if (n == '9') {
        game9();
        main();

    } else {
        cout << "Invalid choice " << endl;
        main();
    }

    return 0;
}
