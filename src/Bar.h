///////////////////////////////////////////////////////////
//  Bar.h
//  Implementation of the Class Bar
//  Created on:      16-�����-2019 12:42:01 �
//  Original author: Pola
///////////////////////////////////////////////////////////

#if !defined(EA_2CE7FBAE_8D16_44c4_A223_87C23FFE6AA0__INCLUDED_)
#define EA_2CE7FBAE_8D16_44c4_A223_87C23FFE6AA0__INCLUDED_

#include "tDirection.h"
#include "Barrier.h"

#define BAR_LENGTH				150u
#define BAR_WIDTH				15u
#define BAR_STEP				20u

class Bar : public Barrier
{
public:
	Bar(View* v);
	virtual ~Bar();
	void move(tDirection dir);

private:
	static const int bar_step = BAR_STEP;
	View* pParentView;

};
#endif // !defined(EA_2CE7FBAE_8D16_44c4_A223_87C23FFE6AA0__INCLUDED_)
