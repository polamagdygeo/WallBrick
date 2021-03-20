///////////////////////////////////////////////////////////
//  View.cpp
//  Implementation of the Class View
//  Created on:      14-�����-2019 03:41:56 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "View.h"
#include "Ball.h"
#include "math.h"

#define NO_OF_BRICKS_ROWS			10u
#define BRICK_MIN_LENGTH			60u
#define BRICK_MAX_LENGTH			120u


View::View(SDL_Renderer* r,int x,int y){
	gRenderer = r;
	this->generatedBricksNo = 0;
	GAME_SCREEN_WIDTH = x;
	GAME_SCREEN_HEIGHT = y;
}



View::~View(){
	int i = 0;

	while(i < this->generatedBricksNo)
	{
		delete this->m_Brick[i];
		i++;
	}
}


void View::updateObjList(void)
{
	ObjVector.push_back(&this->m_Ball);
	ObjVector.push_back(&this->m_Bar);
	for(uint8_t i = 0 ; i < this->generatedBricksNo; i++)
	{
		ObjVector.push_back(this->m_Brick[i]);
	}
	ObjVector.push_back(&this->m_Frame);
}



bool View::checkBallCollision(tCollisionInfo& info){
	bool ret = false;
	int hit_range[4];

	int i = this->generatedBricksNo;

	/*Check ball-brick collision*/
	while(i > 0)
	{
		i--;

		if(this->m_Brick[i]->checkIsHidden() == false)
		{
			this->m_Brick[i]->getDimRange(hit_range[0],hit_range[1],
					hit_range[2],hit_range[3]);

			if(this->m_Ball.isBallInRange(hit_range[0],hit_range[1],
					hit_range[2],hit_range[3],info.barrier_col_pt_x,info.barrier_col_pt_y) == true)
			{
				this->m_Brick[i]->hide();
				ret = true;
				info.barrierType=this->m_Brick[i]->getBarrierType();
				info.brickColor=this->m_Brick[i]->getColorScoring();
				info.barrier_col_pt_x -= hit_range[0]; /*x1*/
				info.barrier_col_pt_y -= hit_range[3]; /*y2*/
				this->m_Brick[i]->getDim(info.barrier_dim_x,info.barrier_dim_y);
				break;
			}

		}
	}

	/*Check ball-bar collision*/
	if(ret == false)
	{
		this->m_Bar.getDimRange(hit_range[0],hit_range[1],
				hit_range[2],hit_range[3]);

		if(this->m_Ball.isBallInRange(hit_range[0],hit_range[1],
				hit_range[2],hit_range[3],info.barrier_col_pt_x,info.barrier_col_pt_y) == true)
		{
			ret = true;
			info.barrierType=this->m_Bar.getBarrierType();
			info.barrier_col_pt_x -= hit_range[0]; /*x1*/
			info.barrier_col_pt_y -= hit_range[2]; /*y2*/
			this->m_Bar.getDim(info.barrier_dim_x,info.barrier_dim_y);
			info.col_pt_to_dim_ratio = (float)info.barrier_col_pt_x / info.barrier_dim_x;
		}
	}

	/*Check ball-frame sides collision*/
	if(ret == false)
	{
		int x1[4],x2[4],y1[4],y2[4];
		this->m_Frame.getFrameSidesDim(x1,x2,y1,y2);

		for(int i= SIDE_UP - 1;i < SIDE_RIGHT;i++)
		{
			if(this->m_Ball.isBallInRange(x1[i],x2[i],y1[i],y2[i],info.barrier_col_pt_x,info.barrier_col_pt_y) == true)
			{
				ret = true;
				info.barrierType = (tBarrier)(i + 1);
				break;
			}
		}
	}

	return ret;
}


void View::generateBricks(){
	int pos_x,pos_y;
	int dim_x,dim_y = BRICK_WIDTH;
	int current_draw_location_x = FRAME_THICKNESS + FRAME_BRICK_SPACE_X;
	int current_draw_location_y = FRAME_BRICK_SPACE_Y + FRAME_THICKNESS;
	int row_no = 0;
	int i = 0;

	while(row_no < NO_OF_BRICKS_ROWS && 
		(i <MAX_BRICKS_NO))
	{
		this->m_Brick[i] = new Brick;
		/*dim_x = random value within range*/
		dim_x = (rand() % (BRICK_MAX_LENGTH - BRICK_MIN_LENGTH)) + BRICK_MIN_LENGTH;
		pos_x = current_draw_location_x;
		pos_y = current_draw_location_y;

		int frame_x,frame_y;
		this->m_Frame.getFrameSize(frame_x,frame_y);

		if((current_draw_location_x + dim_x) >= (frame_x - FRAME_BRICK_SPACE_X - 20))
		{
			dim_x -=  (current_draw_location_x + dim_x) - (frame_x + FRAME_BRICK_SPACE_X + FRAME_THICKNESS);
			current_draw_location_x = FRAME_THICKNESS + FRAME_BRICK_SPACE_X;
			current_draw_location_y += dim_y;
			row_no++;
		}
		else
		{
			current_draw_location_x += dim_x;
		}

		this->m_Brick[i]->setPos(pos_x,pos_y);
		this->m_Brick[i]->setDim(dim_x,dim_y);

		this->generatedBricksNo++;
		i++;

		/*Coloring randomize*/
//		this->m_Brick[i]->setColorScoring((tColor)(rand() % (2-0)));
	}
}

void View::clear()
{
    SDL_SetRenderDrawColor(gRenderer,0,0,0,0);
    SDL_RenderClear(gRenderer);
}


void View::render(){
	this->clear();
	vector<class Object*>::iterator itr = this->ObjVector.begin();
	while(itr != this->ObjVector.end())
	{
		(*itr)->render(gRenderer);
		itr++;
	}
    //Update screen
    SDL_RenderPresent( gRenderer );
}

void View::moveBallWithBar()
{
	int Bar_Pos_x,Bar_Pos_y;
	int Bar_Dim_x,Bar_Dim_y;

	int Ball_Rad;

	this->m_Bar.getPos(Bar_Pos_x,Bar_Pos_y);
	this->m_Bar.getDim(Bar_Dim_x,Bar_Dim_y);

	Ball_Rad = this->m_Ball.getRad();

	this->m_Ball.setPos(Bar_Pos_x + (Bar_Dim_x / 2), Bar_Pos_y - Ball_Rad);
}
