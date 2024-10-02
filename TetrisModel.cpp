#include "TetrisModel.h"
#include <cstdlib>

TetrisModel::TetrisModel(int width, int height) 
    : fieldWidth(width), fieldHeight(height), field(width * height, 0) {
    
    tetromino[0].append("....XX..XX.."); // Exemple de pièce
    tetromino[1].append("....X...X...X...X.");

    InitializeField();
    ResetPiece();
}

void TetrisModel::InitializeField() {
    for (int x = 0; x < fieldWidth; x++) 
        for (int y = 0; y < fieldHeight; y++) 
            field[y * fieldWidth + x] = (x == 0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0;
}

void TetrisModel::ResetPiece() {
    currentPiece = rand() % 7;
    currentRotation = 0;
    currentX = fieldWidth / 2 - 2;
    currentY = 0;
}

bool TetrisModel::CheckGameOver() {
    return !DoesPieceFit(currentPiece, currentRotation, currentX, currentY);
}

int TetrisModel::Rotate(int px, int py, int r) {
    // Logique de rotation
    int pi = 0;
    switch (r % 4) {
        case 0: pi = py * 4 + px; break;    // 0 degrés
        case 1: pi = 12 + py - (px * 4); break; // 90 degrés
        case 2: pi = 15 - (py * 4) - px; break; // 180 degrés
        case 3: pi = 3 - py + (px * 4); break;  // 270 degrés
    }
    return pi;
}

bool TetrisModel::DoesPieceFit(int tetrominoIndex, int rotation, int posX, int posY) {
    // Logique pour vérifier si la pièce entre dans la grille
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++) {
            int pi = Rotate(px, py, rotation);
            int fi = (posY + py) * fieldWidth + (posX + px);
            if (tetromino[tetrominoIndex][pi] == 'X') {
                if (posX + px < 0 || posX + px >= fieldWidth || posY + py >= fieldHeight) return false;
                if (field[fi] != 0) return false;
            }
        }
    return true;
}

void TetrisModel::MovePieceLeft() {
    if (DoesPieceFit(currentPiece, currentRotation, currentX - 1, currentY))
        currentX--;
}

void TetrisModel::MovePieceRight() {
    if (DoesPieceFit(currentPiece, currentRotation, currentX + 1, currentY))
        currentX++;
}

void TetrisModel::RotatePiece() {
    if (DoesPieceFit(currentPiece, currentRotation + 1, currentX, currentY))
        currentRotation++;
}

void TetrisModel::MovePieceDown() {
    if (DoesPieceFit(currentPiece, currentRotation, currentX, currentY + 1))
        currentY++;
    else {
        PlacePiece(currentPiece, currentRotation, currentX, currentY);
        ResetPiece();
    }
}

void TetrisModel::PlacePiece(int tetrominoIndex, int rotation, int posX, int posY) {
    // Place la pièce dans le terrain
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
            if (tetromino[tetrominoIndex][Rotate(px, py, rotation)] == 'X')
                field[(posY + py) * fieldWidth + (posX + px)] = tetrominoIndex + 1;
}
