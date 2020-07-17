///////////////////////////////////////////////////////////
//  Brick.h
//  Implementation of the Class Brick
//  Created on:      16-�����-2019 12:42:01 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_88F2DDCC_91EB_4697_9FA5_6537E60DD597__INCLUDED_)
#define EA_88F2DDCC_91EB_4697_9FA5_6537E60DD597__INCLUDED_

#include "Barrier.h"
#include "tColor.h"
#include <map>
using namespace std;

class Brick : public Barrier
{

public:
	Brick();
	virtual ~Brick();
	void setColorScoring(tColor color);
	tColor getColorScoring();

private:
    static map<int,int> ColorScoring;
	tColor colorScore;

};
#endif // !defined(EA_88F2DDCC_91EB_4697_9FA5_6537E60DD597__INCLUDED_)
