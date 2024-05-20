# 2x2 Rubik's Cube Simulation

## Overview

The objective of this project is to use OpenGL to create an interactive 2x2 Rubik's Cube simulation. This program provides users with a tool to manipulate a simulated Rubik's Cube, enhancing puzzle comprehension and solution. The simulation includes cube-solving algorithms, user interaction, and graphic rendering.

## Features

### Problem Solving and Algorithms

- **Cube Representation:** The cube is represented as a 3D model, with each mini-cube (cubie) having distinct colors on its faces.
- **Rotation Logic:** Algorithms accurately rotate the faces and the whole cube while maintaining the state of each face.
- **Solving Algorithm:** An optional feature provides users with step-by-step solutions based on the cube's current state.
- **User Interaction:** Handles user inputs to rotate and shuffle the cube.

### Design Considerations

- **Model:** The cube's 3D model visually replicates a real 2x2 Rubik's Cube, with each mini-cube rendered in 3D and appropriately colored.
- **View:** A graphical user interface (GUI) allows users to view the cube from different angles and interact with it. The view is implemented using OpenGL, providing real-time 3D rendering.
- **Controller:** The application handles user inputs for cube rotations, shuffling, and solving. It includes keyboard and mouse controls for intuitive interaction.

**Note:** Currently, the Rubik's Cube does not rotate.

## Getting Started

### Prerequisites

- OpenGL
- A C++ compiler

### Running the Code

1. **Download All Files:** Ensure all files from the repository are downloaded.
2. **Run the Code:** Execute the `RubiksCube2x2.cpp` file.

```sh
g++ -o RubiksCube2x2 RubiksCube2x2.cpp -lGL -lGLU -lglut
./RubiksCube2x2
