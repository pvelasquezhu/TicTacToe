#pragma once
#include "./board.hpp"

namespace tic {


template<typename UI>
class Game {
public:
    void initialize();
    bool isOver() const;
    void takeTurn(); 
    void reportOutcome();

private:
    UI _ui;
    Board _board;
    Board::Cell currentPlayer;
};


template<typename UI>
void Game<UI>::initialize() {
    _ui.welcome();
    _board.reset();
    currentPlayer = Board::Cell::X;
}


template<typename UI>
bool Game<UI>::isOver() const {
    return _board.winner() != Board::Cell::Empty || _board.full();
}


template<typename UI>
void Game<UI>::takeTurn() {
    _ui.presentBoard(_board);
    auto loc = _ui.acceptMove(currentPlayer);
    if (_board.set(loc, currentPlayer)) {
        currentPlayer = (currentPlayer == Board::Cell::X) ? Board::Cell::O : Board::Cell::X;
    }
    else {
        _ui.reportInvalidMove();
    }
}


template<typename UI>
void Game<UI>::reportOutcome() {
    _ui.presentBoard(_board);
    _ui.reportWinner(_board.winner());
}


} // namespace tic