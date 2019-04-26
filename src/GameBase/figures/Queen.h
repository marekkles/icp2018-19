#ifndef __QUEEN_H

#define __QUEEN_H

#include "../Enums.h"
#include "../FigureBase.h"
#include "../Move.h"

class Queen : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move);
    virtual void LoadValidMoves();
	virtual ~Queen() = default;
};

#endif