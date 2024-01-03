/*
 * Description: Rubiks Cube reference design
 * Author: Inderpreet Warraich
 * Version: 2023-12-02
 */


#include "RubiksCube2x2.hpp"

RubiksCube2x2::RubiksCube2x2() {
    float miniCubeSize = 1.0f;  // Size of each mini-cube
    float offset = miniCubeSize * 1.1f;  // Offset between mini-cubes

    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 2; z++) {
                // Calculate center positions for each face of the mini-cube
                float centerX = (x * offset) - offset / 2;
                float centerY = (y * offset) - offset / 2;
                float centerZ = (z * offset) - offset / 2;

                // Front face (red)
                float frontFaceVertices[4][3] = {
                    {centerX - miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX - miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ + miniCubeSize / 2}
                };
                Square frontFace(&frontFaceVertices[0][0], &frontFaceVertices[1][0], &frontFaceVertices[2][0], &frontFaceVertices[3][0], 1.0f, 0.0f, 0.0f);
                squares.push_back(frontFace);


                // Back face (orange)
                float backFaceVertices[4][3] = {
                    {centerX - miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX - miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ - miniCubeSize / 2}
                };
                Square backFace(&backFaceVertices[0][0], &backFaceVertices[1][0], &backFaceVertices[2][0], &backFaceVertices[3][0], 1.0f, 0.5f, 0.0f);
                squares.push_back(backFace);

                // Top face (yellow)
                float topFaceVertices[4][3] = {
                    {centerX - miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX - miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ - miniCubeSize / 2}
                };
                Square topFace(&topFaceVertices[0][0], &topFaceVertices[1][0], &topFaceVertices[2][0], &topFaceVertices[3][0], 1.0f, 1.0f, 0.0f);
                squares.push_back(topFace);

                // Left face (green)
                float leftFaceVertices[4][3] = {
                    {centerX - miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX - miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX - miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX - miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ - miniCubeSize / 2}
                };
                Square leftFace(&leftFaceVertices[0][0], &leftFaceVertices[1][0], &leftFaceVertices[2][0], &leftFaceVertices[3][0], 0.0f, 1.0f, 0.0f);
                squares.push_back(leftFace);

                // Right face (blue)
                float rightFaceVertices[4][3] = {
                    {centerX + miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY + miniCubeSize / 2, centerZ + miniCubeSize / 2}
                };
                Square rightFace(&rightFaceVertices[0][0], &rightFaceVertices[1][0], &rightFaceVertices[2][0], &rightFaceVertices[3][0], 0.0f, 0.0f, 1.0f);
                squares.push_back(rightFace);
                // Bottom face (white)
                float bottomFaceVertices[4][3] = {
                    {centerX - miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ - miniCubeSize / 2},
                    {centerX + miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ + miniCubeSize / 2},
                    {centerX - miniCubeSize / 2, centerY - miniCubeSize / 2, centerZ + miniCubeSize / 2}
                };
                Square bottomFace(&bottomFaceVertices[0][0], &bottomFaceVertices[1][0], &bottomFaceVertices[2][0], &bottomFaceVertices[3][0], 1.0f, 1.0f, 1.0f);
                squares.push_back(bottomFace);
            }
        }
    }
}

void RubiksCube2x2::rotateFrontClockwise() {

    Square tempTopLeft = squares[0];
    Square tempTopRight = squares[1];
    Square tempBottomRight = squares[3];
    Square tempBottomLeft = squares[2];


    squares[0] = tempBottomLeft;
    squares[1] = tempTopLeft;
    squares[2] = tempTopRight;
    squares[3] = tempBottomRight;


    float r, g, b;
    tempBottomLeft.getColor(r, g, b);
    squares[0].setColor(r, g, b);
    tempTopLeft.getColor(r, g, b);
    squares[1].setColor(r, g, b);
    tempTopRight.getColor(r, g, b);
    squares[2].setColor(r, g, b);
    tempBottomRight.getColor(r, g, b);
    squares[3].setColor(r, g, b);


    squares[0].setRotationZ(squares[0].getRotationZ() + 90.0f);
    squares[1].setRotationZ(squares[1].getRotationZ() + 90.0f);
    squares[2].setRotationZ(squares[2].getRotationZ() + 90.0f);
    squares[3].setRotationZ(squares[3].getRotationZ() + 90.0f);
}



void RubiksCube2x2::rotateBackClockwise() {

    Square tempTopLeft = squares[4];
    Square tempTopRight = squares[5];
    Square tempBottomRight = squares[7];
    Square tempBottomLeft = squares[6];


    squares[4] = tempBottomLeft;
    squares[5] = tempTopLeft;
    squares[6] = tempTopRight;
    squares[7] = tempBottomRight;


}


void RubiksCube2x2::rotateLeftClockwise() {

    Square tempTopLeft = squares[8];
    Square tempTopRight = squares[9];
    Square tempBottomRight = squares[11];
    Square tempBottomLeft = squares[10];


    squares[8] = tempBottomLeft;
    squares[9] = tempTopLeft;
    squares[10] = tempTopRight;
    squares[11] = tempBottomRight;


}



void RubiksCube2x2::rotateRightClockwise() {

    Square tempTopLeft = squares[12];
    Square tempTopRight = squares[13];
    Square tempBottomRight = squares[15];
    Square tempBottomLeft = squares[14];


    squares[12] = tempBottomLeft;
    squares[13] = tempTopLeft;
    squares[14] = tempTopRight;
    squares[15] = tempBottomRight;



}




void RubiksCube2x2::rotateTopClockwise() {

    Square tempTopLeft = squares[16];
    Square tempTopRight = squares[17];
    Square tempBottomRight = squares[19];
    Square tempBottomLeft = squares[18];


    squares[16] = tempBottomLeft;
    squares[17] = tempTopLeft;
    squares[18] = tempTopRight;
    squares[19] = tempBottomRight;

}





void RubiksCube2x2::rotateBottomClockwise() {


}

void RubiksCube2x2::draw() {
    // Draw each square of the cube
    for (std::vector<Square>::iterator it = squares.begin(); it != squares.end(); ++it) {
        it->draw();
    }
}





