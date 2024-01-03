/*
 * Description: Rubiks Cube reference design
 * Author: Inderpreet Warraich
 * Version: 2023-12-02
 */

#include "World.hpp"

using namespace std;

// Constructor for the World class
World::World() {
    // Initialize any required elements for the world
}

// Destructor for the World class
World::~World(){

}

// Function to draw the world
void World::draw() {
    rubiksCube.draw();  // Draw the Rubik's Cube
    glutPostRedisplay(); // Request to redraw the scene for continuous animation
}

// Function to reset the world to its initial state
void World::reset(){

}

// Rotate the front face of the Rubik's Cube clockwise
void World::rotateFrontClockwise() {
    rubiksCube.rotateFrontClockwise();  // Call the corresponding method on the Rubik's Cube
    cout << "Rotating front face clockwise" << endl;  // Log the action
}

// Rotate the back face of the Rubik's Cube clockwise
void World::rotateBackClockwise() {
    rubiksCube.rotateBackClockwise();  // Call the corresponding method on the Rubik's Cube
}

// Rotate the left face of the Rubik's Cube clockwise
void World::rotateLeftClockwise() {
    rubiksCube.rotateLeftClockwise();  // Call the corresponding method on the Rubik's Cube
}

// Rotate the right face of the Rubik's Cube clockwise
void World::rotateRightClockwise() {
    rubiksCube.rotateRightClockwise();  // Call the corresponding method on the Rubik's Cube
}

// Rotate the top face of the Rubik's Cube clockwise
void World::rotateTopClockwise() {
    rubiksCube.rotateTopClockwise();  // Call the corresponding method on the Rubik's Cube
}

// Rotate the bottom face of the Rubik's Cube clockwise
void World::rotateBottomClockwise() {
    rubiksCube.rotateBottomClockwise();  // Call the corresponding method on the Rubik's Cube
}
