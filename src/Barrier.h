///////////////////////////////////////////////////////////
//  Barrier.h
//  Implementation of the Class Barrier
//  Created on:      16-�����-2019 12:42:01 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_8C5E4714_94AC_43b8_8259_FA8A63BCC875__INCLUDED_)
#define EA_8C5E4714_94AC_43b8_8259_FA8A63BCC875__INCLUDED_

#include "Object.h"
#include "Barrier.h"
#include "tBarrier.h"
#include <SDL2/SDL.h>

class Barrier : public Object
{

public:
	Barrier();
	virtual ~Barrier();
	void getDim(int& x, int& y);
	void getDimRange(int& x1, int& x2, int& y1, int& y2);
	void getPos(int& x, int& y);
	void render(SDL_Renderer* renderer);
	void setDim(int x, int y);
	void setPos(int x, int y);
	void setBarrierType(tBarrier);
	tBarrier getBarrierType();
	bool checkIsHidden();
	void hide();

protected:
	Uint16 dim_x;
	Uint16 dim_y;
	Sint16 pos_x;
	Sint16 pos_y;
	tBarrier barrier_type;
	bool isHidden;

};
#endif // !defined(EA_8C5E4714_94AC_43b8_8259_FA8A63BCC875__INCLUDED_)
