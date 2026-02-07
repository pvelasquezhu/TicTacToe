#include "game.hpp"
#include "console.hpp"

int main() {

    tic::Game<tic::ConsoleUI> game;

    game.initialize();
    while (!game.isOver()) {
        game.takeTurn();
    }
    game.reportOutcome();
}
