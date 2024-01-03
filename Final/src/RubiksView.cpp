/*
 * Description: Rubiks Cube reference design
 * Author: Inderpreet Warraich
 * Version: 2023-12-02
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"

GLint winWidth = 800, winHeight = 800;
GLint isInMove = 0,
	  xbegin = 0,
	  csType = 1, /* coordinate system type: 1 for MCS, 2 for WCS, 3 for VCS */
	  transType = 4;


World myWorld;
Camera myCamera;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	myCamera.setProjectionMatrix();

	myWorld.draw();
	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(myCamera.vangle, (GLfloat)newWidth / (GLfloat)newHeight, myCamera.dnear, myCamera.dfar);
	winWidth = newWidth;
	winHeight = newHeight;
}

static int lastX = 0, lastY = 0;

void mouseActionFcn(int button, int state, int xMouse, int yMouse) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            isInMove = 1;
            lastX = xMouse;
            lastY = yMouse;
        } else if (state == GLUT_UP) {
            isInMove = 0;
        }
    }
}

void mouseMotionFcn(int xMouse, int yMouse) {
    if (isInMove) {
        int dx = xMouse - lastX;
        int dy = yMouse - lastY;

        // Sensitivity factor: the lower the value, the less sensitive the mouse movement will be.
        float sensitivity = 0.1f;

        // Convert mouse delta into degrees, factoring in the sensitivity
        float angleY = static_cast<float>(dx) * sensitivity;
        float angleX = static_cast<float>(dy) * sensitivity;

        // Rotate the camera position around the Y axis
        myCamera.rotate(0.0, 1.0, 0.0, angleY);

        // Rotate the camera position around the X axis
        myCamera.rotate(1.0, 0.0, 0.0, -angleX); // Inverting angleX to have a natural "dragging" feel

        // Update the last position
        lastX = xMouse;
        lastY = yMouse;

        // Redisplay
        glutPostRedisplay();
    }
}



void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Clear the background to black
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthFunc(GL_LEQUAL); // Specify depth comparison function
    glClearDepth(1.0f); // Specify clear value for the depth buffer to the default value
    glEnable(GL_COLOR_MATERIAL); // Ensure the color is used for the material



   // glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    // Set the initial projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Ensure the near and far values are set to reasonable numbers
    gluPerspective(myCamera.vangle, (GLfloat)winWidth / (GLfloat)winHeight, myCamera.dnear, myCamera.dfar);




    // Set the initial modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Bright white specular light
    GLfloat lightPos[] = { 0.0f, 0.0f, 1.0f, 0.0f };

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight); // Set specular light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // Material properties
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Material's specular color
    GLfloat mat_shininess[] = { 50.0 }; // Shininess factor (higher value for more concentrated specular highlight)

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Add GLUT_DEPTH to enable depth buffering
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Rubiks Cube");

    init(); // Initializes the rendering context

    menu();
    glutDisplayFunc(display);
    glutReshapeFunc(winReshapeFcn); // Ensure you have a reshape callback to handle window resizing.
    glutMouseFunc(mouseActionFcn);
    glutMotionFunc(mouseMotionFcn); // Register the motion callback
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}

