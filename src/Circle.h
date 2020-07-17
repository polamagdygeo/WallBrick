/*
 * Circle.h
 *
 *  Created on: Aug 23, 2019
 *      Author: pola
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <SDL2/SDL.h>

class Circle {
public:
	Circle();
	virtual ~Circle();
	void setPos(int x, int y);
	void getPos(int& x, int& y);
	void setRad(int r);
	int getRad();
	void draw(SDL_Renderer* renderer);

protected:
	Sint16 pos_x;
	Sint16 pos_y;
	int radius;

};

#endif /* CIRCLE_H_ */
