/**
 * This program will focus on making a tic tac toe board.
 * This program is visualized through a 2d vector 
 * The complexity is O(n^2)
 * @author Colin MacMillan
 * Date: Nov. 15, 2022
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

   /**
   * This is the print board method. It prints the board
   */
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { //nested for loop to print the board. I think one of the only ways to do it.
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

   /**
   * This is a method that checks for if the player wins
   */
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function for the computer's move
void computerMove(vector<vector<char>>& board) {
    srand(static_cast<unsigned int>(time(NULL)));
    while (true) {
        int row = rand() % 3;
        int col = rand() % 3;

        if (board[row][col] == ' ') {
            board[row][col] = 'O';
            break;
        }
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    int currentPlayer = 1;
    int moves = 0;

    cout << "Welcome to tic-tac-toe. " << endl;
    cout << "You are 'X', and the computer is 'O'. You play your move as a two number input, one the x(col) value and the other is your y(row) value." << endl;
    cout << "DO NOT PUT A COMMA." << endl;
    while (true) {
        if (currentPlayer == 1) {
            int col, row; 
            
            bool validMove = false;
            
            while (!validMove) {
                cout << "your turn! Enter the column (1, 2, 3) and then the row (1, 2, 3) for your move: ";
                cin >> col >> row; 
                
                if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') { //checking parameters
                    cout << "Oops! That's an invalid move. please try again." << endl;
                } else {
                    validMove = true;
                }
            }

            char symbol = 'X';
            board[row - 1][col - 1] = symbol;
        } else {
            cout << "NYEHEHEHE MY TURN!!!" << endl;
            computerMove(board);
        }

        moves++;
        printBoard(board);

        if (checkWin(board, 'X')) {
            cout << "shucks, you win!" << endl;
            break;
        } else if (checkWin(board, 'O')) {
            cout << "HAHAHA i won!!!!11!!!" << endl;
            break;
        }

        if (moves == 9) {
            cout << "It's a draw! go again?" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}
