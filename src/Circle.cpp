/*
 * Circle.cpp
 *
 *  Created on: Aug 23, 2019
 *      Author: pola
 */

#include "Circle.h"
#include <math.h>

Circle::Circle() {
	// TODO Auto-generated constructor stub

}

Circle::~Circle() {
	// TODO Auto-generated destructor stub
}

void Circle::draw(SDL_Renderer* renderer){
	signed int x_value;
	int y_value;

	for(x_value = this->radius; x_value >= -this->radius;x_value--)
	{
		y_value = sqrt(this->radius*this->radius - (x_value*x_value)) ;
		SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0x00, 0xFF );
		SDL_RenderDrawPoint( renderer,x_value + this->pos_x,y_value + this->pos_y);
		SDL_RenderDrawPoint( renderer,x_value + this->pos_x,this->pos_y - y_value);
	}
}

void Circle::getPos(int& x,int& y){
	x = this->pos_x;
	y = this->pos_y;
}

void Circle::setPos(int x,int y){
	this->pos_x = x;
	this->pos_y = y;
}

void Circle::setRad(int r)
{
	this->radius = r;
}

int Circle::getRad()
{
	return this->radius;
}

