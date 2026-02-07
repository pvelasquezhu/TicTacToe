#pragma once

#include "./board.hpp"
#include <utility>

namespace tic {


struct ConsoleUI {

    void welcome();

    void presentBoard(Board const& board);

    Board::Loc acceptMove(Board::Cell player);

    void reportInvalidMove();

    void reportWinner(Board::Cell winner);

};


} // namespace tic
