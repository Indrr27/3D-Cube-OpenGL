/*
 * Description: Rubiks Cube reference design
 * Author: Inderpreet Warraich
 * Version: 2023-12-02
 */


#include "Square.hpp"
#include <cmath>

// Constructor for the Square class
Square::Square(float *v0, float *v1, float *v2, float *v3, float red, float green, float blue) {
    // Initialize rotations to zero
    rotationX = rotationY = rotationZ = 0.0f;

    // Copy vertices from the provided arrays
    for (int i = 0; i < 3; ++i) {
        vertex[0][i] = v0[i];
        vertex[1][i] = v1[i];
        vertex[2][i] = v2[i];
        vertex[3][i] = v3[i];
    }

    // Set color
    r = red; g = green; b = blue;
}

// Method to draw the square
void Square::draw() {
    applyRotation(); // Apply rotation before drawing

    // Set color of the square
    glColor3f(r, g, b);

    // Draw the square as a quadrilateral
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; ++i) {
        glVertex3fv(vertex[i]); // Specify each vertex
    }
    glEnd(); // End drawing the quadrilateral
}

// Method to apply rotation transformations
void Square::applyRotation() {
    glPushMatrix();

    // Apply rotations around each axis
    glRotatef(rotationX, 1.0f, 0.0f, 0.0f); // Rotate around X axis
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f); // Rotate around Y axis
    glRotatef(rotationZ, 0.0f, 0.0f, 1.0f); // Rotate around Z axis

    glPopMatrix();
}

// Method to get a vertex of the square
GLfloat* Square::getVertex(int index) {
    return vertex[index]; // Return the specified vertex
}

// Method to set the rotation around Z-axis
void Square::setRotationZ(float angle) {
    rotationZ = angle; // Set rotation angle
}

// Method to get the rotation around Z-axis
float Square::getRotationZ() const {
    return rotationZ; // Return rotation angle
}

// Method to set the color of the square
void Square::setColor(float red, float green, float blue) {
    r = red;
    g = green;
    b = blue;
}

// Method to get the color of the square
void Square::getColor(float& red, float& green, float& blue) const {
    red = r;
    green = g;
    blue = b;
}
