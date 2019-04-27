#ifndef __PAWN_H

#define __PAWN_H

#include "../Enums.h"
#include "../FigureBase.h"
#include "../Move.h"

class Pawn : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move);
    virtual void LoadValidMoves(bool writeOver);
	virtual ~Pawn() = default;
};

#endif