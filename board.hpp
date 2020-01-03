//  ----------------------------------------------------------------------------
//  Header file for all Board programs.                              board.hpp
// -----------------------------------------------------------------------------
#pragma once
#include <string>
#include <iostream>
#include "player.hpp"
using namespace std;
class Board {
  private:
    // ------------------------------------------------------------------
    int pitArray[14]; // array of pits
  public:
    // -------------------------------------------------------------------
    Board() {
        pitArray[0] = 0;
        for (int i = 1; i < 7; i++) {
            pitArray[i] = 4;
        }
        pitArray[7] = 0;
        for (int i = 8; i < 14; i++) {
            pitArray[i] = 4;
        }
    }
    // -------------------------------------------------------------------
    ostream& print(ostream& out) const;
    bool pitFull(Player p, int nHouse);
    int sow(Player p, int move);
    bool isOverBoard();
    void endGameBoard();
};
// extend the operator output<<() to board type
inline ostream& operator<<(ostream& out, const Board& b) {
    return b.print(out);
}