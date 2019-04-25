#ifndef __PAWN_H

#define __PAWN_H
#include "../FigureBase.h"

#include "../FigureBase.h"
#include "../Move.h"

class Pawn : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move); 
	virtual ~Pawn() = default;
};

#endif