//  ----------------------------------------------------------------------------
//  Header file for all Game programs.                                  game.hpp
// -----------------------------------------------------------------------------
#pragma once
#include "board.hpp"
class Game {
  private:
    // ------------------------------------------------------------------
    Board b;       // Board for game
    Player current = SOUTH;
    bool repeatTurn;

  public:
    // -------------------------------------------------------------------
    bool isValidMove(int move);
    void doMove(int move);
    bool const getRepeatTurn() {
        return repeatTurn;
    } // getter for repeatTurn variable
    Player const activePlayer() {
        return current;
    } // getter for current active player
    bool isOver();
    void endGame();
    void quitGame();
    void const printBoard() { cout << b; }; // print board
};