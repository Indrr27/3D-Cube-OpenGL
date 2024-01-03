/*
 * Description: Rubiks Cube reference design
 * Author: Inderpreet Warraich
 * Version: 2023-12-02
 */
#include <stdio.h>
#include "Camera.hpp"
#include "Matrix.hpp"
#include <math.h>

bool DEBUG = false;

Camera::Camera(){
	eye.set(5.0, 5.0, 10.0);
	ref.set(0, 0, 0);
	viewup.set(0, 0, 1);
	aspect = 1.0, vangle = 40.0, dnear = 1.0, dfar = 15.0;
	setViewNorm();
}

void Camera::reset(void) { // make default camera
	eye.set(5.0, 5.0, 10.0);
	ref.set(0, 0, 0);
	viewup.set(0, 0, 1);
	aspect = 1.0, vangle = 40.0, dnear = 1.0, dfar = 15.0;
	setViewNorm();
}

void Camera::set(Point Eye, Point Look, Vector Up) {
	eye.set(Eye);
	ref.set(Look);
	viewup.set(Up);
	aspect = 1.0, vangle = 40.0, dnear = 1.0, dfar = 15.0;
	setViewNorm();
}

void Camera::setViewNorm() {
	GLfloat x, y, z, sr;
	x = ref.x-eye.x;
	y = ref.y-eye.y;
	z = ref.z-eye.z;
	sr = sqrt(x*x + y*y + z*z);
	x = x/sr;
	y = y/sr;
	z = z/sr;
	viewNorm.set(x, y, z);
}

void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle){
    // Create a rotation matrix
    Matrix rotationMatrix;
    rotationMatrix.rotateMatrix(rx, ry, rz, angle);

    // Create a vector for the eye position relative to the reference point
    Vector eyeVector(eye.x - ref.x, eye.y - ref.y, eye.z - ref.z);

    // Manually multiply the rotation matrix with the eye position vector
    GLfloat x = rotationMatrix.mat[0][0]*eyeVector.x + rotationMatrix.mat[0][1]*eyeVector.y + rotationMatrix.mat[0][2]*eyeVector.z;
    GLfloat y = rotationMatrix.mat[1][0]*eyeVector.x + rotationMatrix.mat[1][1]*eyeVector.y + rotationMatrix.mat[1][2]*eyeVector.z;
    GLfloat z = rotationMatrix.mat[2][0]*eyeVector.x + rotationMatrix.mat[2][1]*eyeVector.y + rotationMatrix.mat[2][2]*eyeVector.z;

    // Update the eye position relative to the reference point
    eye.set(x + ref.x, y + ref.y, z + ref.z);
}

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
    // Update the eye position
    eye.x += tx;
    eye.y += ty;
    eye.z += tz;
}

void Camera::setProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(vangle, aspect, dnear, dfar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, ref.x, ref.y, ref.z, viewup.x,viewup.y,viewup.z);
}

