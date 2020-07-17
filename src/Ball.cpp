///////////////////////////////////////////////////////////
//  Ball.cpp
//  Implementation of the Class Ball
//  Created on:      14-�����-2019 03:41:53 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Ball.h"
#include "GameConfig.h"


Ball::Ball(View* v){
	int x,y;
	this->angle = 250;
	this->radius = 15;
	this->isThrown = false;
	pParentView = v;
	pParentView->getGameAreaDim(x,y);
	this->setPos(x/2,y - 15 - 10 - this->radius);
}



Ball::~Ball(){

}

void Ball::render(SDL_Renderer* renderer)
{
	this->draw(renderer);
}


void Ball::updatePos(){

	if(isThrown == true)
	{
		/*Update ball postion*/
		int x,y;

		int curr_angle = this->getAngle();

		this->getPos(x,y);

		/*Down right*/
		if(curr_angle == 0)
		{
			x+=1;
		}
		else if(curr_angle < 90)
		{
			x+=1;
			y+=1;
		}
		else if(curr_angle == 90)
		{
			y+=1;
		}
		/*Down left*/
		else if(curr_angle < 180)
		{
			x-=1;
			y+=1;
		}
		else if(curr_angle == 180)
		{
			x-=1;
		}
		/*Up left*/
		else if(curr_angle < 270)
		{
			x-=1;
			y-=1;
		}
		else if(curr_angle == 270)
		{
			y-=1;
		}
		/*Up right*/
		else if(curr_angle < 360)
		{
			x+=1;
			y-=1;
		}

		this->setPos(x,y);
	}
}


void Ball::setAngle(int angle){
	this->angle = angle%360;
}

int Ball::getAngle(){
	return this->angle;
}

bool Ball::isBallInRange(int x1,int x2,int y1,int y2,int& col_pt_x,int& col_pt_y)
{
	bool ret = false;
	int x,y;
	int circum_x = 0,circum_y_positive = 0,circum_y_minus = 0;

	int curr_angle = this->getAngle();

	for(x = this->radius; x >= -this->radius;x--)
	{
		y = sqrt(this->radius*this->radius - (x*x)) ;

		circum_x = this->pos_x + x;
		circum_y_positive = this->pos_y + y;
		circum_y_minus = this->pos_y - y;

		if(circum_x <= x2 && circum_x>= x1 && circum_y_positive <= y2 && circum_y_positive>= y1
				|| (circum_x <= x2 && circum_x>= x1 && circum_y_minus <= y2 && circum_y_minus>= y1))
		{
			col_pt_x = circum_x;
			col_pt_y = circum_y_positive;
			ret=true;
		}
	}

	return ret;
}

void Ball::_throw(void)
{
	this->isThrown = true;
}

bool Ball::is_Thrown()
{
	return this->isThrown;
}
