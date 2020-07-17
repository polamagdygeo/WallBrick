///////////////////////////////////////////////////////////
//  Session.h
//  Implementation of the Class Session
//  Created on:      16-�����-2019 12:42:03 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_C561E91A_8ABA_478c_A49F_2BDA59426269__INCLUDED_)
#define EA_C561E91A_8ABA_478c_A49F_2BDA59426269__INCLUDED_

#include "View.h"

class Session
{

public:
	Session(SDL_Renderer* r,int x,int y);
	virtual ~Session();

	int getScore();
	void setScore(int);
	View* m_View;

private:
	int score;

};
#endif // !defined(EA_C561E91A_8ABA_478c_A49F_2BDA59426269__INCLUDED_)
