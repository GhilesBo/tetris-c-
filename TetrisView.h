#ifndef TETRISVIEW_H
#define TETRISVIEW_H

#include "TetrisModel.h"

class TetrisView {
public:
    TetrisView(int screenWidth, int screenHeight);
    void Render(const TetrisModel& model);
    void DisplayGameOver();

private:
    int screenWidth, screenHeight;
};

#endif
