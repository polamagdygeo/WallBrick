///////////////////////////////////////////////////////////
//  Ball.h
//  Implementation of the Class Ball
//  Created on:      16-�����-2019 12:42:00 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_B19AE01B_BF76_4685_98A4_5D9FA38BC233__INCLUDED_)
#define EA_B19AE01B_BF76_4685_98A4_5D9FA38BC233__INCLUDED_

#include "Object.h"
#include "Circle.h"
#include "View.h"

class Ball :public Circle,public Object
{

public:
	Ball(View* v);
	virtual ~Ball();
	void _throw();
	int getAngle();
	bool isBallInRange(int x1,int x2,int y1,int y2,int& col_pt_x,int& col_pt_y);
	void setAngle(int angle);
	void updatePos();
	void render(SDL_Renderer* renderer);
	bool isThrown();

private:
	int angle;
	bool isThrown;
	View* pParentView;

};
#endif // !defined(EA_B19AE01B_BF76_4685_98A4_5D9FA38BC233__INCLUDED_)
