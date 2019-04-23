#ifndef __ROOK_H

#define __ROOK_H
#include "../FigureBase.h"

#include "../FigureBase.h"
#include "../Move.h"

class Rook : public FigureBase
{
public:
    Rook(FigureColor_t color, Position * position);
    virtual bool VerifyMove(Move * move); 
	virtual ~Rook() = default;
};

#endif