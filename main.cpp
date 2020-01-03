//  ---------------------------------------------------------------------------
//  Main program for running Kalah game system                         main.cpp
// ----------------------------------------------------------------------------
#include "game.hpp"
void playGame();
// ----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    cout << "Welcome to Mancala!\n";
    playGame();
    return 0;
}

void playGame() {
    Game g;
    while (!g.isOver()) {
        cout << "\n----------\n";
        cout << g.activePlayer() << "'s turn:\n";
        g.printBoard();
        cout << "Please enter a pit number for " << g.activePlayer() << " (q to quit): \n";
        char* inStr = new char[4];
        cin >> inStr;
        if (inStr[0] == 'q') {
            cout << "Quitting game\n";
            delete[] inStr;
            return;
        }
        int move = atoi(inStr);
        while (!g.isValidMove(move)) { // Check if move is valid
            cout << "Invalid move\n";
            cout << "Please enter a pit number for " << g.activePlayer() << " (q to quit): \n";
            cin >> inStr;
            if (inStr[0] == 'q') {
                cout << "Quitting game\n";
                delete[] inStr;
                return;
            }
            move = atoi(inStr);
        }
        cout << g.activePlayer() << " playing move " << move << "\n";
        g.doMove(move);
        if (g.getRepeatTurn()) {
            cout << g.activePlayer() << " gets another turn\n";
        } else {
            cout << "Turn is over\n";
        }
        delete[] inStr;
    }
    g.endGame();
}