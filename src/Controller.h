///////////////////////////////////////////////////////////
//  Controller.h
//  Implementation of the Class Controller
//  Created on:      16-�����-2019 12:42:02 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_72F771C6_8CCB_4e7d_A3C3_44D1A9E3A511__INCLUDED_)
#define EA_72F771C6_8CCB_4e7d_A3C3_44D1A9E3A511__INCLUDED_

#include "Session.h"
#include <SDL2/SDL.h>

class Controller
{

public:
	Controller();
	virtual ~Controller();
	void update();
	void newSession();
	SDL_Renderer* getRenderer();

private:
	unsigned char tick;
	const int update_tick;
	Session* m_ptr_Session;
	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	const int SCREEN_BPP = 32;
	//The window renderer
	SDL_Renderer* gRenderer = NULL;

};
#endif // !defined(EA_72F771C6_8CCB_4e7d_A3C3_44D1A9E3A511__INCLUDED_)
