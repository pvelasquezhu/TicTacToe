#pragma once

#include <vector>

namespace tic {


class Board {
public:
    constexpr static int SIZE = 3;

    enum class Cell { Empty, X, O };

    struct Loc { int row; int col; };


    Board();

    bool set(Loc loc, Cell mark);

    Cell get(Loc loc) const;

    bool full() const;

    Cell winner() const;

    void reset();

private:
    std::vector<Cell> _cells;

    Cell& _cell(Loc loc);
    Cell const& _cell(Loc loc) const;
    bool _isWin(Cell a, Cell b, Cell c) const;
    bool _inBounds(Loc loc) const;
};


} // namespace tic
