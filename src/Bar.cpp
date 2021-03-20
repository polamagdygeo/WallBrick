///////////////////////////////////////////////////////////
//  Bar.cpp
//  Implementation of the Class Bar
//  Created on:      14-�����-2019 03:41:54 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Bar.h"
#include "tBarrier.h"
#include "Frame.h"


Bar::Bar(View* v){
	int x,y;
	pParentView->getGameAreaDim(x,y);
	this->setBarrierType(BAR);
	this->setPos((x / 2), y - BAR_WIDTH - FRAME_THICKNESS - FRAME_BAR_SPACE_Y);
	pParentView = v;
	this->setDim(BAR_LENGTH,BAR_WIDTH);
}



Bar::~Bar(){

}


void Bar::move(tDirection dir){
	int prev_x,prev_y;

	this->getPos(prev_x,prev_y);


	if(dir == DIR_RIGHT)
	{
		if((prev_x + this->dim_x) < (FRAME_LENGTH - FRAME_THICKNESS - FRAME_BAR_SPACE_X))
		{
			this->setPos(prev_x + bar_step,prev_y);
		}
	}
	else if(dir == DIR_LEFT)
	{
		if(prev_x > (FRAME_THICKNESS + FRAME_BAR_SPACE_X))
		{
			this->setPos(prev_x - bar_step,prev_y);
		}
	}
}
