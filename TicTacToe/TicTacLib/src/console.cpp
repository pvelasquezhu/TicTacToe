#include "console.hpp"
#include <string>
#include <iostream>
#include <cctype>

namespace tic {


const std::string cellIds = "abcdefghi";


std::ostream& operator <<(std::ostream& os, Board::Cell cell) {
    switch (cell) {
        case Board::Cell::X:     os << "X"; break;
        case Board::Cell::O:     os << "O"; break;
        case Board::Cell::Empty: os << " "; break;
    }
    return os;
}


void ConsoleUI::welcome() {
    std::cout << "Welcome to Tic-Tac-Toe!\n";
}


void ConsoleUI::presentBoard(const Board& board) {
    std::cout << "\n";
    for (int i = 0; i < Board::SIZE; ++i) {
        if (i > 0) std::cout << "-+-+-\n";
        for (int j = 0; j < Board::SIZE; ++j) {
            if (j > 0) std::cout << "|";
            auto cell = board.get({ i, j });
            if (cell == Board::Cell::Empty) {
                std::cout << cellIds[i * Board::SIZE + j];
            }
            else {
                std::cout << cell;
            }
        }
        std::cout << "\n";
    }
}


Board::Loc ConsoleUI::acceptMove(Board::Cell player) {
    char move;
    int pos;
    std::cout << "\nPlayer " << player << ", enter your move: ";
    std::cin >> move;
    pos = cellIds.find(std::tolower(move));
    while (pos == -1) {
        std::cout << "Invalid input. Please enter a valid move: ";
        std::cin >> move;
        pos = cellIds.find(std::tolower(move));
    }
    return { pos / Board::SIZE, pos % Board::SIZE };
}


void ConsoleUI::reportInvalidMove() {
    std::cout << "\nThat cell is taken. Please try again.\n";
}


void ConsoleUI::reportWinner(Board::Cell winner) {
    if (winner == Board::Cell::Empty) {
        std::cout << "\nIt's a draw!\n";
    }
    else {
        std::cout << "\nPlayer " << winner << " wins!\n";
    }
}


} // namespace tic
