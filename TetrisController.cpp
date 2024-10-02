#include "TetrisController.h"
#include <conio.h>

TetrisController::TetrisController(TetrisModel& m, TetrisView& v)
    : model(m), view(v), gameOver(false) {}

void TetrisController::HandleInput() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'a': model.MovePieceLeft(); break;
            case 'd': model.MovePieceRight(); break;
            case 's': model.RotatePiece(); break;
            case 'w': model.MovePieceDown(); break;
        }
    }
}

void TetrisController::UpdateGame() {
    view.Render(model);
    if (model.CheckGameOver()) {
        gameOver = true;
        view.DisplayGameOver();
    }
}
