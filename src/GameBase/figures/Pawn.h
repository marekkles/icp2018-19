#ifndef __PAWN_H

#define __PAWN_H
#include "../FigureBase.h"

#include "../FigureBase.h"
#include "../Move.h"

class Pawn : public FigureBase
{
public:
    Pawn(FigureColor_t color, Position * position);
    virtual bool VerifyMove(Move * move); 
	virtual ~Pawn() = default;
};

#endif