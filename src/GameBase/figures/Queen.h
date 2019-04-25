#ifndef __QUEEN_H

#define __QUEEN_H
#include "../FigureBase.h"

#include "../FigureBase.h"
#include "../Move.h"

class Queen : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move); 
	virtual ~Queen() = default;
};

#endif