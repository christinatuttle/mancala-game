//  ----------------------------------------------------------------------------
//  Header file for all PLayer programs.                              player.hpp
// -----------------------------------------------------------------------------
#pragma once
#include <iostream>
using namespace std;

enum Player { NORTH, SOUTH };
// extend the operator output<<() to player type
inline ostream& operator<<(ostream& out, const Player& p) {
    if (p == NORTH) {
        return out << "NORTH";
    } else {
        return out << "SOUTH";
    }
}