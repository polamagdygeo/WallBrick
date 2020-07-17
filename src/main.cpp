//============================================================================
// Name        : BreakBricks.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Controller.h"

using namespace std;


int main( int argc, char* args[] )
{
	Controller c;

	while(1)
	{
		c.update();
	}

    return 0;
}

