#include "TetrisView.h"
#include <iostream>

TetrisView::TetrisView(int width, int height)
    : screenWidth(width), screenHeight(height) {}

void TetrisView::Render(const TetrisModel& model) {
    // Affichage du terrain et de la pièce courante
    const std::vector<unsigned char>& field = model.GetField();

    for (int y = 0; y < model.GetFieldHeight(); y++) {
        for (int x = 0; x < model.GetFieldWidth(); x++) {
            unsigned char val = field[y * model.GetFieldWidth() + x];
            std::cout << (val == 9 ? "#" : (val == 0 ? "." : "X"));
        }
        std::cout << std::endl;
    }
}

void TetrisView::DisplayGameOver() {
    std::cout << "GAME OVER" << std::endl;
}
