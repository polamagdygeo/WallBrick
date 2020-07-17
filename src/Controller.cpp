///////////////////////////////////////////////////////////
//  Controller.cpp
//  Implementation of the Class Controller
//  Created on:      14-�����-2019 03:41:55 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#include "Controller.h"
#include "tBarrier.h"
#include "GameConfig.h"


Controller::Controller():update_tick(40){
	this->tick = 0;

    //Create window
    gWindow = SDL_CreateWindow( "Break Bricks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create renderer for window
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED );
        if( gRenderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Clear screen
            SDL_RenderClear( gRenderer );
            printf( "Renderer created");

        }

    	this->m_ptr_Session = new Session(gRenderer);
    }
}



Controller::~Controller(){

}


void Controller::update(){
	SDL_Event event;

	this->tick = SDL_GetTicks();

    while( SDL_PollEvent( &event ) != 0 )
    {
        //User presses a key
        if( event.type == SDL_KEYDOWN )
        {
            //Select surfaces based on key press
            switch( event.key.keysym.sym )
            {
                case SDLK_LEFT:
                	this->m_ptr_Session->m_View->m_Bar.move(DIR_LEFT);
                	if(this->m_ptr_Session->m_View->m_Ball.is_Thrown() == false)
                	{
                		this->m_ptr_Session->m_View->moveBallWithBar();
                	}
                break;

                case SDLK_RIGHT:
                	this->m_ptr_Session->m_View->m_Bar.move(DIR_RIGHT);
                	if(this->m_ptr_Session->m_View->m_Ball.is_Thrown() == false)
                	{
                		this->m_ptr_Session->m_View->moveBallWithBar();
                	}
                break;

                case SDLK_SPACE:
                	this->m_ptr_Session->m_View->m_Ball._throw();
                break;
                case SDLK_ESCAPE:
    				this->newSession();
				break;

            }
        }
    }

	if(this->tick % update_tick == 0)
	{
		tCollisionInfo collisionInfo;

		int curr_angle = this->m_ptr_Session->m_View->m_Ball.getAngle();

		if(this->m_ptr_Session->m_View->checkBallCollision(collisionInfo) == true)
		{
			if(collisionInfo.barrierType == SIDE_BOTTOM)
			{
				/*Game Over*/
				this->newSession();
			}
			else if(collisionInfo.barrierType == SIDE_UP || collisionInfo.barrierType == BRICK)
			{
				if(curr_angle == 270)
				{
					curr_angle = 90;
				}
				/*Up left*/
				else if(curr_angle < 270)
				{
					curr_angle -= 180 - 2*(270-curr_angle);
				}
				/*Up right*/
				else if(curr_angle < 360)
				{
					curr_angle -= 180 + (180 - 2*(curr_angle-270));
				}

				int prev_score = this->m_ptr_Session->getScore();
				this->m_ptr_Session->setScore(prev_score + collisionInfo.brickColor);
			}
			else if(collisionInfo.barrierType == BAR)
			{
				if(curr_angle == 90)
				{
					if(collisionInfo.col_pt_to_dim_ratio > 0.5)
					{
						curr_angle += 180 + (90 - (90 * collisionInfo.col_pt_to_dim_ratio));
					}
					else if(collisionInfo.col_pt_to_dim_ratio < 0.5)
					{
						curr_angle += 90 + (90 * collisionInfo.col_pt_to_dim_ratio);
					}
				}
				/*Down right*/
				else if(curr_angle < 90)
				{
					curr_angle += 180 + 180 - 2*curr_angle;
				}
				/*Down left*/
				else if(curr_angle <= 180)
				{
					curr_angle += 180 - 2*(curr_angle - 90);
				}
			}
			else if(collisionInfo.barrierType == SIDE_RIGHT)
			{
				/*Down right*/
				if(curr_angle < 90)
				{
					curr_angle += 180 - 2*curr_angle;
				}
				/*Up right*/
				else if(curr_angle < 360)
				{
					curr_angle -= 180 - 2*(360-curr_angle);
				}
			}
			else if(collisionInfo.barrierType == SIDE_LEFT)
			{
				/*Down left*/
				if(curr_angle < 180)
				{
					curr_angle -= 180 - 2*(180-curr_angle);
				}
				/*Up left*/
				else if(curr_angle < 270)
				{
					curr_angle += 180 - 2*(curr_angle-180);
				}
			}

			this->m_ptr_Session->m_View->m_Ball.setAngle(curr_angle);
		}

		this->m_ptr_Session->m_View->m_Ball.updatePos();

		this->m_ptr_Session->m_View->render();
	}
}


void Controller::newSession()
{
	delete this->m_ptr_Session;

	this->m_ptr_Session = new Session(gRenderer);
}
