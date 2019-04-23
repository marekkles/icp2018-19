#ifndef __KING_H

#define __KING_H

#include "../FigureBase.h"
#include "../Move.h"

class King : public FigureBase
{
public:
    King(FigureColor_t color, Position * position);
    virtual bool VerifyMove(Move * move); 
	virtual ~King() = default;
};

#endif