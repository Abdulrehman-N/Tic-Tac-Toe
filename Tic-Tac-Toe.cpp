#include <iostream>
#include <string>
#include <random>
using namespace std;

void userIn(char board[3][3]){
    int row;
    int col;

    // Prompt user for row input (0-2)
    do {
        cout << "Enter row (0-2): ";
        cin >> row;
        if (row < 0 || row > 2) {
            cout << "Invalid row. Please enter a number between 0 and 2." << endl;
        }
    } while (row < 0 || row > 2);

    // Prompt user for column input (0-2)
    do {
        cout << "Enter column (0-2): ";
        cin >> col;
        if (col < 0 || col > 2) {
            cout << "Invalid column. Please enter a number between 0 and 2." << endl;
        }
    } while (col < 0 || col > 2);

    // Check if the selected cell is empty
    if (board[row][col] != ' ') {
        cout << "Cell already occupied. Please select another cell." << endl;
        userIn(board); // Recursively prompt for valid input
    } else {
        board[row][col] = 'X'; // Place 'X' in the selected cell
    }
}

void prntbrd(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j != 2) {
                cout << board[i][j] << " | ";
            } else {
                cout << board[i][j];
            }
        }
        cout << endl;
        if(i != 2) {
            cout << "---------" << endl;
        }
    }
}

void compIn(char board[3][3]){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,2);
    int row=dist(gen);
    int col=dist(gen);
    if (board[row][col] != ' ') {
        compIn(board); // Recursively prompt for valid input
    } else {
        board[row][col] = 'O'; // Place 'X' in the selected cell
    }

}

char isWin(char board[3][3]){
    // Check rows and columns for a win
    for(int i = 0; i < 3; i++){
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
            return 'X'; // Row i is all 'X'
        }
        else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
            return 'O'; // Row i is all 'X'
        }
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
            return 'O'; // Column i is all 'X'
        }
        else if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
            return 'O'; // Column i is all 'X'
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
        (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
        return 'X'; // Diagonal win
    }
    else if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
        (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
        return 'O'; // Diagonal win
    }

    return ' '; // No win condition met
}

int main() {
    int cells=9;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    cout << "Tic-Tac-Toe Game Started!" << endl;
    prntbrd(board);

    while (isWin(board)==' ' && cells>0) {
        cout << "Player's turn:" << endl;
        userIn(board);
        cells--;
        cout << "Computer's turn:" << endl;
        compIn(board);
        cells--;
        prntbrd(board);
    }
    if(isWin(board)=='X')
    {cout << "Player wins!" << endl;}
    else if(isWin(board)=='O'){
        cout<<"Computer wins!"<<endl;
    }
    return 0;
}
