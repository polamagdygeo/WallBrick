///////////////////////////////////////////////////////////
//  Bar.cpp
//  Implementation of the Class Bar
//  Created on:      14-�����-2019 03:41:54 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Bar.h"
#include "tBarrier.h"


Bar::Bar(View* v){
	int x,y;
	this->setBarrierType(BAR);
	this->setPos(640/2 - 75,480 - 15 - 10);
	pParentView = v;
	pParentView->get

	this->setDim(150,15);
}



Bar::~Bar(){

}


void Bar::move(tDirection dir){
	int prev_x,prev_y;

	this->getPos(prev_x,prev_y);


	if(dir == DIR_RIGHT)
	{
		if(prev_x+this->dim_x < 640-5-10)
		{
			this->setPos(prev_x+bar_step,prev_y);
		}
	}
	else if(dir == DIR_LEFT)
	{
		if(prev_x > 5+10)
		{
			this->setPos(prev_x-bar_step,prev_y);
		}
	}
}
