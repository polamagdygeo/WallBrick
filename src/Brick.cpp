///////////////////////////////////////////////////////////
//  Brick.cpp
//  Implementation of the Class Brick
//  Created on:      14-�����-2019 03:41:55 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Brick.h"
#include "tBarrier.h"
#include "tColor.h"

map<int,int> Brick::ColorScoring;

Brick::Brick(){
	this->setBarrierType(BRICK);

	Brick::ColorScoring[COLOR_RED] = 10;
	Brick::ColorScoring[COLOR_GREED] = 20;
	Brick::ColorScoring[COLOR_BLUE] = 30;

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
