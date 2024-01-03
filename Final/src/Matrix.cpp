/*
 * Description: Rubiks Cube reference design
 * Author: Inderpreet Warraich
 * Version: 2023-12-02
 */

#include "Matrix.hpp"
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

Matrix::Matrix() {
	loadIdentity();
}

// mat <- identity matrix
void Matrix::loadIdentity() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
}

// multiplication  mat <- m * mat
void Matrix::matrixPreMultiply(Matrix* m) {
    GLfloat result[4][4] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                result[i][j] += m->mat[i][k] * this->mat[k][j];
            }
        }
    }
    std::copy(&result[0][0], &result[0][0] + 4 * 4, &this->mat[0][0]);
}

// transpose  mat <- mat'
void Matrix::transpose() {
    GLfloat temp;
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            temp = this->mat[i][j];
            this->mat[i][j] = this->mat[j][i];
            this->mat[j][i] = temp;
        }
    }
}

// normalize MC
void Matrix::normalize() {
    GLfloat length;
    for (int i = 0; i < 3; ++i) {
        length = sqrt(mat[i][0]*mat[i][0] + mat[i][1]*mat[i][1] + mat[i][2]*mat[i][2]);
        for (int j = 0; j < 3; ++j) {
            mat[i][j] /= length;
        }
    }
}

// v  <- mat * v
void Matrix::multiplyVector(GLfloat* v) {
    GLfloat result[4] = {0};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i] += this->mat[i][j] * v[j];
        }
    }
    std::copy(result, result + 4, v);
}

void Matrix::rotateMatrix(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
    angle = angle * M_PI / 180.0f;
    GLfloat mag, s, c;
    mag = sqrt(rx*rx + ry*ry + rz*rz);
    s = sin(angle);
    c = cos(angle);

    if (mag > 0) {
        rx /= mag;
        ry /= mag;
        rz /= mag;

        GLfloat xx = rx * rx;
        GLfloat yy = ry * ry;
        GLfloat zz = rz * rz;
        GLfloat xy = rx * ry;
        GLfloat yz = ry * rz;
        GLfloat zx = rz * rx;
        GLfloat xs = rx * s;
        GLfloat ys = ry * s;
        GLfloat zs = rz * s;

        this->mat[0][0] = (1 - c) * xx + c;
        this->mat[1][0] = (1 - c) * xy - zs;
        this->mat[2][0] = (1 - c) * zx + ys;

        this->mat[0][1] = (1 - c) * xy + zs;
        this->mat[1][1] = (1 - c) * yy + c;
        this->mat[2][1] = (1 - c) * yz - xs;

        this->mat[0][2] = (1 - c) * zx - ys;
        this->mat[1][2] = (1 - c) * yz + xs;
        this->mat[2][2] = (1 - c) * zz + c;

        this->mat[3][3] = 1.0f;
    }
}



