///////////////////////////////////////////////////////////
//  Barrier.cpp
//  Implementation of the Class Barrier
//  Created on:      14-�����-2019 05:31:23 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Barrier.h"


Barrier::Barrier(){
	isHidden = false;
}



Barrier::~Barrier(){

}





void Barrier::getPos(int& x ,int& y)
{
	x=this->pos_x;
	y=this->pos_y;
}
void Barrier::setPos(int x,int y)
{
	this->pos_x=x;
	this->pos_y=y;
}
void Barrier::setDim(int x,int y)
{
	this->dim_x=x;
	this->dim_y=y;
}
void Barrier::getDim(int& x,int& y)
{
	x=this->dim_x;
	y=this->dim_y;
}

void Barrier::getDimRange(int& x1,int& x2,int& y1,int& y2)
{
	int brick_x,brick_y;
	int brick_dim_x,brick_dim_y;

	this->getPos(brick_x,brick_y);
	this->getDim(brick_dim_x,brick_dim_y);

	x1 = brick_x;
	x2 = brick_x + brick_dim_x;

	y1 = brick_y;
	y2 = brick_y + brick_dim_y;
}


void Barrier::render(SDL_Renderer* renderer){
	if(this->isHidden == false)
	{
	    SDL_Rect outlineRect = { .x = this->pos_x , .y = this->pos_y, .w = this->dim_x, .h = this->dim_y};
	    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0x00, 0xFF );
	    SDL_RenderDrawRect( renderer, &outlineRect );
	}
}

void Barrier::setBarrierType(tBarrier b)
{
	this->barrier_type = b;
}
tBarrier Barrier::getBarrierType()
{
	return this->barrier_type;
}

bool Barrier::checkIsHidden()
{
	return this->isHidden;
}

void Barrier::hide()
{
	this->isHidden = true;
}
