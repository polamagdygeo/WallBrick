///////////////////////////////////////////////////////////
//  View.h
//  Implementation of the Class View
//  Created on:      16-�����-2019 12:42:03 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_DE94B283_A355_46ec_8D67_257DA393B003__INCLUDED_)
#define EA_DE94B283_A355_46ec_8D67_257DA393B003__INCLUDED_

#include "Ball.h"
#include "Bar.h"
#include "Frame.h"
#include "Brick.h"
#include "tBarrier.h"
#include <SDL2/SDL.h>
#include <vector>

#define MAX_BRICKS_NO	200

typedef struct
{
	int barrier_dim_x,barrier_dim_y;
	tBarrier barrierType;
	tColor brickColor;
	int barrier_col_pt_x,barrier_col_pt_y;
	float col_pt_to_dim_ratio;
}tCollisionInfo;

class View
{

public:
	Ball m_Ball;
	Bar m_Bar;

	explicit View(SDL_Renderer* r,int x,int y);
	virtual ~View();
	bool checkBallCollision(tCollisionInfo& info);
	void generateBricks();
	void render();
	void showScore(int score);
	void updateObjList(void);
	void clear();
	void moveBallWithBar();
	void getGameAreaDim(int& x,int &y);

private:
	int generatedBricksNo;
	Brick* m_Brick[MAX_BRICKS_NO];
	Frame m_Frame;
	char user_message[50];
	vector<class Object*> ObjVector;
	SDL_Renderer* gRenderer = NULL;
	const int GAME_SCREEN_WIDTH ;
	const int GAME_SCREEN_HEIGHT ;

};
#endif // !defined(EA_DE94B283_A355_46ec_8D67_257DA393B003__INCLUDED_)
