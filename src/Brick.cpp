///////////////////////////////////////////////////////////
//  Brick.cpp
//  Implementation of the Class Brick
//  Created on:      14-�����-2019 03:41:55 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Brick.h"
#include "tBarrier.h"
#include "tColor.h"

Brick::Brick(){
	this->setBarrierType(BRICK);
}



Brick::~Brick(){

}


void Brick::setColorScoring(tColor color)
{
	this->colorScore = color;
}
tColor Brick::getColorScoring()
{
	return this->colorScore;
}
