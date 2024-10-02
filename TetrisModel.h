#ifndef TETRISMODEL_H
#define TETRISMODEL_H

#include <string>
#include <vector>

class TetrisModel {
public:
    TetrisModel(int fieldWidth, int fieldHeight);
    bool DoesPieceFit(int tetrominoIndex, int rotation, int posX, int posY);
    void PlacePiece(int tetrominoIndex, int rotation, int posX, int posY);
    void InitializeField();
    void ResetPiece();
    bool CheckGameOver();
    
    // Getters
    int GetFieldWidth() const { return fieldWidth; }
    int GetFieldHeight() const { return fieldHeight; }
    const std::vector<unsigned char>& GetField() const { return field; }
    int GetCurrentPiece() const { return currentPiece; }
    int GetCurrentRotation() const { return currentRotation; }
    int GetCurrentX() const { return currentX; }
    int GetCurrentY() const { return currentY; }

    void MovePieceLeft();
    void MovePieceRight();
    void RotatePiece();
    void MovePieceDown();

private:
    int fieldWidth, fieldHeight;
    std::vector<unsigned char> field; // Terrain de jeu
    std::string tetromino[7];         // Pièces Tetris
    int currentPiece, currentRotation, currentX, currentY; // État courant de la pièce

    int Rotate(int px, int py, int r);
};

#endif
