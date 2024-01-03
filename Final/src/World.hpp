/*
 * Description: SimpleView reference design
 * Author: HBF
 * Version: 2022-10-03
 */

#ifndef CWORLD_HPP
#define CWORLD_HPP

#include <iostream>
#include <list>
#include <vector>
#include "RubiksCube2x2.hpp"


class World {
private:
	RubiksCube2x2 rubiksCube;
public:
    RubiksCube2x2& getRubiksCube() {
        return rubiksCube;
    }
	World();
	~World();
	void draw();   /* draw all objects in the world */
	void reset();  /* resets all objects */
    void rotateFrontClockwise();
    void rotateBackClockwise();
    void rotateLeftClockwise();
    void rotateRightClockwise();
    void rotateTopClockwise();
    void rotateBottomClockwise();
};

#endif
