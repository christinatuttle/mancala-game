// -----------------------------------------------------------------------------
//  Implementation file for all Game programs.                  game.cpp
// -----------------------------------------------------------------------------
#include "game.hpp"
// ---------------------------------------------------------------------
// Determine if the user input is a legal move
bool Game::isValidMove(int move) {
    return (move >= 1 && move <= 6) && (b.pitFull(current, move));
}
// Perform the move
void Game::doMove(int move) {
    int pitIndex = b.sow(current, move);
    // if last seed is dropped in own store, player gets another turn (do not switch player)
    if ((current == NORTH && pitIndex == 0) || (current == SOUTH && pitIndex == 7)) {
        repeatTurn = true;
    } else {
        repeatTurn = false;
        if (current == NORTH) { // switch player
            current = SOUTH;
        } else {
            current = NORTH;
        }
    }
}
// Determined whether game is over or not
bool Game::isOver() { return b.isOverBoard(); }
// Moves seeds from the other player's hosues to its own store
void Game::endGame() { b.endGameBoard(); }