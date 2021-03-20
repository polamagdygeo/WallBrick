///////////////////////////////////////////////////////////
//  Session.cpp
//  Implementation of the Class Session
//  Created on:      16-�����-2019 12:42:03 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Session.h"


Session::Session(SDL_Renderer* r,int x,int y){
	this->score = 0;
	this->m_View = new View(r,x,y);
	this->m_View->generateBricks();
	this->m_View->updateObjList();
}



Session::~Session(){
	delete this->m_View;
}


int Session::getScore(){
	return this->score;
}


void Session::setScore(int s){
	this->score = s;
}
