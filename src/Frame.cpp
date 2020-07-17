///////////////////////////////////////////////////////////
//  Frame.cpp
//  Implementation of the Class Frame
//  Created on:      14-�����-2019 03:41:56 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Frame.h"
#include "tBarrier.h"


Frame::Frame():dim_x(640),dim_y(480){
	this->m_FrameSide[SIDE_UP-1].setBarrierType(SIDE_UP);
	this->m_FrameSide[SIDE_UP-1].setPos(0,0);
	this->m_FrameSide[SIDE_UP-1].setDim(640,5);

	this->m_FrameSide[SIDE_BOTTOM-1].setBarrierType(SIDE_BOTTOM);
	this->m_FrameSide[SIDE_BOTTOM-1].setPos(0,480-5);
	this->m_FrameSide[SIDE_BOTTOM-1].setDim(640,5);

	this->m_FrameSide[SIDE_LEFT-1].setBarrierType(SIDE_LEFT);
	this->m_FrameSide[SIDE_LEFT-1].setPos(0,0);
	this->m_FrameSide[SIDE_LEFT-1].setDim(5,480);

	this->m_FrameSide[SIDE_RIGHT-1].setBarrierType(SIDE_RIGHT);
	this->m_FrameSide[SIDE_RIGHT-1].setPos(640-5,0);
	this->m_FrameSide[SIDE_RIGHT-1].setDim(5,480);
}



Frame::~Frame(){

}





void Frame::render(SDL_Renderer* renderer){
	for(uint8_t i = 0;i < 4;i++)
	{
		this->m_FrameSide[i].render(renderer);
	}
}

void Frame::getFrameSidesDim(int x1[],int x2[],int y1[],int y2[])
{
	for(int i = 0; i<4 ;i++)
	{
		this->m_FrameSide[i].getDimRange(x1[i],x2[i],y1[i],y2[i]);
	}
}

void Frame::getFrameSize(int& x,int& y)
{
	x=this->dim_x;
	y=this->dim_y;
}
