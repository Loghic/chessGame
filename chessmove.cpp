#include <iostream>
#include "chessmove.h"
using namespace std;

int pawnMove(int board[][8], int row, int col, int player)
{
    int movement = row - (1*player);
    if (movement < 0 || movement > 7){
        cout << "Piece can't move! Choose different one!" << endl;
        return 1;
    }
    board[row][col] = 0;
    board[movement][col] = 1 * player;
    return 0;
}

int knightMove(int board[][8], int row, int col, int player, int piece)
{
    int movementRow = row - (2*player);
    int movementColMinus = col - (1*player);
    int movementColPlus = col + (1*player);
    int optionRow = 0;
    int optionCol = 0;
    if (movementRow < 0 || movementRow > 7 || movementColMinus < 0 || movementColMinus > 7 || movementColPlus < 0 || movementColPlus > 7){
        cout << "Piece can't move! Choose different one!" << endl;
        //choosePiece(board, player);
        return 1;
    }
    cout << "Choose desired position 1st row, 2nd col: ";
    cout << "[" << movementRow << " " << movementColPlus << "] ";
    cout << "[" << movementRow << " " << movementColMinus << "] ";

    cin >> optionRow >> optionCol;
    board[row][col] = 0;
    board[optionRow][optionCol] = 2 * player;
    return 0;
}
