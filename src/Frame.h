///////////////////////////////////////////////////////////
//  Frame.h
//  Implementation of the Class Frame
//  Created on:      16-�����-2019 12:42:02 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_F028B284_3A13_4b87_AEE6_4A55219ACDBF__INCLUDED_)
#define EA_F028B284_3A13_4b87_AEE6_4A55219ACDBF__INCLUDED_

#include "Object.h"
#include "FrameSide.h"

#define FRAME_LENGTH		640u
#define FRAME_WIDTH			480u
#define FRAME_THICKNESS		5u
#define FRAME_BAR_SPACE_X	10u
#define FRAME_BAR_SPACE_Y	5u
#define FRAME_BRICK_SPACE_X	10u
#define FRAME_BRICK_SPACE_Y	5u

class Frame : public Object
{

public:
	Frame();
	virtual ~Frame();
	void getFrameSidesDim(int x1[], int x2[], int y1[], int y2[]);
	void getFrameSize(int& x, int& y);
	void render(SDL_Renderer* renderer);

private:
	const int dim_x;
	const int dim_y;
	FrameSide m_FrameSide[4];

};
#endif // !defined(EA_F028B284_3A13_4b87_AEE6_4A55219ACDBF__INCLUDED_)
