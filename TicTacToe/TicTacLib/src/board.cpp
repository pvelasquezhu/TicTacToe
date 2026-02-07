#include "board.hpp"
#include <algorithm>

namespace tic {

Board::Board() {
    reset();
}


bool Board::set(Loc loc, Cell mark) {
    if (_inBounds(loc) && _cell(loc) == Cell::Empty) {
        _cell(loc) = mark;
        return true;
    }
    else {
        return false;
    }
}


Board::Cell Board::get(Loc loc) const {
    if (_inBounds(loc)) {
        return _cell(loc);
    }
    else {
        return Cell::Empty;
    }
}


bool Board::full() const {
    return std::all_of(_cells.begin(), _cells.end(), [](Cell c) { return c != Cell::Empty; });
}


Board::Cell Board::winner() const {
    for (int i = 0; i < SIZE; ++i) {
        if (_isWin(_cell({ i, 0 }), _cell({ i, 1 }), _cell({ i, 2 }))) {
            return _cell({ i, 0 });
        }
        if (_isWin(_cell({ 0, i }), _cell({ 1, i }), _cell({ 2, i }))) {
            return _cell({ 0, i });
        }
    }
    if (_isWin(_cell({ 0, 0 }), _cell({ 1, 1 }), _cell({ 2, 2 }))) {
        return _cell({ 0, 0 });
    }
    if (_isWin(_cell({ 2, 0 }), _cell({ 1, 1 }), _cell({ 0, 2 }))) {
        return _cell({ 2, 0 });
    }
    return Cell::Empty;
}


void Board::reset() {
    _cells.clear();
    _cells.resize(SIZE * SIZE, Cell::Empty);
}


Board::Cell& Board::_cell(Loc loc) {
    return _cells[loc.row * SIZE + loc.col];
}


Board::Cell const& Board::_cell(Loc loc) const {
    return _cells[loc.row * SIZE + loc.col];
}


bool Board::_isWin(Cell a, Cell b, Cell c) const {
    return a != Cell::Empty && a == b && b == c;
}


bool Board::_inBounds(Loc loc) const {
    return loc.row >= 0 && loc.row < SIZE && loc.col >= 0 && loc.col < SIZE;
}

} // namespace tic
