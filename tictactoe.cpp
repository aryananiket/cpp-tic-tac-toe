#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic Tac Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
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

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board

    char currentPlayer = 'X';
    int row, col;

    cout << "Tic Tac Toe Game" << endl;

    for (int turn = 0; turn < 9; ++turn) {
        // Print the board
        cout << "Current board:" << endl;
        printBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        // Check if the chosen cell is empty
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            --turn; // Repeat the current turn
            continue;
        }

        // Place the player's mark on the board
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            printBoard(board);
            break;
        }

        // Switch players for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // If the game ends in a draw
    if (!checkWin(board, 'X') && !checkWin(board, 'O')) {
        cout << "It's a draw!" << endl;
        printBoard(board);
    }

    return 0;
}
