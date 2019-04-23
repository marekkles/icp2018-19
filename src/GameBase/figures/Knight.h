#ifndef __KNIGHT_H

#define __KNIGHT_H
#include "../FigureBase.h"

#include "../FigureBase.h"
#include "../Move.h"

class Knight : public FigureBase
{
public:
    Knight(FigureColor_t color, Position * position);
    virtual bool VerifyMove(Move * move); 
	virtual ~Knight() = default;
};

#endif