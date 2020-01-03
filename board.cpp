// -----------------------------------------------------------------------------
//  Implementation file for Board programs.                  board.cpp
#include "board.hpp"
// -----------------------------------------------------------------------------
// Print board
ostream& Board::print(ostream& out) const {
    for (int i = 0; i < 7; i++) {
        out << " " << "N" << i << "   ";
    }
    out << "\n";
    for (int i = 0; i < 7; i++) {
        out << "[ " << pitArray[i] << "]  ";
    }
    out << "\n\n       ";
    for (int i = 13; i >= 7; i--) {
        out << " " << "S" << 14 - i << "   ";
    }
    out << "\n       ";
    for (int i = 13; i >=7; i--) {
        out << "[ " << pitArray[i] << "]  ";
    }
    out << "\n\n";
    return out;
}
// return true if pit contains seeds; false otherwise
bool Board::pitFull(Player p, int n) {
    if (p == NORTH) {
        return (pitArray[n] != 0);
    } else {
        return (pitArray[14 - n] != 0);
    }
}
// Grab seeds from starting pit and sow down board
int Board::sow(Player p, int move) {
    int currentPit;
    int oppStore;
    if (p == NORTH) {
        currentPit = move;
        oppStore = 7;
    } else {
        currentPit = 14 - move;
        oppStore = 0;
    }
    int seeds = pitArray[currentPit]; // seeds to be sown down board
    pitArray[currentPit] = 0; // remove seeds from pit
    while (seeds > 0) {
        if (currentPit == 0) { // move to end of array if to continue sowing down board
            currentPit = 13;
        } else {
            currentPit--;
        }
        if (currentPit != oppStore) {
            pitArray[currentPit]++;
        }
        seeds--;
    }
    return currentPit;
}
// Iterate through board checking if either player's houses are all empty
bool Board::isOverBoard() {
    int index = 1;
    while (index < 7 && pitArray[index] == 0) {
        index++;
    }
    if (index == 7) {
        return true;
    }
    index = 8;
    while (index < 14 && pitArray[index] == 0) {
        index++;
    }
    if (index == 14)  {
        return true;
    }
    return false;
}
// Scoop all houses from non-empty side and put into player's store
void Board::endGameBoard() {
    for (int i = 1; i < 7; i++) {
        pitArray[0] += pitArray[i];
        pitArray[i] = 0;
    }
    for (int i = 8; i <= 14; i++) {
        pitArray[7] += pitArray[i];
        pitArray[i] = 0;
    }
    if (pitArray[0] > pitArray[7]) {
        cout << "Game over. North won";
    } else if (pitArray[0] < pitArray[7]) {
        cout << "Game over. South won";
    } else {
        cout << "Game over. It's a tie";
    }
}
