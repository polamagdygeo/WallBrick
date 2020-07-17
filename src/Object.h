/*
 * Object.h
 *
 *  Created on: Aug 21, 2019
 *      Author: pola
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <SDL2/SDL.h>

class Object {
public:
	Object();
	virtual ~Object();
	virtual void render(SDL_Renderer* renderer) = 0;
};

#endif /* OBJECT_H_ */
