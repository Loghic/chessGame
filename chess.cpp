#include <iostream>
#include <iomanip>
#include "chessmove.h"
#include "chessmove.cpp"
using namespace std;

void makeBoard();
void setUpPieces(int board[][8]);
void printBoard(int board[][8]);
void choosePiece(int board[][8], int &player);
void game(int board[][8]);


int main(int argc, char *argv[])
{
    makeBoard();
    return 0;
}

void makeBoard()
{
    int board [8][8];
    for (int i {0}; i < 8; i++){
        for (int j {0}; j < 8; j++){
            board[i][j] = 0;
        }
    }
    setUpPieces(board);
    game(board);
    printBoard(board);
}

void setUpPieces(int board[][8])
{
    int player = 1;
    for (int row = 0; row < 8; row++){
        if (row == 0 || row == 1 || row == 6 || row == 7){
            (row == 0 || row == 1 ? player = -1 : player = 1);
            for (int col = 0; col < 8; col++){
            if (row == 1 || row == 6){
                board[row][col] = player;
                continue;
            }
            if (row == 0 || row == 7){
                switch (col){
                    case 0:
                    case 7:
                        board[row][col] = 4 * player;
                        break;
                    case 1:
                    case 6:
                        board[row][col] = 2 * player;
                        break;
                    case 2: 
                    case 5:
                        board[row][col] = 3 * player;
                        break;
                    case 3:
                        board[row][col] = 5 * player;
                        break;
                    case 4:
                        board[row][col] = 6 * player;
                        break;
                    default:
                        break;
                }
            }
            }
        }
    }
        
}

void game(int board[][8])
{
    int player = 1;
    char play = 'c';
    printBoard(board);
    while (play == 'c'){
        cout << (player == 1? "White move" : "Black move") << endl;
        choosePiece(board, player);
        printBoard(board);
        player *= -1;
        cout << "Do you wanna continue? Press 'c' if yes, else press anything else: ";
        cin >> play;
    }
}

void choosePiece(int board[][8], int &player)
{
    int piece = 0;
    cout << "Choose piece 1 for Pawn, 2 for knight, 3 for bishop, 4 for rook, 5 for queen, 6 for king: ";
    cin >> piece;
    cout << "Avaible moves: " << endl;
    for (int row {0}; row < 8; row++){
            for (int col {0}; col < 8; col++){
                if (board[row][col] == piece * player){
                    cout << "[" << row << " " << col << "] ";
                }
        }
    }
    int row = 0;
    int col = 0;
    cout << "Please enter coordinates of piece: ";
    cin >> row >> col;
    switch (piece)
    {
        case 1:
            pawnMove(board, row, col, player);
            break;
        case 2:
            knightMove(board, row, col, player, piece);
        default:
            break;
    }

}

void printBoard(int board[][8])
{
    for (int i {0}; i < 8; i++){
        for (int j {0}; j < 8; j++){
            cout << setfill(' ') << setw(2) << board[i][j] << " ";
        }
        cout << endl;
    }
}