#ifndef CSQUARE_H
#define CSQUARE_H

#include <GL/glut.h>
#include "Vector.hpp"

class Square {
    GLfloat vertex[4][3]; // 3D vertices
    GLfloat r, g, b;      // Color
    float rotationX, rotationY, rotationZ; // Rotation around each axis

public:
    Square(float *v0, float *v1, float *v2, float *v3, float red, float green, float blue);
    void applyRotation();
    void draw();
    GLfloat* getVertex(int index);
    void setRotationZ(float angle);
    float getRotationZ() const;
    void setColor(float red, float green, float blue);
    void getColor(float& red, float& green, float& blue) const;
};

#endif
