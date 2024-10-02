#ifndef TETRISCONTROLLER_H
#define TETRISCONTROLLER_H

#include "TetrisModel.h"
#include "TetrisView.h"

class TetrisController {
public:
    TetrisController(TetrisModel& model, TetrisView& view);
    void HandleInput();
    void UpdateGame();

private:
    TetrisModel& model;
    TetrisView& view;
    bool gameOver;
};

#endif
