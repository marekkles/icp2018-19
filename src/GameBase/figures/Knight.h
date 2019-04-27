#ifndef __KNIGHT_H

#define __KNIGHT_H

#include "../Enums.h"
#include "../FigureBase.h"
#include "../Move.h"

class Knight : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move);
    virtual void LoadValidMoves(bool writeOver);
	virtual ~Knight() = default;
};

#endif