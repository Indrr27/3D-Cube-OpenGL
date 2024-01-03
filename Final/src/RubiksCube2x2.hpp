#ifndef RUBIKSCUBE2X2_H
#define RUBIKSCUBE2X2_H

#include "Square.hpp"
#include <vector>
#include "Vector.hpp"

class RubiksCube2x2 {
private:
    std::vector<Square> squares; // Squares representing the faces of the mini-cubes


public:
    RubiksCube2x2();
    void draw();
    void rotateFrontClockwise();
    void rotateBackClockwise();
    void rotateLeftClockwise();
    void rotateRightClockwise();
    void rotateTopClockwise();
    void rotateBottomClockwise();
};

#endif
