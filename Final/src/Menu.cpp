/*
 * Description: Rubiks Cube reference design
 * Author: Inderpreet Warraich
 * Version: 2023-12-02
 */

#include "Menu.hpp"
#include "World.hpp"
#include "Camera.hpp"


extern World myWorld;
extern Camera myCamera;

void menu() {


    GLint RubiksCube_Menu = glutCreateMenu(rubiksCubeMenu);
    glutAddMenuEntry("Front Clockwise", 1);
    glutAddMenuEntry("Back Clockwise", 2);
    glutAddMenuEntry("Left Clockwise", 3);
    glutAddMenuEntry("Right Clockwise", 4);
    glutAddMenuEntry("Top Clockwise", 5);
    glutAddMenuEntry("Bottom Clockwise", 6);

	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Reset", 1);
	glutAddSubMenu("Rubik's Cube", RubiksCube_Menu);
	glutAddMenuEntry("Quit", 2);
}

void mainMenu(GLint option) {
	switch (option){
		case 1:
			myWorld.reset();
			myCamera.reset();
			break;
		case 2:
			exit(0);
			break;
	}
	glutPostRedisplay();
}

void rubiksCubeMenu(GLint option) {
    RubiksCube2x2& cube = myWorld.getRubiksCube();
    switch (option) {
        case 1:
        	myWorld.rotateFrontClockwise();
            break;
        case 2:
            myWorld.rotateBackClockwise();
            break;
        case 3:
            myWorld.rotateLeftClockwise();
            break;
        case 4:
            myWorld.rotateRightClockwise();
            break;
        case 5:
            myWorld.rotateTopClockwise();
            break;
        case 6:
            myWorld.rotateBottomClockwise();
            break;
    }
    glutPostRedisplay();
}

