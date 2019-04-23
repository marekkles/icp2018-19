#ifndef __QUEEN_H

#define __QUEEN_H
#include "../FigureBase.h"

#include "../FigureBase.h"
#include "../Move.h"

class Queen : public FigureBase
{
public:
    Queen(FigureColor_t color, Position * position);
    virtual bool VerifyMove(Move * move); 
	virtual ~Queen() = default;
};

#endif